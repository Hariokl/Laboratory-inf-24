#include "mprinter.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <format>


namespace mprinter {
void PrintMatrix(double** matrix, int N, int M, int precision, char scientific) {
    const int kMargin = 4;
    const int kScience = 6;
    const int kScientificMargin = 15;
    int kMaxCols = kMaxPrintSize / (precision + kMargin);
    int kMaxRepeats = ceil(static_cast<double>(M) / static_cast<double>(kMaxCols));

    for (int kReap = 0; kReap < kMaxRepeats; ++kReap) {
        for (int kC = 0; kC < N; ++kC) {
            for (int kR = 0; (kMaxCols * kReap + kR < M) && (kR < kMaxCols);++kR) {
                if (scientific == 'y') {
                    std::cout << std::setw(kScientificMargin) << std::fixed << std::setprecision(kScience) << std::scientific << matrix[kC][kMaxCols * kReap + kR];
                } else {
                    std::cout << std::setw(precision + kMargin) << std::fixed << std::setprecision(precision) << matrix[kC][kMaxCols * kReap + kR];
                }
            }
            std::cout << '\n';
        }
        std::cout << '\n' << "===============================================================================" << '\n';
    }
}
}
