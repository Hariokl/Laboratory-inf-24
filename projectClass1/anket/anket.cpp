#include "anket.hpp"
#include "string.h"
#include "cmath"



std::ostream &operator<<(std::ostream &out, Anket anket) {
    out << anket.GetAnketName() << ' ' << anket.GetAnketSize() << ' ' << anket.GetAnketPopularity() << ' ' << anket.GetAnketBigfoot() << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, Anket& anket) {
    char tempName[kMaxCharSize];
    int tempSize;
    int tempPop;
    int tempBigfoot;

    if (!(in >> tempName >> tempSize >> tempPop >> tempBigfoot)) {
        // in.clear();  // Clear error state
        // in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Skip invalid line
        return in;
    }

    anket.SetAnketName(tempName);
    anket.SetAnketSize(tempSize);
    anket.SetAnketPopularity(tempPop);
    anket.SetAnketBigfoot(tempBigfoot);


    return in;
}


Anket* sort_db(Anket* ankets, int numberOfPlanets){
    Anket temp;
    for (int i = 0; i < numberOfPlanets; ++i) {
        for (int j = i + 1; j < numberOfPlanets; ++j) {
            if (ankets[i] < ankets[j]) {
                temp = ankets[j];
                ankets[j] = ankets[i];
                ankets[i] = temp;
            }
        }
    }
    return ankets;
}

int read_db(Anket* ankets, int currentI, int maxSize) {
    std::ifstream file(FILE_PATH);
    if (!file) {
        std::cerr << "Ошибка при открытии файла!\n";
        return 0;
    }

    while ((currentI < maxSize) && (!file.eof())) {
        Anket anket;

        file >> anket;

        if (anket.GetAnketName() != nullptr && strlen(anket.GetAnketName()) > 0) {
            ankets[currentI++] = anket;
        }
    }

    return currentI;
}

void write_db(Anket* ankets, int n_planet) {
    std::ofstream file(FILE_PATH);
    if (!file) {
        std::cout << "Неудача при открытии файла info.\n";
        return;
    }
    for (int i = 0; i < n_planet; ++i) {
        file << ankets[i];
    }
}

void print_db(Anket* ankets, int n_planet) {
    for (int i = 0; i < n_planet; ++i) {
        std::cout << i << ". " << ankets[i];
    }
}

Anket* delete_anket(Anket* ankets, int& numberOfAnkets) {
    int deleteId;
    std::cout << "Введите ID анкеты, которую хотите удалить" << '\n';
    std::cin >> deleteId;
    if ((deleteId < 0) || (deleteId >= numberOfAnkets)) {
        std::cout << "Неверное ID" << '\n';
        return ankets;
    }

    Anket* newPlanets = new Anket[numberOfAnkets - 1];
    for (int i = 0, j = 0; i < numberOfAnkets; i++) {
        if (i != deleteId) {
            newPlanets[j++] = ankets[i];
        }
    }

    std::cout << "Успешно удалили анкету" << '\n';
    delete[] ankets;
    numberOfAnkets--;
    return newPlanets;
}

Anket* add_anket(Anket* ankets, int& numberOfAnkets) {
    Anket* newAnkets = new Anket[numberOfAnkets + 1];
    for (int i = 0; i < numberOfAnkets; i++) {
        newAnkets[i] = ankets[i];
    }

    std::cout << "Введите имя анкеты, её размер, популярность в народе и был ли замечен бигфут в анкете (1 - был замечен; 0 - не был замечен)" << '\n';
    Anket anket;
    std::cin >> anket;


    newAnkets[numberOfAnkets++] = anket;
    std::cout << (numberOfAnkets) << anket;
    return newAnkets;
}


Anket* redact_anket(Anket* ankets, int& numberOfAnkets) {
    std::cout << "Введите ID анкеты, которую хотите редактировать" << '\n';
    int id;
    std::cin >> id;

    if ((id < 0) || (id >= numberOfAnkets)) {
        std::cout << "Введено неверное ID" << '\n';
        return ankets;
    }

    std::cout << "Введите параметр анкеты, который хотите изменить: (1 - имя; 2 - размер; 3 - популярность; 4 - бигфут;)" << '\n';
    int temp;
    std::cin >> temp;

    switch (temp) {
        case 1:
            char name[100];
            std::cin >> name;
            ankets[id].SetAnketName(name);
            break;
        case 2:
            int size;
            std::cin >> size;
            ankets[id].SetAnketSize(size);
            break;
        case 3:
            int popularity;
            std::cin >> popularity;
            ankets[id].SetAnketPopularity(popularity);
            break;
        case 4:
            int bigfoot;
            std::cin >> bigfoot;
            ankets[id].SetAnketBigfoot(bigfoot);
            break;
        default:
            std::cout << "ВВедено неправильно" << '\n';
            break;
    }

    return ankets;
}
