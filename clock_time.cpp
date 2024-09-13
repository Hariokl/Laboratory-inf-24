#include <iostream>

const int zeroHours = 0;
const int oneHours = 1;
const int twoHours = 2;
const int fiveHours = 5;
const int twelveHours = 12;
const int eighteenHours = 18;
const int twentyFourHours = 24;

const int zeroMinutes = 0;
const int oneMinutes = 1;
const int twoMinutes = 2;
const int threeMinutes = 3;
const int fourMinutes = 4;
const int sixtyMinutes = 60;

const int delimeterByTen = 10;

int main() {
    int hours = zeroHours;
    int minutes = zeroMinutes;
    std::cin >> hours >> minutes;

    if (!(hours >= zeroHours && hours < twentyFourHours && minutes >= zeroMinutes && minutes < sixtyMinutes)) {
        std::cout << "введены недопустимые данные";
        return 1;
    }

    if (hours == twelveHours && minutes == zeroMinutes) {
        std::cout << "полдень";
        return 0;
    } else if (hours == zeroHours && minutes == zeroMinutes) {
        std::cout << "полночь";
        return 0;
    }

    std::cout << hours;

    if (hours == oneHours) {
        std::cout << " час";
    } else if (hours >= twoHours && hours < fiveHours) {
        std::cout << " часа";
    } else {
        std::cout << " часов";
    }

    if (minutes != zeroMinutes) {
        std::cout << minutes;
        if (minutes % delimeterByTen == oneMinutes) {
            std::cout << " минута";
        } else if (minutes % delimeterByTen == twoMinutes || minutes % delimeterByTen == threeMinutes || minutes % delimeterByTen == fourMinutes) {
            std::cout << " минуты";
        } else {
            std::cout << " минут";
        }
    }

    if (fiveHours <= hours && hours < twelveHours) {
        std::cout << " утра";
    } else if (twelveHours <= hours && hours < eighteenHours) {
        std::cout << " дня";
    } else if (eighteenHours <= hours && hours < twentyFourHours) {
        std::cout << " вечера";
    } else {
        std::cout << " ночи";
    }

    if (minutes == zeroMinutes) {
        std::cout << " ровно";
    }

    return 0;
}
