#include "solver.h"

#include <cmath>
#include <iomanip>
#include <iostream>

namespace {
const int kMaxIteration = 1e5;
const double kStartUpEps = 1e-6;
[[nodiscard]] double CalculateFunctionValue(double x, double coef) {
    return x - coef * cos(x);
}

[[nodiscard]] double CalculateFunctionDerivative(double x, double coef) {
    return 1 + coef * sin(x);
}

void Menu(double coef, double eps) {
    std::cout << "Выберите метод решения уравнения:" << '\n';
    std::cout << '\t' << "1. Итерационный метод" << '\n';
    std::cout << '\t' << "2. Метод Ньютона" << '\n';
    std::cout << '\t' << "3. Метод половинного деления" << '\n';
    std::cout << "Если хотите изменить коэфициент k или эпсилон eps:" << '\n';
    std::cout << '\t' << "a. Изменить коэфициент k (сейчас " << coef << ')' << '\n';
    std::cout << '\t' << "b. Изменить эпсилон eps (сейчас " << std::setprecision(-log10(eps)) << eps << ')' << '\n';
}

void ChooseContinue() {
    std::cout << "Хотите продолжить выполнение программы?(y/n)" << '\n';
}

void FoundError() {
    std::cout << "Функция не дошла до нужной точности, либо решений нет, либо решений больше одного" << '\n';
}

void OutputResults(Solver::Results results, double eps) {
    std::cout << "Результаты:" << '\n';
    std::cout << std::fixed << "\tx:" << std::setprecision(-log10(eps)) <<results.x << '\n';
    std::cout << "\tn:" << results.n << '\n';
    std::cout << '\n';
}

}  // namespace

namespace Solver {
[[nodiscard]] Results CalculatingBruteForce(double coef, double eps) {
    int n = 0;
    double x = .0;
    while ((std::abs(CalculateFunctionValue(x, coef)) > eps) && (n < kMaxIteration)) {
        x -= CalculateFunctionValue(x, coef);
        ++n;
    }

    if (n == kMaxIteration) {
        x = NAN;
    }
    Results results{x, n};
    return results;
}

[[nodiscard]] Results CalculatingNewton(double coef, double eps) {
    int n = 0;
    double x = 0.;

    while ((std::abs(CalculateFunctionValue(x, coef)) > eps) && (n < kMaxIteration)) {
        x -= CalculateFunctionValue(x, coef) / CalculateFunctionDerivative(x, coef);
        ++n;
    }
    if (n == kMaxIteration) {
        x = NAN;
    }
    Results results{x, n};
    return results;
}

[[nodiscard]] Results CalculatingBisection(double coef, double eps, double leftX, double rightX) {
    int count = 0;
    double const kHalf = 2.;
    int const kBorder = 0;
    double middleX = (leftX + rightX) / kHalf;
    double calcLeft = CalculateFunctionValue(leftX, coef);
    double calcRight = CalculateFunctionValue(rightX, coef);
    double calcMiddle;
    Results results;

    if ((calcLeft > kBorder && calcRight > kBorder)) {
        results.x = NAN;
        return results;
    }


    while ((std::fabs(rightX - leftX) > eps) && (count < kMaxIteration)) {
        calcMiddle = CalculateFunctionValue(middleX, coef);
        std::cout << middleX << '\n';
        if (calcMiddle > kBorder) {
            rightX = middleX;
        } else {
            leftX = middleX;
            calcLeft = calcMiddle;
        }
        ++count;
        middleX = (leftX + rightX) / kHalf;
    }

    if (count == kMaxIteration) {
        results.x = NAN;
    } else {
        results.x = middleX;
    }
    results.n = count;
    return results;
}

void MethodBruteForce(double coef, double eps) {
    Results results = CalculatingBruteForce(coef, eps);

    if (results.x != results.x) {
        FoundError();
        return;
    }

    OutputResults(results, eps);
}

void MethodNewton(double coef, double eps) {
    Results results = CalculatingNewton(coef, eps);

    if (results.x != results.x) {
        FoundError();
        return;
    }

    OutputResults(results, eps);
}

void MethodBisection(double coef, double eps) {
    double leftX = 0.;
    double rightX = 0.;
    std::cout << "Введите значения для левого и правого конца отрезка:" << '\n';
    std::cin >> leftX >> rightX;

    Results results = CalculatingBisection(coef, eps, leftX, rightX);

    if (results.x != results.x) {
        FoundError();
        return;
    }

    OutputResults(results, eps);
}

void SelectMethod(char userChoice, double coef, double eps) {
    switch (static_cast<UserChoice>(userChoice)) {
        case UserChoice::bruteForce:
            MethodBruteForce(coef, eps);
            break;
        case UserChoice::newton:
            MethodNewton(coef, eps);
            break;
        case UserChoice::bisection:
            MethodBisection(coef, eps);
            break;
        default:
            break;
    }
}

void ChangeSettings(char userChoice, double* coef, double* eps) {
    switch (static_cast<UserChoice>(userChoice)) {
        case UserChoice::changeCoef:
            std::cin >> *coef;
            break;
        case UserChoice::changeEps:
            std::cin >> *eps;
            break;
        default:
            break;
    }
}

void StartUp() {
    char continueProgram = 'y';
    char userChoice = '1';
    double coef = 1.;
    double eps = kStartUpEps;

    while (continueProgram == 'y') {
        Menu(coef, eps);
        std::cin >> userChoice;
        SelectMethod(userChoice, coef, eps);
        ChangeSettings(userChoice, &coef, &eps);
        ChooseContinue();
        std::cin >> continueProgram;
        if (continueProgram != 'y') {
            return;
        }
    }
}

}  // namespace Solver
