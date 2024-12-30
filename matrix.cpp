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
    const int kN = 10;

int factorial(int x) {
    if (x == 0) {
        return 1;
    }
    return x * factorial(x - 1);
}

void InputSize() {
    std::cout << "\n\tВведите размерность матрицы NxM: ";
}
void InputPrecision() {
    std::cout << "\n\tВведите точность: ";
}
void InputScientific() {
    std::cout << "\n\tИспользовать научную нотацию? (y/n)";
}
void ContinueProgram() {
    std::cout << "\nПродолжить выполнение программы? (y/n)";
}


void InputChooseMethod() {
    std::cout << "\nВыберите задачу:";
    std::cout << "\n\t1. Динамический массив";
    std::cout << "\n\t2. Статический массив";
}
}

namespace Matrix {
// int RandomIntGenerator(int a, int b) {
//     std::random_device r{};
//     std::default_random_engine randomEngine(r());
//     std::uniform_int_distribution distribution(a, b);
//     return distribution(randomEngine);
// }

void CreateMatrix(double** matrix, int N, int M) {
    for (int i = 0; i < N; ++i) {
        matrix[i] = new double[M];
    }
}

void DeleteMatrix(double** matrix, int N) {
    for (int i = 0; i < N; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void FillDynamicMatrix(double** matrix, int N, int M) {
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

void DynamicMatrix() {
    int N{};
    int M{};
    int precision{};
    char scientific{};

    InputSize();
    std::cin >> N;
    std::cin >> M;
    InputPrecision();
    std::cin >> precision;
    InputScientific();
    std::cin >> scientific;

    double** matrix = new double*[N];
    CreateMatrix(matrix, N, M);
    FillDynamicMatrix(matrix, N, M);

    mprinter::PrintMatrix(matrix, N, M, precision, scientific);
    DeleteMatrix(matrix, N);
}

void FillStaticMatrix(double matrix[][kN], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = i * N + j;
        }
    }
}

void StaticMatrix() {
    const int N = 10;
    double B[N][N];
    FillStaticMatrix(B, N);

    double **xB = new double*[N];
    for (int i = 0; i < N; ++i) {
        xB[i] = B[i];
    }


    mprinter::PrintMatrix(xB, N, N, 0, 'n');

int q;
    std::cout<<B<<'\n';
std::cin >>q;
    std::cout <<"  "<<*B + 1 <<"  "<<B[2] - 1<<std::endl;
    std::cin >>q;
    std::cout<<*(B +1) - 1<<"  "<< (*B +4) + 2 <<"  "<<&B[2][23] -1 <<std::endl;
    std::cin >>q;
    std::cout<<*(*(B+3))<<"  "<<*B[3]+2 <<std::endl;
    std::cin >>q;
    std::cout<<*(B[0]+1)<<"  " <<*(*B+1)<<std::endl;
    std::cin >>q;
    std::cout<<B[1][25]<<"  "<<(B[0]+20)<<"  "<<*B[2]<<std::endl;

}

void ChooseMethod(char userChoice) {
    switch (static_cast<methods>(userChoice)) {
        case (methods::dynamicM):
            DynamicMatrix();
            break;
        case (methods::staticM):
            StaticMatrix();
            break;
        default:
            break;
    }
}

void Launcher() {
    char continueProgram = 'y';
    char userChoice = '1';

    while (continueProgram == 'y') {
        InputChooseMethod();
        std::cin >> userChoice;
        ChooseMethod(userChoice);
        ContinueProgram();
        std::cin >> continueProgram;
    }

}
}
