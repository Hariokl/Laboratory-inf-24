#pragma once

namespace mprinter {
const int kN = 10;
const int kMaxPrintSize = 79;
void PrintMatrix(double** matrix, int N, int M, int precision, char scientific);
}
