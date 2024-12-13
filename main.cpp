#include <iomanip>
#include <iostream>


namespace {
const int kMaxPrimeNumbers = 100;
[[nodiscard]]int FindEulerFunctionResult(int p, int q) { return (p - 1) * (q - 1); }


[[nodiscard]]int FindPrimeNumber(int n, int kStartCycle) {
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

  return y2 < x2 ? y2 : x2;
}
}


[[nodiscard]]int DecryptMessage(int encryptedMessage, int closeKey, int N) {
  int decryptedMessage = 1;
  for (int i = 0; i < closeKey; ++i) {
    decryptedMessage = (decryptedMessage * encryptedMessage) % N;
  }
  return decryptedMessage;
}


int main(int, char**) {
  int encryptedMessage = 171;
  int openKey = 53;
  int N = 299;
  int startCycle = 2;


  int p = FindPrimeNumber(N, startCycle);
  startCycle = p + 1;


  int q = FindPrimeNumber(N, startCycle);


  int valueEulerFunction = FindEulerFunctionResult(p, q);
  int y2 = EuclidAlgorithm(valueEulerFunction, openKey);


  int closeKey{};
  if (y2 < 0) {
    closeKey = y2 + valueEulerFunction;
  } else {
    closeKey = y2;
  }


  int decryptedMessage = DecryptMessage(encryptedMessage, closeKey, N);


  std::cout << "Открытый ключ(e, N): (" << openKey << ' ' << N << ")\n";
  std::cout << "Закрытый ключ(d, N): (" << closeKey << ' ' << N << ")\n";
  std::cout << "Функция Эйлера: " << valueEulerFunction << std::endl;
  std::cout << "Зашифрованное сообщение: " << encryptedMessage << std::endl;
  std::cout << "Расшифрованное сообщение " << decryptedMessage << std::endl;


  return 0;
}
