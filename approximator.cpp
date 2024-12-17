#include <iostream>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <functional>
#include "approximator.hpp"

namespace {
const int kMaxFunctions = 4;
const int kMaxMethods = 2;
const int kColumnWidth = 15;
const int kMaxIterations = 1e5;

double LinearFunction(double x){ return x; }
double SineWaveFunction(double x){ return sin(x * 22.); }
double DegreeFunction(double x){ return pow(x, 4); }
double ArctanFunction(double x){ return atan(x); }


double LinearFunctionIntegral(double a, double b){ return (b*b - a*a)/2.0; }
double SineWaveFunctionIntegral(double a, double b){ return (cos(a*22.0) - cos(b*22.0))/22.0; }
double DegreeFunctionIntegral(double a, double b){ return (pow(b, 5) - pow(a, 5))/5.0; }
double ArctanFunctionIntegral(double a, double b){ return b*atan(b) - a*atan(a) - (log(b*b+1) - log(a*a+1))/2.0; }

void Menu() {
    std::cout << "\nВведите границы(a и b) для интегригрования, а также eps: ";
}

void ContinueProgram() {
    std::cout << std::endl;
    std::cout << "Продолжить программу? (y/n)";
}

void PrintMethod(int j) {
    if (j == 0) {
        std::cout << "\n\nМетод прямоугольников";
    } else {
        std::cout << "\n\nМетод трапеций";
    }
}

void TableHead() {
    std::cout << "\n" << std::setw(10) << "Function" << std::setw(10) << "Integral" << std::setw(10)<< "IntSum" << std::setw(10)<< 'N';
}

void TableBody(const char* column1, double column2, double column3, int column4, double eps) {
    std::cout << '\n' << std::setw(10) << column1 << std::setw(10) << std::setprecision(-log10(eps)) << column2;
    std::cout << std::setw(10) << std::setprecision(-log10(eps)) << column3 << std::setw(10) <<column4;
}

void InvalidData() {
    std::cout << "\nБыли введены неверные данные (методы занимают больше максимально возможного количества итераций)";
}

}

namespace Approximator{
double IntRect(TPF f, double a, double b, double dx, int* n){
    double x = a;
    double sum = 0.;
    while (((*n) < kMaxIterations) && (x < b)){
        double f1 = f(x);
        double f2 = f(x + dx);
        if (f1 <= f2){
            sum += f1 * dx;
        }else{
            sum += f2 * dx;
        }
        x += dx;
        ++(*n);
    }
    return sum;
}

double IntTrap(TPF f, double a, double b, double dx, int* n){
    double x = a;
    double sum = 0.;
    while (((*n) < kMaxIterations) && (x < b)){
        sum += dx * (f(x) + f(x + dx)) / 2.0;
        x += dx;
        ++(*n);
    }
    return sum;
}

TPF ChooseFunction(int currentIter){
    TPF function;
    switch (static_cast<Functions>(currentIter)) {
        case Functions::linear:
            function = LinearFunction;
            break;
        case Functions::degree:
            function = DegreeFunction;
            break;
        case Functions::sineWave:
            function = SineWaveFunction;
            break;
        case Functions::arctan:
            function = ArctanFunction;
            break;
    }
    return function;
}

TPFI ChooseFunctionIntegral(int currentIter){
    TPFI functionInteg;
    switch (static_cast<Functions>(currentIter)) {
        case Functions::linear:
            functionInteg = LinearFunctionIntegral;
            break;
        case Functions::degree:
            functionInteg = DegreeFunctionIntegral;
            break;
        case Functions::sineWave:
            functionInteg = SineWaveFunctionIntegral;
            break;
        case Functions::arctan:
            functionInteg = ArctanFunctionIntegral;
            break;
    }
    return functionInteg;
}

TPFM ChooseMethod(int currentIter){
    TPFM method;
    switch (static_cast<Methods>(currentIter)) {
        case Methods::rect:
            method = IntRect;
            break;
        case Methods::trap:
            method = IntTrap;
            break;
    }
    return method;
}

void Approximate(double a, double b, double eps) {
    if ((b - a < eps) || ((b - a) / eps > kMaxIterations)){
        InvalidData();
        return;
    }
    const char* kFunctionList[4] = {"y=x", "y=sin(22x)", "y=x^4", "y=arctg(x)"};
    double approxResult = 0.;
    double interResult = 0.;
    for (int j = 0; j < kMaxMethods; ++j) {
        TPFM method = ChooseMethod(j);
        PrintMethod(j);
        TableHead();
        for (int i = 0; i < kMaxFunctions; ++i) {
            int N = 0;
            approxResult = method(ChooseFunction(i), a, b, eps, &N);
            interResult = ChooseFunctionIntegral(i)(a, b);
            TableBody(kFunctionList[i], approxResult, interResult, N, eps);
        }
    }
}

void StartUp() {
    double a = 0.;
    double b = 0.;
    double eps = 0.;
    char choiceToContinue = 'y';
    while (choiceToContinue == 'y') {
        Menu();
        std::cin >> a;
        std::cin >> b;
        std::cin >> eps;
        Approximate(a, b, eps);
        ContinueProgram();
        std::cin >> choiceToContinue;
    }
}

}
