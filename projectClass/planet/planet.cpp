#include "planet.hpp"
#include "string.h"
#include "cmath"



std::ostream &operator<<(std::ostream &out, Planet planet) {
    out << planet.GetPlanetName() << ' ' << planet.GetPlanetDiameter() << ' ' << planet.GetPlanetLife() << ' ' << planet.GetPlanetSatelittes() << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, Planet& planet) {
    char tempPlanet[kMaxCharSize];
    int tempDiameter;
    bool tempLife;
    int tempSatellites;

    if (!(in >> tempPlanet >> tempDiameter >> tempLife >> tempSatellites)) {
        // in.clear();  // Clear error state
        // in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Skip invalid line
        return in;
    }

    planet.SetPlanetName(tempPlanet);
    planet.SetPlanetDiameter(tempDiameter);
    planet.SetPlanetLife(tempLife);
    planet.SetPlanetSatelittes(tempSatellites);


    return in;
}


Planet* sort_db(Planet* planets, int numberOfPlanets){
    Planet temp;
    for (int i = 0; i < numberOfPlanets; ++i) {
        for (int j = i + 1; j < numberOfPlanets; ++j) {
            if (planets[i] < planets[j]) {
                temp = planets[j];
                planets[j] = planets[i];
                planets[i] = temp;
            }
        }
    }
    return planets;
}

int read_db(Planet* planets, int currentI, int maxSize) {
    std::ifstream file(FILE_PATH);
    if (!file) {
        std::cerr << "Ошибка при открытии файла!\n";
        return 0;
    }

    while ((currentI < maxSize) && (!file.eof())) {
        Planet planet;

        file >> planet;

        if (planet.GetPlanetName() != nullptr && strlen(planet.GetPlanetName()) > 0) {
            planets[currentI++] = planet;
        }
    }

    return currentI;
}

void write_db(Planet* planets, int n_planet) {
    std::ofstream file(FILE_PATH);
    if (!file) {
        std::cout << "Неудача при открытии файла info.\n";
        return;
    }
    for (int i = 0; i < n_planet; ++i) {
        file << planets[i];
    }
}

void print_db(Planet* planets, int n_planet) {
    for (int i = 0; i < n_planet; ++i) {
        std::cout << i << ". " << planets[i];
    }
}

Planet* delete_planet(Planet* planets, int& numberOfPlanets) {
    int deleteId;
    std::cout << "Введите ID планеты, которую хотите удалить" << '\n';
    std::cin >> deleteId;
    if ((deleteId < 0) || (deleteId >= numberOfPlanets)) {
        std::cout << "Неверное ID" << '\n';
        return planets;
    }

    Planet* newPlanets = new Planet[numberOfPlanets - 1];
    for (int i = 0, j = 0; i < numberOfPlanets; i++) {
        if (i != deleteId) {
            newPlanets[j++] = planets[i];
        }
    }

    std::cout << "Успешно удалили планету" << '\n';
    delete[] planets;
    numberOfPlanets--;
    return newPlanets;
}

Planet* add_planet(Planet* planets, int& numberOfPlanets) {
    Planet* newPlanets = new Planet[numberOfPlanets + 1];
    for (int i = 0; i < numberOfPlanets; i++) {
            newPlanets[i] = planets[i];
    }

    std::cout << "Введите имя планеты, её диаметр, живет ли там кто-то (1 если живет, 0 если не живет), и количество спутников:" << '\n';
    Planet planet;
    std::cin >> planet;


    newPlanets[numberOfPlanets++] = planet;
    return newPlanets;
}


Planet* redact_planet(Planet* planets, int& numberOfPlanets) {
    std::cout << "Введите ID планеты, которую хотите редактировать" << '\n';
    int id;
    std::cin >> id;

    if ((id < 0) || (id >= numberOfPlanets)) {
        std::cout << "Введено неверное ID" << '\n';
        return planets;
    }

    std::cout << "Введите параметр планеты, который хотите изменить: (1 - имя; 2 - диаметр; 3 - жизнь; 4 - спутники;)" << '\n';
    int temp;
    std::cin >> temp;

    switch (temp) {
        case 1:
            char name[100];
            std::cin >> name;
            planets[id].SetPlanetName(name);
            break;
        case 2:
            int diametr;
            std::cin >> diametr;
            planets[id].SetPlanetDiameter(diametr);
            break;
        case 3:
            int life;
            std::cin >> life;
            planets[id].SetPlanetLife(life);
            break;
        case 4:
            int satelittes;
            std::cin >> satelittes;
            planets[id].SetPlanetSatelittes(satelittes);
            break;
        default:
            std::cout << "ВВедено неправильно" << '\n';
            break;
    }

    return planets;
}
