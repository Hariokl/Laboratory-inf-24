#pragma once
#include <iomanip>

namespace Caesar {
size_t GetTextSize(char* text);
int GetTextWordSize(char* text);
char* ReadFile(const char* filename);
void WriteFile(const char* filename, char* encodedMessage);
char ShiftChar(char character);
char ReverseShiftChar(char character);
char* Encode(char* sourceMessage);
char* Decode(char* encodedMessage);
void StartUp(char** input);
}  // namespace Caesar
