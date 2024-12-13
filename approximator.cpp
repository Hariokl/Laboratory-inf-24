#include <iostream>
#include <cmath>
#include <iomanip>
#include <cctype>
#include "approximator.hpp"

namespace {

double LinearFunction(double x){ return x; }
double SineWaveFunction(double x){ return sin(x * 22.); }
double DegreeFunction(double x){ return pow(x, 4); }
double ArctanFunction(double x){ return atan(x); }

// I_print
// void PrintTabl(int* i_prn[], size_t k){

// }

// void SelectEpsilon() {
//     std::cout << "\nВведите эпсилон для вычисления";
// }

void Menu() {
    std::cout << "\nВыберите функцию для апроксимации:";
    std::cout << "\n\t1. f = x";
    std::cout << "\n\t2. f = sin(22x)";
    std::cout << "\n\t3. f = x * x * x * x";
    std::cout << "\n\t4. f = arctan(x)";
}

void ContinueProgram() {
    std::cout << "\nПродолжить программу? (y/n)";
}

}

namespace approximator{
// int IntRect();

// int IntTrap();

FunctionReturn ChooseFunction(int userChoice){
    switch (static_cast<Functions>(userChoice)) {
        case Functions::linear:
            return LinearFunction;
        case Functions::degree:
            return DegreeFunction;
        case Functions::sineWave:
            return SineWaveFunction;
        case Functions::arctan:
            return ArctanFunction;
    }
}

void StartUp() {
    char choiceToContinue = 'y';
    char userChoice = '1';
    while (choiceToContinue == 'y') {
        Menu();
        std::cin >> userChoice;
        ChooseFunction(userChoice);
        ContinueProgram();
        std::cin >> choiceToContinue;
    }
}

}
