#ifndef PLANET
#define PLANET_H
#pragma once
#include <iostream>
#include <cstring>
#include <fstream>

const int kMaxCharSize = 30;

const char FILE_PATH[61] = "/home/hariokl/gitrep/Laboratory-inf-24/projectClass/info.txt";

class Planet {
private:
    char *planet_ = nullptr;
    long int diameter_;
    bool life_;
    int satelittes_;
public:
    Planet() {}

    Planet(const char *planet, int diameter, bool life, int satelittes) {
        this->planet_ = new char[strlen(planet) + 1];
        strcpy(this->planet_, planet);
        this->diameter_ = diameter;
        this->life_ = life;
        this->satelittes_ = satelittes;
    }

    ~Planet() {
        delete[] this->planet_;
    }

    Planet(const Planet &other) {  // Copy Constructor (Deep Copy)
        this->planet_ = new char[strlen(other.planet_) + 1];
        strcpy(this->planet_, other.planet_);
        this->diameter_ = other.diameter_;
        this->life_ = other.life_;
        this->satelittes_ = other.satelittes_;
    }

    Planet &operator=(const Planet &other) {  // Copy Assignment Operator (Deep Copy)
        if (this != &other) {
            this->SetPlanetName(other.planet_);
            this->diameter_ = other.diameter_;
            this->life_ = other.life_;
            this->satelittes_ = other.satelittes_;
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
        delete[] this->planet_;
        this->planet_ = new char[strlen(planet) + 1];
        strcpy(this->planet_, planet);
    }
    void SetPlanetDiameter(int diameter) { this->diameter_ = diameter; }
    void SetPlanetLife(bool life) { this->life_ = life; }
    void SetPlanetSatelittes(int satelittes) { this->satelittes_ = satelittes; }
};

Planet* sort_db(Planet* planets, int numberOfPlanets);

int read_db(Planet* planets, int currentI, int maxSize);

void write_db(Planet* planets, int n_planet);

void print_db(Planet* planets, int n_planet);

Planet* delete_planet(Planet* planets, int& numberOfPlanets);

Planet* redact_planet(Planet* planets, int& numberOfPlanets);

Planet* add_planet(Planet* planets, int& numberOfPlanets);
#endif
