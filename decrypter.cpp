#include "decrypter.h"

#include <cmath>
#include <iomanip>
#include <iostream>

namespace {
const size_t kMaxPrimeNumbers = 100;

[[nodiscard]] int FindEulerFunctionResult(int p, int q) {
    return (p - 1) * (q - 1);
}

[[nodiscard]] int FindPrimeNumberN(int n, int kStartCycle) {
    const int maxI = n / 2 + 1;
    int* primeNumberArray = new int[kMaxPrimeNumbers];
    size_t sizeOfPNA = 0;
    for (int i = kStartCycle; i < maxI; ++i) {
        bool primeNumber = true;
        for (size_t j = 0; j < sizeOfPNA; ++j) {
            if (i % primeNumberArray[j] == 0) {
                primeNumber = false;
                break;
            }
        }
        if (primeNumber) {
            primeNumberArray[sizeOfPNA] = i;
            ++sizeOfPNA;
            if ((n % i == 0) && (i * i != n)) {
                break;
            }
        }
    }
    int result = primeNumberArray[sizeOfPNA - 1];
    delete[] primeNumberArray;
    return result;
}

[[nodiscard]] int EuclidAlgorithm(int a, int b) {
    int q{};
    int r{};
    int x{};
    int x1{};
    int x2 = 1;
    int y{};
    int y1 = 1;
    int y2{};

    while (b > 0) {
        q = a / b;
        r = a - q * b;
        x = x2 - q * x1;
        y = y2 - q * y1;
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }

    if (y2 < x2) {
        return y2;
    } else {
        return x2;
    }
}

void OutputResults(int encryptedMessage, int decryptedMessage, Decrypter::Results results, int openKey, int N) {
    std::cout << "Открытый ключ(e, N): (" << openKey << ' ' << N << ")\n";
    std::cout << "Закрытый ключ(d, N): (" << results.closeKey << ' ' << N << ")\n";
    std::cout << "Функция Эйлера: " << results.valueEulerFunction << std::endl;
    std::cout << "Зашифрованное сообщение: " << encryptedMessage << std::endl;
    std::cout << "Расшифрованное сообщение " << decryptedMessage << std::endl;
}
}  // namespace

namespace Decrypter {
[[nodiscard]] int DecryptMessage(int encryptedMessage, int closeKey, int N) {
    int decryptedMessage = 1;
    for (int i = 0; i < closeKey; ++i) {
        decryptedMessage = (decryptedMessage * encryptedMessage) % N;
    }
    return decryptedMessage;
}

[[nodiscard]] int EncryptMessage(int message, int openKey, int N) {
    int encryptedMessage = 1;
    for (int i = 0; i < openKey; ++i) {
        encryptedMessage = (encryptedMessage * message) % N;
    }
    return encryptedMessage;
}

[[nodiscard]] Results FindCloseKey(const int encryptedMessage, const int openKey, const int N) {
    const int maxI = 100;
    int startCycle = 2;
    int p{};
    int q{};
    int valueEulerFunction{};
    int closeKey{};
    int y2{};
    int I = 0;

    while (I < maxI && (encryptedMessage != EncryptMessage(DecryptMessage(encryptedMessage, closeKey, N), openKey, N))) {
        p = FindPrimeNumberN(N, startCycle);
        startCycle = p + 1;
        if (p == 0) {
            ++startCycle;
            continue;
        }
        q = N / p;
        valueEulerFunction = FindEulerFunctionResult(p, q);
        y2 = EuclidAlgorithm(valueEulerFunction, openKey);
        if (y2 < 0) {
            closeKey = y2 + valueEulerFunction;
        } else {
            closeKey = y2;
        }
        ++I;
    }

    return Results{closeKey, valueEulerFunction};
}

void StartUp() {
    const int encryptedMessage = 171;
    const int openKey = 53;
    const int N = 299;

    Results results = FindCloseKey(encryptedMessage, openKey, N);
    int decryptedMessage = DecryptMessage(encryptedMessage, results.closeKey, N);

    OutputResults(encryptedMessage, decryptedMessage, results, openKey, N);
}

}  // namespace Decrypter
