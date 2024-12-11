#pragma once

namespace Decrypter {
struct Results {
    int closeKey;
    int valueEulerFunction;
};

[[nodiscard]] int DecryptMessage(int encryptedMessage, int closeKey, int N);

[[nodiscard]] int EncryptMessage(int message, int openKey, int N);

[[nodiscard]] Results FindCloseKey(const int encryptedMessage, const int openKey, const int N);

void StartUp();
}  // namespace Decrypter
