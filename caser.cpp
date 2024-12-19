#include <iostream>
#include <fstream>


namespace {
    const int kMaxAlphabetCharacters = 26;
    const int kASCIICharacters = 128;
}

namespace Caesar {
size_t GetTextSize(char* text) {
    size_t textSize = 0;
    while (text[textSize] != '\0') {
        ++textSize;
    }
    return textSize;
}

int GetTextWordSize(char* text) {
    int textWordSize = 0;
    size_t textI = 0;
    bool lastCharIsAlpha = false;
    while (text[textI] != '\0') {
        if ((text[textI] == ' ') || (text[textI] == '\n') || (text[textI] == '\0')) {
            if (lastCharIsAlpha) {
                ++textWordSize;
            }
            lastCharIsAlpha = false;
        }
        ++textI;
        lastCharIsAlpha = true;
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
    size_t shiftI = 0;
    size_t keyI = 0;
    int shiftSum = 0;
    bool lastCharIsAlpha = false;
    while (keyI < keySize) {
        if ((keyMessage[keyI] == ' ') && (keyMessage[keyI] == '\n') && (keyMessage[keyI] == '\0')){
            if (lastCharIsAlpha) {
                shiftArray[shiftI] = shiftSum % kASCIICharacters;
                shiftSum = 0;
                ++shiftI;
            }
            lastCharIsAlpha = false;
        }
        if (isalpha(keyMessage[keyI])) {
            shiftSum += static_cast<int>(keyMessage[keyI]);
        }
        ++keyI;
        lastCharIsAlpha = true;
    }
}

char GetShift(char encodeChar, char* keyMessage, size_t keySize, size_t encodeI) {
    if ((encodeChar == ' ') || (encodeChar == '\n')) {
        return ' ';
    }
    int wordsInKey = GetTextWordSize(keyMessage);

    int* shiftArray = new int[wordsInKey];
    ShiftArray(shiftArray, keyMessage, keySize);
    char encodedChar = static_cast<char>((static_cast<int>(encodeChar) + shiftArray[encodeI % wordsInKey]) % kASCIICharacters);

    delete[] shiftArray;
    return encodedChar;
}

char GetReverseShift(char encodedChar, char* keyMessage, size_t keySize, size_t encodeI) {
    if ((encodedChar == ' ') || (encodedChar == '\n')) {
        return ' ';
    }
    int wordsInKey = GetTextWordSize(keyMessage);

    int* shiftArray = new int[wordsInKey];
    ShiftArray(shiftArray, keyMessage, keySize);
    char sourceChar = static_cast<char>((static_cast<int>(encodedChar) - shiftArray[encodeI % wordsInKey] + kASCIICharacters) % kASCIICharacters);

    delete[] shiftArray;
    return sourceChar;
}

char* Encode(char* sourceMessage, char* keyMessage) {
    size_t sourceSize = GetTextSize(sourceMessage);
    size_t keySize = GetTextSize(keyMessage);
    char* encodedMessage = new char[sourceSize + 1];
    size_t encodedI = 0;

    while (sourceMessage[encodedI] != '\0') {
        encodedMessage[encodedI] = GetShift(sourceMessage[encodedI], keyMessage, keySize, encodedI);
        ++encodedI;
    }

    encodedMessage[sourceSize] = '\0';
    return encodedMessage;
}

char* Decode(char* encodedMessage, char* keyMessage) {
    size_t encodedSize = GetTextSize(encodedMessage);
    size_t keySize = GetTextSize(keyMessage);
    char* sourceMessage = new char[encodedSize + 1];
    size_t sourceI = 0;

    while (encodedMessage[sourceI] != '\0') {
        sourceMessage[sourceI] = GetShift(encodedMessage[sourceI], keyMessage, keySize, sourceI);
        ++sourceI;
    }

    sourceMessage[encodedSize] = '\0';
    return sourceMessage;
}

void StartUp() {
    char* sourceMessage = ReadFile("source.txt");
    char* keyMessage = ReadFile("key.txt");
    char* encodedMessage = Encode(sourceMessage, keyMessage);
    WriteFile("encoded.txt", encodedMessage);
    char* decodedMessage = Decode(encodedMessage, keyMessage);
    WriteFile("decoded.txt", decodedMessage);
}
}
