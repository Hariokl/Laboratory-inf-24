#pragma once
#include <functional>

namespace Approximator {
typedef double (*TPF)(double);
typedef double (*TPFI)(double, double);
typedef double (*TPFM)(TPF, double, double, double, int*);

enum class Functions {
    linear = 0,
    sineWave,
    degree,
    arctan
};

enum class Methods {
    rect = 0,
    trap
};

int* GenerateRandomNumber(double minNumber, double maxNumber);

double IntRect(TPF f, double a, double b, double eps, int* n);

double IntTrap(TPF f, double a, double b, double eps, int* n);

TPF ChooseFunction(int userChoice);
TPFI ChooseFunctionIntegral(int userChoice);
TPFM ChooseMethod(int userChoice);

void Approximator(double a, double b, double eps);

void StartUp();
}  // namespace Approximator
