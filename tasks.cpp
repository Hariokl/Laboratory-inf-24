#include <iostream>


namespace {
    const int taskOneNumber = 1;
    const int taskTwoNumber = 2;
    const int taskThreeNumber = 3;
    const int taskFourNumber = 4;

}

int taskOne() {
    int n = 0;
    int m = 0;
    std::cout << "Введите натуральные числа n и m:" << std::endl;
    std::cin >> n >> m;

    int naturalSum = 0;
    for (int i = 5; i <= n; i+=5) {
        if (i % m != 0) {
            naturalSum += i;
        }
    }
    std::cout << "Ответ на задачу: " << naturalSum << std::endl;

    return 0;
}

int taskTwo() {
    int a = 0;
    std::cout << "Введите число a:" << std::endl;
    std::cin >> a;

    int S = 0;
    if (a >= 0) {
        for (int i = 2; i <= 8; i+=2)
    }

    return 0;
}

int taskThree() {
    return 0;
}

int taskFour() {
    return 0;
}

int main() {
    int userTaskChoice = -1;
    char userChoiceToContinue = -1;
    bool isRunning = true;

    while (isRunning) {
        std::cout << "\nВыберите задачу из списка и напишите её номер для выподнения:\n";
        for (int i = 1; i <= 4; i++) {
            std::cout << "\tЗадача №" << i << std::endl;
        }

        std::cin >> userTaskChoice;
        if (!std::cin.good() || userTaskChoice < taskOneNumber || userTaskChoice > taskFourNumber) {
            std::cout << "Неправильный ввод" << std::endl;
            return 1;
        }

        std::cout << "\nЗадача №" << userTaskChoice << std::endl;
        switch (userTaskChoice) {
            case taskOneNumber:
                taskOne();
                break;
            case taskTwoNumber:
                taskTwo();
                break;
            case taskThreeNumber:
                taskThree();
                break;
            case taskFourNumber:
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
            break;
        }
    }
    return 0;
}
