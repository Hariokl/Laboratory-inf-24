#pragma once

namespace approximator{
typedef double (*FunctionReturn)();

enum class Functions{
    linear = '1',
    sineWave,
    degree,
    arctan
};

int* GenerateRandomNumber(double minNumber, double maxNumber);

int IntRect();

int IntTrap();
FunctionReturn ChooseFunction(int userChoice);

void StartUp();
}
