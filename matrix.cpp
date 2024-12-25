#include "matrix.hpp"
#include "mprinter.hpp"

#include <iomanip>
#include <iostream>
#include <random>
namespace {
    const int kNMin = 8;
    const int kNMax = 15;
    const int kMMin = 8;
    const int kMMax = 15;
    const int kPrecisionMin = 3;
    const int kPrecisionMax = 8;

int factorial(int x) {
    if (x == 0) {
        return 1;
    }
    return x * factorial(x - 1);
}

void InputPrecision() {
    std::cout << "\nВведите точность: ";
}
void InputScientific() {
    std::cout << "\nИспользовать научную нотацию? (y/n)";
}
void ContinueProgram() {
    std::cout << "\nПродолжить выполнение программы? (y/n)";
}
}

namespace Matrix {
int RandomIntGenerator(int a, int b) {
    std::random_device r{};
    std::default_random_engine randomEngine(r());
    std::uniform_int_distribution distribution(a, b);
    return distribution(randomEngine);
}

void CreateMatrix(long double** matrix, int N, int M) {
    for (int i = 0; i < N; ++i) {
        matrix[i] = new long double[M];
    }
}

void DeleteMatrix(long double** matrix, int N) {
    for (int i = 0; i < N; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void FillMatrix(long double** matrix, int N, int M) {
    const int kOne = 1;
    const int kTwo = 2;
    int x = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i == j) {
                matrix[i][j] = kOne;
            } else {
                matrix[i][j] = x / pow(factorial(j + 1), i + 1);
                if ((i > j) && ((i + 1) % kTwo == kOne)) {
                    matrix[i][j] = -matrix[i][j];
                }
            }
        }
    }
}

void Launcher() {
    int N = RandomIntGenerator(kNMin, kNMax);
    int M = RandomIntGenerator(kMMin, kMMax);
    int precision{};
    long double** matrix = new long double*[N];
    CreateMatrix(matrix, N, M);
    FillMatrix(matrix, N, M);
    char continueProgram = 'y';
    char scientific = 'n';

    while (continueProgram == 'y') {
        InputPrecision();
        std::cin >> precision;
        InputScientific();
        std::cin >> scientific;

        mprinter::PrintMatrix(matrix, N, M, precision, false);
        ContinueProgram();
        std::cin >> continueProgram;
    }

    DeleteMatrix(matrix, N);
}
}
