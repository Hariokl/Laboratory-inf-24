#include <iostream>
#include <cmath.h>
#include <task_functions.h>


namespace {
    const int taskOneNumber = 1;
    const int taskTwoNumber = 2;
    const int taskThreeNumber = 3;
    const int taskFourNumber = 4;
}

int main() {
    int userTaskChoice;
    char userChoiceToContinue;

    while (true) {
        std::cout << "\nВыберите задачу из списка и напишите её номер для выподнения:\n";
        for (int i = 1; i <= 4; i++) {
            std::cout << "\tЗадача №" << i << std::endl;
        }

        while (true) {
            std::cin >> userTaskChoice;
            if (userTaskChoice >= taskOneNumber && userTaskChoice <= taskFourNumber) {
                break;
            } else if (!std::cin.good()) {
                return 1;
            }
            std::cout << "Неправильный ввод, попробуй ещё раз." << std::endl;
        }

        std::cout << "\nЗадача №" << userTaskChoice << std::endl;
        switch (userTaskChoice) {
            case taskOneNumber:
                std::cout << taskOne() << std::endl;
                break;
            case taskTwoNumber:
                std::cout << taskTwo() << std::endl;
                break;
            case taskThreeNumber:
                std::cout << taskThree() << std::endl;
                break;
            case taskFourNumber:
                std::cout << taskFour() << std::endl;
                break;
            default:
                std::cout << "Неправильный ввод." << std::endl;
        }

        std::cout << "\nПродолжить работу? (y/n)" << std::endl;
        std::cin >> userChoiceToContinue;
        if (userChoiceToContinue == 'n') {
            break;
        } else if (userChoiceToContinue == 'y') {
            continue;
        } else {
            return 1;
        }
    }
    return 0;
}
