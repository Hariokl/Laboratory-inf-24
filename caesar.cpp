#include <iostream>
#include <fstream>
#include <iomanip>


namespace {
const int kSetWidth = 10;
const int kASCIICharacters = 256;
const int kZero = 0;

void EqualTexts(bool equal) {
    if (equal) {
        std::cout << "Успешно раздекодировали!" << std::endl;
    } else {
        std::cout << "Успешно раздекодировали!." << std::endl;
    }
}

void AskForCharacter() {
    std::cout << "\nКакой сивол декодировать?";
}

void ChoiceToContinue() {
    std::cout << "\nПродолжить программу (y/n)";
}

void InformationMenu() {
    std::cout << '\n' << std::setw(kSetWidth) << "символ" << std::setw(kSetWidth) << "кол-во" << std::setw(kSetWidth);
    std::cout << "вар-ов";
}

void Info(char userChar, int** symbolArray) {
    std::cout << '\n' << std::setw(kSetWidth) << userChar;
    int sourceCount = 0;
    int encodedCount = 0;
    int symbolCount = 0;
    for (int i = 0; i < kASCIICharacters; ++i) {
        symbolCount = symbolArray[static_cast<int>(userChar)][i];
        sourceCount += symbolCount;
        if (symbolCount != kZero) {
            ++encodedCount;
        }
    }
    std::cout << std::setw(kSetWidth) << sourceCount << std::setw(kSetWidth) << encodedCount;
}
}

namespace Caesar {
size_t GetTextSize(char* text) {
    size_t textSize = 0;
    while (text[textSize] != '\0') {
        ++textSize;
    }
    return textSize;
}

bool CompareTexts(char* text1, char* text2) {
    size_t textSize = GetTextSize(text1);
    if (textSize != GetTextSize(text2)) {
        return false;
    }
    for (size_t i = 0; i < textSize; ++i) {
        if (text1[i] != text2[i]) {
            return false;
        }
    }
    return true;
}

int GetTextWordSize(char* text) {
    int textWordSize = 0;
    size_t textI = 0;
    bool lastCharIsAlpha = false;
    while (text[textI] != '\0') {
        if ((text[textI] == ' ') || (text[textI] == '\n') || (text[textI] == '\0')) {
            if (lastCharIsAlpha) {
                ++textWordSize;
                lastCharIsAlpha = false;
            }
        } else {
            lastCharIsAlpha = true;
        }
        ++textI;
    }
    return textWordSize;
}

char* ReadFile(const char* filename) {
    std::ifstream file(filename);

    file.seekg(0, std::ios::end);
    int size = file.tellg();
    file.seekg(0, std::ios::beg);

    char* buffer = new char[size + 1];
    file.read(buffer, size);
    buffer[size] = '\0';

    file.close();
    return buffer;
}

void WriteFile(const char* filename, char* encodedMessage) {
    std::ofstream file(filename);
    size_t messageSize = GetTextSize(encodedMessage);
    file.write(encodedMessage, messageSize);
    file.close();
}

void ShiftArray(int* shiftArray, char* keyMessage, size_t keySize) {
    const int kZero = 0;
    size_t shiftI = 0;
    size_t keyI = 0;
    int shiftSum = 0;
    while (keyI < keySize) {
        if ((keyMessage[keyI] == ' ') || (keyMessage[keyI] == '\n') || (keyMessage[keyI] == '\0')){
            if (shiftSum != kZero) {
                shiftArray[shiftI] = shiftSum % kASCIICharacters;
                shiftSum = 0;
                ++shiftI;
            }
        } else {
            shiftSum += static_cast<int>(keyMessage[keyI]);
        }
        ++keyI;
    }
}

char GetShift(int* shiftArray, char encodeChar, int wordsInKey, size_t encodeI) {
    char encodedChar = static_cast<char>((kASCIICharacters + static_cast<int>(encodeChar) + shiftArray[encodeI % wordsInKey]) % kASCIICharacters);
    return encodedChar;
}

char GetReverseShift(int* shiftArray, char encodedChar, int wordsInKey, size_t encodeI) {
    char sourceChar = static_cast<char>((kASCIICharacters + static_cast<int>(encodedChar) - shiftArray[encodeI % wordsInKey]) % kASCIICharacters);
    return sourceChar;
}

// int* GetInfo(char* source, char* encoded, size_t textSize, int* sourceCounter) {
//     int* symbolCounter{};

//     for (size_t sourceI = 0; sourceI < textSize; ++sourceI) {
//         char curSymbol = sourceCounter[sourceI];
//         int curCounter = 0;
//         char* allEncoded{};
//         for (size_t encodedI = 0; encodedI < textSize; ++encodedI) {
//             if (source[encodedI] == curSymbol) {
//                 bool in = false;
//                 for (size_t i = 0; i < curCounter; ++i) {
//                     if (encoded[encodedI] == allEncoded[i]) {
//                         in = true;
//                         break;
//                     }
//                 }
//                 if (!in) {
//                     allEncoded[curCounter] = encoded[encodedI];
//                     ++curSymbol;
//                 }
//             }
//         }
//     }

//     delete[] symbolCounter;
// }

char* Encode(char* sourceMessage, char* keyMessage, int** symbolArray) {
    size_t sourceSize = GetTextSize(sourceMessage);
    size_t keySize = GetTextSize(keyMessage);
    int wordsInKey = GetTextWordSize(keyMessage);

    char* encodedMessage = new char[sourceSize + 1];
    size_t encodedI = 0;
    int* shiftArray = new int[wordsInKey];
    ShiftArray(shiftArray, keyMessage, keySize);



    while (encodedI < sourceSize) {
        encodedMessage[encodedI] = GetShift(shiftArray, sourceMessage[encodedI], wordsInKey, encodedI);
        ++symbolArray[static_cast<int>(sourceMessage[encodedI])][static_cast<int>(encodedMessage[encodedI])];
        ++encodedI;
    }

    delete[] shiftArray;
    encodedMessage[sourceSize] = '\0';
    return encodedMessage;
}

char* Decode(char* encodedMessage, char* keyMessage) {
    size_t encodedSize = GetTextSize(encodedMessage);
    size_t keySize = GetTextSize(keyMessage);
    int wordsInKey = GetTextWordSize(keyMessage);

    char* sourceMessage = new char[encodedSize + 1];
    size_t sourceI = 0;
    int* shiftArray = new int[wordsInKey];
    ShiftArray(shiftArray, keyMessage, keySize);

    while (sourceI < encodedSize) {
        sourceMessage[sourceI] = GetReverseShift(shiftArray, encodedMessage[sourceI], wordsInKey, sourceI);
        ++sourceI;
    }

    sourceMessage[encodedSize] = '\0';
    delete[] shiftArray;
    return sourceMessage;
}

void StartUp(char** input) {
    char* sourceFile = input[1];
    char* keyFile = input[2];
    char* sourceMessage = ReadFile(sourceFile);
    char* keyMessage = ReadFile(keyFile);

    int** symbolArray = new int*[kASCIICharacters];
    for (int i = 0; i < kASCIICharacters; ++i) {
        symbolArray[i] = new int[kASCIICharacters];
    }
    char* encodedMessage = Encode(sourceMessage, keyMessage, symbolArray);
    WriteFile("encoded.txt", encodedMessage);
    char* decodedMessage = Decode(encodedMessage, keyMessage);
    WriteFile("decoded.txt", decodedMessage);
    EqualTexts(CompareTexts(sourceMessage, decodedMessage));

    char userChoice{};
    char continueProgram = 'y';
    while (continueProgram == 'y') {
        AskForCharacter();
        std::cin >> userChoice;
        InformationMenu();
        Info(userChoice, symbolArray);
        ChoiceToContinue();
        std::cin >> continueProgram;
    }

    for (int i = 0; i < kASCIICharacters; ++i) {
        delete[] symbolArray[i];
    }
    delete[] symbolArray;
}
}
