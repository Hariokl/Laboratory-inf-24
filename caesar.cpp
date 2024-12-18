#include <iostream>
#include <fstream>
#include "caesar.hpp"


namespace {
    const int kMaxAlphabetCharacters = 26;
    // const int kASCIICharacters = 128;
    const int kShift = 13;
    const int kASCIIStart = static_cast<int>('a');
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
    std::ofstream stream;
    stream.open(filename);
    stream << encodedMessage << std::endl;
    stream.close();
}

char ShiftChar(char character) {
    return static_cast<char>(kASCIIStart + (static_cast<int>(character) + kShift - kASCIIStart) % kMaxAlphabetCharacters);
}

char ReverseShiftChar(char character) {
    return static_cast<char>(kASCIIStart + (static_cast<int>(character) - kShift - kASCIIStart + kMaxAlphabetCharacters) % kMaxAlphabetCharacters);
}

char* Encode(char* sourceMessage) {
    size_t sourceSize = GetTextSize(sourceMessage);
    char* encodedMessage = new char[sourceSize];

    for (size_t i = 0; i < sourceSize; ++i) {
        if (isalpha(sourceMessage[i])){  //
            char lowerChar = tolower(sourceMessage[i]);
            encodedMessage[i] = islower(sourceMessage[i]) ? ShiftChar(lowerChar) : toupper(ShiftChar(lowerChar));
        } else {
            encodedMessage[i] = sourceMessage[i];
        }
    }

    return encodedMessage;
}

char* Decode(char* encodedMessage) {
    size_t encodedSize = GetTextSize(encodedMessage);
    char* sourceMessage = new char[encodedSize + 1];

    for (size_t i = 0; i < encodedSize; ++i) {
        if (isalpha(encodedMessage[i])){  //
            char lowerChar = tolower(encodedMessage[i]);
            sourceMessage[i] = islower(encodedMessage[i]) ? ReverseShiftChar(lowerChar) : toupper(ReverseShiftChar(lowerChar));
        } else {
            sourceMessage[i] = encodedMessage[i];
        }
    }

    return sourceMessage;
}

void StartUp() {
    char* sourceMessage = ReadFile("source.txt");
    // char* keyMessage = ReadFile("key.txt");
    char* encodedMessage = Encode(sourceMessage);
    WriteFile("encoded.txt", encodedMessage);
    char* decodedMessage = Decode(encodedMessage);
    WriteFile("decoded.txt", decodedMessage);
}
}
