#include <iostream>

const int kZero = 0;
const int kOne = 1;
const int kTwo = 2;
const int kThree = 3;
const int kFour = 4;
const int kFive = 5;
const int kTen = 10;
const int kTwelve = 12;
const int kEighteen = 18;
const int kTwentyFour = 24;
const int kSixty = 60;

int main() {
    int hours = kZero;
    int minutes = kZero;
    std::cin >> hours >> minutes;

    if (!(hours >= kZero && hours < kTwentyFour && minutes >= kZero && minutes < kSixty)) {
        std::cout << "введены недопустимые данные";
        return 1;
    }

    if (hours == kTwelve && minutes == kZero) {
        std::cout << "полдень";
        return 0;
    } else if (hours == kZero && minutes == kZero) {
        std::cout << "полночь";
        return 0;
    }

    std::cout << hours % kTwelve;

    if (hours % kTwelve == kOne) {
        std::cout << " час";
    } else if (hours % kTwelve >= kTwo && hours % kTwelve < kFive) {
        std::cout << " часа";
    } else {
        std::cout << " часов";
    }

    if (minutes != kZero) {
        std::cout << " " << minutes;
        if (minutes % kTen == kOne) {
            std::cout << " минута";
        } else if (minutes % kTen == kTwo || minutes % kTen == kThree || minutes % kTen == kFour) {
            std::cout << " минуты";
        } else {
            std::cout << " минут";
        }
    }

    if (kFive <= hours && hours < kTwelve) {
        std::cout << " утра";
    } else if (kTwelve <= hours && hours < kEighteen) {
        std::cout << " дня";
    } else if (kEighteen <= hours && hours < kTwentyFour) {
        std::cout << " вечера";
    } else {
        std::cout << " ночи";
    }

    if (minutes == kZero) {
        std::cout << " ровно";
    }

    return 0;
}
