#pragma once

namespace Solver {
enum class UserChoice {
    bruteForce = '1',
    newton = '2',
    bisection = '3',
    changeCoef = 'a',
    changeEps = 'b'
};

struct Results {
    double x;
    int n;
};

[[nodiscard]] Results CalculatingBruteForce(double coef, double eps);
[[nodiscard]] Results CalculatingNewton(double coef, double eps);
[[nodiscard]] Results CalculatingBisection(double coef, double eps);

void MethodBruteForce(double coef, double eps);
void MethodNewton(double coef, double eps);
void MethodBisection(double coef, double eps);

void StartUp();
void SelectMethod(char userChoice, double coef, double eps);
void ChangeSettings(char userChoice, double* coef, double* eps);
}  // namespace Solver
