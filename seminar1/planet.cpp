#include "planet.hpp"
#include "string.h"
#include <iostream>
#include <cstring>
#include <fstream>

const int kMaxCharSize = 30;

class Planet {

private:
    // int id_;
    char *planet_ = nullptr;
    long int diameter_;
    bool life_;
    int satelittes_;

public:

    Planet()
    {
        planet_ = new char[kMaxCharSize];
        memcpy(this->planet_, "planet_name", sizeof this->planet_);
        this->diameter_ = 123;
        this->satelittes_ = 12;
        this->life_ = true;
    }
    // static int total;
    Planet(char *planet, int diameter, bool life, int satelittes) {
        // this->id_ = total++;
        this->planet_ = planet;
        this->diameter_ = diameter;
        this->life_ = life;
        this->satelittes_ = satelittes;
        // std::cout << "Создание ID " << this->id_;
    }
    ~Planet() {
        // total--;
        delete[] this->planet_;
        // std::cout << "Удаление ID " << this->id_;
    }
    Planet& operator=(const Planet& other) {
        if (this != &other) {  // Check for self-assignment
            delete[] planet_;  // Free existing memory
            planet_ = new char[strlen(other.planet_) + 1];  // Allocate new memory
            strcpy(planet_, other.planet_);                 // Copy the string
            diameter_ = other.diameter_;
            life_ = other.life_;
            satelittes_ = other.satelittes_;
        }
        return *this;
    }
    bool operator<(const Planet &other) {
        return this->diameter_ > other.diameter_;
    }
    bool operator>(const Planet &other) {
        return this->diameter_ > other.diameter_;
    }
    bool operator==(const Planet &other) {
        return this->diameter_ == other.diameter_;
    }
    char* GetPlanetName() { return this->planet_; }
    int GetPlanetDiameter() { return this->diameter_; }
    bool GetPlanetLife() { return this->life_; }
    int GetPlanetSatelittes() { return this->satelittes_; }
    void SetPlanetName(char* planet) {
        delete[] planet_;
        planet_ = new char[strlen(planet) + 1];
        strcpy(planet_, planet);
    }
    void SetPlanetDiameter(int diameter) { this->diameter_ = diameter; }
    void SetPlanetLife(bool life) { this->life_ = life; }
    void SetPlanetSatelittes(int satelittes) { this->satelittes_ = satelittes; }
};


std::ostream &operator<<(std::ostream &out, Planet planet) {
    out << planet.GetPlanetName() << ' ' << planet.GetPlanetDiameter() << ' ' << planet.GetPlanetLife() << ' ' << planet.GetPlanetSatelittes() << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, Planet& planet) {
    char tempPlanet[kMaxCharSize];
    int tempDiameter;
    bool tempLife;
    int tempSatellites;

    // Read data from the input stream
    in >> tempPlanet >> tempDiameter >> tempLife >> tempSatellites;

    // Set the data in the Planet object
    planet.SetPlanetName(tempPlanet);  // This will allocate memory internally
    planet.SetPlanetDiameter(tempDiameter);
    planet.SetPlanetLife(tempLife);
    planet.SetPlanetSatelittes(tempSatellites);

    return in;
}


Planet* sort_db(Planet* planets){
    size_t numberOfPlanets = sizeof(planets) / sizeof(Planet);
    Planet temp;
    for (size_t i = 0; i < numberOfPlanets; ++i) {
        for (size_t j = i + 1; j < numberOfPlanets; ++j) {
            if (planets[i] < planets[j]) {
                temp = planets[j];
                planets[j] = planets[i];
                planets[i] = temp;
            }
        }
    }
    return planets;
}


int read_db(const char* file_name, Planet* planets, int Size) {
        std::ifstream file(file_name);
        if (!file) {
            std::cout << "Неудача при открытии файла abc.\n";
            return 0;
        }
        int i = 0;
        while (file >> planets[i++]){std::cout << planets[i - 1].GetPlanetName();}
        return i;
    }

void write_db(const char* file_name, Planet* planets, int n_planet) {
    std::ofstream file(file_name);
    // if (!file) {
    //     std::cout << "Неудача при открытии файла info.\n";
    //     return;
    // }
    for (int i = 0; i < n_planet; ++i) {
        file << planets[i];
    }
}

void print_db(Planet* planets, int n_planet) {
    for (int i = 0; i < n_planet; ++i) {
        std::cout << planets[i];
    }
}
