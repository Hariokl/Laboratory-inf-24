#include <iostream>

namespace {
const int kOne = 1;
const int kTwo = 2;
const int kThree = 3;
const int kFour = 4;
const int kFive = 5;

const int kMinTime = 0;
const int kMorning = 5;
const int kModTen = 10;
const int kHalfADay = 12;
const int kEvening = 18;
const int kMaxHours = 24;
const int kMaxMinutes = 60;
}  // namespace

int main() {
    int hours = kMinTime;
    int minutes = kMinTime;
    std::cin >> hours >> minutes;

    // std::cin.good() checks if inputs are of correct types
    if (!(std::cin.good() && hours >= kMinTime && hours < kMaxHours && minutes >= kMinTime && minutes < kMaxMinutes)) {
        std::cout << "введены недопустимые данные" << std::endl;
        return 1;
    }

    if (hours == kHalfADay && minutes == kMinTime) {
        std::cout << "полдень" << std::endl;
        return 0;
    } else if (hours == kMinTime && minutes == kMinTime) {
        std::cout << "полночь" << std::endl;
        return 0;
    }

    std::cout << hours % kHalfADay;

    if (hours % kHalfADay == kOne) {
        std::cout << " час";
    } else if (hours % kHalfADay >= kTwo && hours % kHalfADay < kFive) {
        std::cout << " часа";
    } else {
        std::cout << " часов";
    }

    if (minutes != kMinTime) {
        std::cout << " " << minutes;
        if (minutes % kModTen == kOne) {
            std::cout << " минута";
        } else if (minutes % kModTen == kTwo || minutes % kModTen == kThree || minutes % kModTen == kFour) {
            std::cout << " минуты";
        } else {
            std::cout << " минут";
        }
    }

    if (kMorning <= hours && hours < kHalfADay) {
        std::cout << " утра";
    } else if (kHalfADay <= hours && hours < kEvening) {
        std::cout << " дня";
    } else if (kEvening <= hours && hours < kMaxHours) {
        std::cout << " вечера";
    } else {
        std::cout << " ночи";
    }

    if (minutes == kMinTime) {
        std::cout << " ровно";
    }

    std::cout << std::endl;
    return 0;
}
