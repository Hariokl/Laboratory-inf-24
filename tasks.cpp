#include <iostream>

namespace {
    const int taskOneNumber = 1;
    const int taskTwoNumber = 2;
    const int taskThreeNumber = 3;
    const int taskFourNumber = 4;
}

int taskOne() {
    std::cout << "Задача 1:" << std::endl;
    int n = 0, m = 0;
    std::cin >> n >> m;


}

int main() {
    int taskToDo = 1;
    while (True) {
        std::cout << "Выберите задачу из списка и напишите её номер для выподнения:";
        for (int i = 0; i < 4; i++){
            std::cout << "\n\tЗадача №" << i;
        }
        std::cin >> taskToDo;
        if (taskToDo == taskOneNumber){
            std::cout << taskOne() << std::endl;
        } else if (taskToDo == taskTwoNumber){
            std::cout << taskTwo() << std::endl;
        } else if (taskToDo == taskThreeNumber){
            std::cout << taskTwo() << std::endl;
        } else if (taskToDo == taskFourNumber){
            std::cout << taskTwo() << std::endl;
        }

    }
    return 0;
}
