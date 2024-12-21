#include <iostream>
#include <fstream>


namespace {
const int kASCIICharacters = 256;

void EqualTexts(bool equal) {
    if (equal) {
        std::cout << "Тексты одинаковы" << std::endl;
    } else {
        std::cout << "Тексты разные" << std::endl;
    }
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

// void GetWordsFromText(char* text, size_t textSize) {
//     bool lastCharIsAlpha = false;
//     size_t wordsI = 0;
//     char** words;
//     char* word = new char[100];
//     size_t wordI = 0;
//     for (size_t textI = 0; textI < textSize; ++textI){
//         if ((text[textI] == ' ') || (text[textI] == '\n') || (text[textI] == '\0')) {
//             if (lastCharIsAlpha) {
//                 word[wordI] = '\0';
//                 words[wordI] = word;
//                 std::cout << word;
//                 ++wordsI;
//             }
//             wordI = 0;
//             lastCharIsAlpha = false;
//         } else {
//             word[wordI] = text[textI];
//             ++wordI;
//             lastCharIsAlpha = true;
//         }
//     }
// }

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

char GetShift(int* shiftArray, char encodeChar, char* keyMessage, size_t encodeI) {
    int wordsInKey = GetTextWordSize(keyMessage);
    char encodedChar = static_cast<char>((kASCIICharacters + static_cast<int>(encodeChar) + shiftArray[encodeI % wordsInKey]) % kASCIICharacters);
    return encodedChar;
}

char GetReverseShift(int* shiftArray, char encodedChar, char* keyMessage, size_t encodeI) {
    int wordsInKey = GetTextWordSize(keyMessage);
    char sourceChar = static_cast<char>((kASCIICharacters + static_cast<int>(encodedChar) - shiftArray[encodeI % wordsInKey]) % kASCIICharacters);
    return sourceChar;
}

char* Encode(char* sourceMessage, char* keyMessage) {
    size_t sourceSize = GetTextSize(sourceMessage);
    size_t keySize = GetTextSize(keyMessage);
    int wordsInKey = GetTextWordSize(keyMessage);

    char* encodedMessage = new char[sourceSize + 1];
    size_t encodedI = 0;
    int* shiftArray = new int[wordsInKey];
    ShiftArray(shiftArray, keyMessage, keySize);
    for (int i = 0; i < wordsInKey; ++i) {
        std::cout << shiftArray[i] << ' ';
    }

    while (encodedI < sourceSize) {
        encodedMessage[encodedI] = GetShift(shiftArray, sourceMessage[encodedI], keyMessage, encodedI);
        ++encodedI;
    }

    encodedMessage[sourceSize] = '\0';
    delete[] shiftArray;
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
        sourceMessage[sourceI] = GetReverseShift(shiftArray, encodedMessage[sourceI], keyMessage, sourceI);
        ++sourceI;
    }

    sourceMessage[encodedSize] = '\0';
    delete[] shiftArray;
    return sourceMessage;
}

void StartUp() {
    char* sourceMessage = ReadFile("source.txt");
    char* keyMessage = ReadFile("key.txt");
    // GetWordsFromText(keyMessage, GetTextSize(keyMessage));
    char* encodedMessage = Encode(sourceMessage, keyMessage);
    WriteFile("encoded.txt", encodedMessage);
    char* decodedMessage = Decode(encodedMessage, keyMessage);
    WriteFile("decoded.txt", decodedMessage);
    EqualTexts(CompareTexts(sourceMessage, decodedMessage));
}
}
