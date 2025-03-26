#ifndef ANKET
#define ANKET_H
#pragma once
#include <iostream>
#include <cstring>
#include <fstream>

const int kMaxCharSize = 30;

const char FILE_PATH[62] = "/home/hariokl/gitrep/Laboratory-inf-24/projectClass1/info.txt";

class Anket {
private:
    char *name_ = nullptr;
    int size_;
    int popularity_;
    int bigfoot_;
public:
    Anket() {}

    Anket(const char *name, int size, int popularity, int bigfoot) {
        this->name_ = new char[strlen(name) + 1];
        strcpy(this->name_, name);
        this->size_ = size;
        this-> popularity_ = popularity;
        this-> bigfoot_ = bigfoot;
    }

    ~Anket() {
        delete[] this->name_;
    }

    Anket(const Anket &other) {  // Copy Constructor (Deep Copy)
        this->name_ = new char[strlen(other.name_) + 1];
        strcpy(this->name_, other.name_);
        this->size_ = other.size_;
        this-> bigfoot_ = other.bigfoot_;
        this-> popularity_ = other.popularity_;
    }

    Anket &operator=(const Anket &other) {  // Copy Assignment Operator (Deep Copy)
        if (this != &other) {
            this->SetAnketName(other.name_);
            this->size_ = other.size_;
            this-> bigfoot_ = other.bigfoot_;
            this-> popularity_ = other.popularity_;
        }
        return *this;
    }

    bool operator<(const Anket &other) {
        return this->size_ > other.size_;
    }
    bool operator>(const Anket &other) {
        return this->size_ > other.size_;
    }
    bool operator==(const Anket &other) {
        return this->size_ == other.size_;
    }
    char* GetAnketName() { return this->name_; }
    int GetAnketSize() { return this->size_; }
    int GetAnketPopularity() { return this->popularity_; }
    int GetAnketBigfoot() { return this->bigfoot_; }
    void SetAnketName(char* name) {
        delete[] this->name_;
        this->name_ = new char[strlen(name) + 1];
        strcpy(this->name_, name);
    }
    void SetAnketSize(int size) { this->size_ = size; }
    void SetAnketPopularity(int popularity) { this->popularity_ = popularity; }
    void SetAnketBigfoot(int bigfoot) { this->bigfoot_ = bigfoot; }
};

Anket* sort_db(Anket* names, int numberOfAnkets);

int read_db(Anket* names, int currentI, int maxSize);

void write_db(Anket* names, int n_name);

void print_db(Anket* names, int n_name);

Anket* delete_anket(Anket* names, int& numberOfAnkets);

Anket* redact_anket(Anket* names, int& numberOfAnkets);

Anket* add_anket(Anket* names, int& numberOfAnkets);
#endif
