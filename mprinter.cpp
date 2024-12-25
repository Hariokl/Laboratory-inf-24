#include "mprinter.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <format>

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

namespace mprinter {
void PrintMatrix(long double** matrix, int N, int M, int precision, char scientific) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    const int kMaxPrintSize = w.ws_col;
    const int kMargin = precision;
    int kMaxCols = kMaxPrintSize / (precision + kMargin);
    int kMaxRepeats = ceil(static_cast<double>(M) / static_cast<double>(kMaxCols));

    for (int kReap = 0; kReap < kMaxRepeats; ++kReap) {
        for (int kC = 0; kC < N; ++kC) {
            for (int kR = 0; (kMaxCols * kReap + kR < M) && (kR < kMaxCols);++kR) {
                if (scientific == 'y') {
                    std::cout << std::setw(precision + kMargin) << scientific << matrix[kC][kMaxCols * kReap + kR];
                } else {
                    std::cout << std::setw(precision + kMargin) << std::fixed << std::setprecision(precision) << matrix[kC][kMaxCols * kReap + kR];
                }
            }
            std::cout << '\n';
        }
        std::cout << '\n' << "================================================================================" << '\n';
    }
}

}
