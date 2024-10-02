#include <cmath>
#include <iostream>

namespace {
const int kTaskOneNumber = 1;
const int kTaskTwoNumber = 2;
const int kTaskThreeNumber = 3;
const int kTaskFourNumber = 4;

const int kTaskFourIntermediateSumCaseOne = 3;
const int kTaskFourIntermediateSumCaseTwo = 5;
const int kTaskFourIntermediateSumCaseThree = 10;
}  // namespace

void taskOne() {
    int n = 0;
    int m = 0;
    std::cout << "Введите натуральные числа n и m (m < n):" << std::endl;
    std::cin >> n >> m;

    int naturalSum = 0;
    for (int i = 5; i <= n; i += 5) {
        if (i % m != 0) {
            naturalSum += i;
        }
    }
    std::cout << "Ответ на задачу: " << naturalSum << std::endl;
}

void taskTwo() {
    int a = 0;
    std::cout << "Введите число a:" << std::endl;
    std::cin >> a;

    int S = 1;
    if (a >= 0) {
        for (int i = 2; i <= 8; i += 2) {
            S *= i * i;
        }
        S -= a;
    } else {
        for (int i = 3; i <= 9; i += 3) {
            S *= (i - 2);
        }
    }
    std::cout << "Ответ на задачу: " << S << std::endl;
}

void taskThree() {
    float Y = .0;
    float A = .0;
    float A_last = .0;
    float S = .0;
    float S_last = .0;
    int n = 1;

    for (float x = .0; x <= 1; x += 0.2) {
        Y = 1 + x * exp(x) * cos(M_PI / 4);

        A = 0;
        A_last = cos(M_PI / 4);
        S = 1 + cos(M_PI / 4);
        S_last = 1;
        n = 1;
        while (S - S_last > 1e-6) {
            S_last = S;
            A = A_last / n * x;
            A_last = A;
            S += A;
            ++n;
        }
        std::cout << x << "\t" << Y << "\t" << S << "\t" << n + 2 << std::endl;
    }
}

int taskFour() {
    float y = .0;
    int n = 0;
    float x = .0;
    std::cout << "Введите числа n (n - натуральное число) и x (|x| < 1)" << std::endl;
    std::cin >> n >> x;

    bool isRunning = true;
    char userChoiceToContinue = 'n';
    while (isRunning) {
        float A_last = 1.;
        for (int i = 1; i <= n; i++) {
            y += A_last * x / i;
            A_last = A_last * x * (-1);
            if (i != n && (i == kTaskFourIntermediateSumCaseOne || i == kTaskFourIntermediateSumCaseTwo || i == kTaskFourIntermediateSumCaseThree)) {
                std::cout << "Промежуточное значение суммы при количестве слагаемых " << i << ": " << y << std::endl;
            }
        }
        std::cout << "Значение искомой суммы: " << y << std::endl;
        std::cout << "Хотите продолжить вычислять? (y/n)" << std::endl;
        std::cin >> userChoiceToContinue;
        if (userChoiceToContinue == 'y') {
            std::cout << "Введите новое число n:" << std::endl;
            std::cin >> n;
        } else {
            isRunning = false;
        }
    }

    return 0;
}

int main(int, char**) {
    int userTaskChoice = -1;
    char userChoiceToContinue = -1;
    bool isRunning = true;

    while (isRunning) {
        std::cout << "\nВыберите задачу из списка и напишите её номер для выподнения:\n";
        for (int i = 1; i <= 4; i++) {
            std::cout << "\tЗадача №" << i << std::endl;
        }

        std::cin >> userTaskChoice;
        if (std::cin.fail() || userTaskChoice < kTaskOneNumber || userTaskChoice > kTaskFourNumber) {
            std::cout << "Неправильный ввод" << std::endl;
            return 1;
        }

        std::cout << "\nЗадача №" << userTaskChoice << std::endl;
        switch (userTaskChoice) {
            case kTaskOneNumber:
                taskOne();
                break;
            case kTaskTwoNumber:
                taskTwo();
                break;
            case kTaskThreeNumber:
                taskThree();
                break;
            case kTaskFourNumber:
                taskFour();
                break;
            default:
                std::cout << "Неправильный ввод" << std::endl;
                return 1;
        }

        std::cout << "\nПродолжить работу? (y/n)" << std::endl;
        std::cin >> userChoiceToContinue;
        if (userChoiceToContinue == 'y') {
            continue;
        } else {
            isRunning = false;
        }
    }
    return 0;
}
