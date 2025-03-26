#include <iostream>
#include <fstream>
#include "planet/planet.hpp"

using namespace std;

const int Size = 30;
const int l_record = 80;

int menu() {
    cout << "===================================================" << '\n';
    cout << "Выберите действие:" << '\n';
    cout << "1. Считать информацию с файла" << '\n';
    cout << "2. Записать планеты в файл" << '\n';
    cout << "3. Сортировать планеты (по диаметру)" << '\n';
    cout << "4. Добавить планету" << '\n';
    cout << "5. Удалить планету" << '\n';
    cout << "6. Редактировать планету" << '\n';
    cout << "7. Вывести планеты" << '\n';
    int tmp;
    cin >> tmp;
    return tmp;
}


int main() {
    Planet* planets = new Planet[Size];

    int numberOfPlanets = 0;
    int ind;
    while (true) {
        switch (menu()) {
            case 1:
                numberOfPlanets = read_db(planets, numberOfPlanets, Size);
                break;
            case 2:
                write_db(planets, numberOfPlanets);
                break;
            case 3:
                sort_db(planets, numberOfPlanets);
                break;
            case 4:
                planets = add_planet(planets, numberOfPlanets);
                break;
            case 5:
                planets = delete_planet(planets, numberOfPlanets);
                break;
            case 6:
                planets = redact_planet(planets, numberOfPlanets);
                break;
            case 7:
                print_db(planets, numberOfPlanets);
                break;
            default:
                cout << " Неправильный ввод" << endl;
                break;
        }
        cout << "===================================================" << '\n';
    }
    return 0;
}
