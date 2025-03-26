#include <iostream>
#include <fstream>
#include "anket/anket.hpp"

using namespace std;

const int Size = 30;
const int l_record = 80;

int menu() {
    cout << "===================================================" << '\n';
    cout << "Выберите действие:" << '\n';
    cout << "1. Считать информацию с файла" << '\n';
    cout << "2. Записать планеты в файл" << '\n';
    cout << "3. Сортировать анкеты (по размеру)" << '\n';
    cout << "4. Добавить анкету" << '\n';
    cout << "5. Удалить анкету" << '\n';
    cout << "6. Редактировать анкету" << '\n';
    cout << "7. Вывести анкеты" << '\n';
    int tmp;
    cin >> tmp;
    return tmp;
}


int main() {
    Anket* ankets = new Anket[Size];

    int numberOfAnkets = 0;
    int ind;
    while (true) {
        switch (menu()) {
            case 1:
                numberOfAnkets = read_db(ankets, numberOfAnkets, Size);
                break;
            case 2:
                write_db(ankets, numberOfAnkets);
                break;
            case 3:
                sort_db(ankets, numberOfAnkets);
                break;
            case 4:
                ankets = add_anket(ankets, numberOfAnkets);
                break;
            case 5:
                ankets = delete_anket(ankets, numberOfAnkets);
                break;
            case 6:
                ankets = redact_anket(ankets, numberOfAnkets);
                break;
            case 7:
                print_db(ankets, numberOfAnkets);
                break;
            default:
                cout << " Неправильный ввод" << endl;
                break;
        }
        cout << "===================================================" << '\n';
    }
    return 0;
}
