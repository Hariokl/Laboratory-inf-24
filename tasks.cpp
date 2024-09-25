#include <iostream>

namespace {
    const int taskOneNumber = 1;
    const int taskTwoNumber = 2;
    const int taskThreeNumber = 3;
    const int taskFourNumber = 4;
}

int taskOne() {
    int n = 0, m = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)


}

int main() {
    int taskToDo = 1;
    while (True) {
        std::cout << "\nВыберите задачу из списка и напишите её номер для выподнения:";
        for (int i = 0; i < 4; i++){
            std::cout << "\n\tЗадача №" << i;
        }
        std::cin >> taskToDo;
        std::cout << "Задача №" << taskToDo << std::endl;
        if (taskToDo == taskOneNumber){
            std::cout << taskOne() << std::endl;
        } else if (taskToDo == taskTwoNumber){
            std::cout << taskTwo() << std::endl;
        } else if (taskToDo == taskThreeNumber){
            std::cout << taskThree() << std::endl;
        } else if (taskToDo == taskFourNumber){
            std::cout << taskFour() << std::endl;
        }
        std::cout << "Продолжить работу? (y/n)";
    }
    return 0;
}
