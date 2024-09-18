#include <iostream>

namespace {
const int kOneHour = 1;
const int kFiveHour = 5;

const int kOneMinute = 1;
const int kFourMinute = 4;
const int kFirstTenMinutes = 1;  // ???

const int kMinHours = 0;
const int kMinMinutes = 0;
const int kMorningHours = 5;
const int kMinutesModTen = 10;
const int kMinutesDevideTen = 10;
const int kHalfADay = 12;
const int kEveningHours = 18;
const int kMaxHours = 24;
const int kMaxMinutes = 60;
}  // namespace

int main() {
    int hours = kMinHours;
    int minutes = kMinMinutes;
    std::cin >> hours >> minutes;

    // std::cin.good() checks if inputs are of correct types
    if (!(std::cin.good() && hours >= kMinHours && hours < kMaxHours && minutes >= kMinMinutes && minutes < kMaxMinutes)) {
        std::cout << "введены недопустимые данные" << std::endl;
        return 1;
    }

    if (hours == kHalfADay && minutes == kMinMinutes) {
        std::cout << "полдень" << std::endl;
        return 0;
    } else if (hours == kMinHours && minutes == kMinMinutes) {
        std::cout << "полночь" << std::endl;
        return 0;
    }

    if (hours == kHalfADay) {
        std::cout << hours;
    } else {
        std::cout << hours % kHalfADay;
    }

    if (hours % kHalfADay == kOneHour) {
        std::cout << " час";
    } else if (hours % kHalfADay < kFiveHour) {
        std::cout << " часа";
    } else {
        std::cout << " часов";
    }

    if (minutes != kMinMinutes) {
        std::cout << " " << minutes;
        if (minutes % kMinutesModTen == kOneMinute) {
            std::cout << " минута";
        } else if (minutes / kMinutesDevideTen != kFirstTenMinutes && minutes % kMinutesModTen <= kFourMinute) {
            std::cout << " минуты";
        } else {
            std::cout << " минут";
        }
    }

    if (kMorningHours <= hours && hours < kHalfADay) {
        std::cout << " утра";
    } else if (kHalfADay <= hours && hours < kEveningHours) {
        std::cout << " дня";
    } else if (kEveningHours <= hours && hours < kMaxHours) {
        std::cout << " вечера";
    } else {
        std::cout << " ночи";
    }

    if (minutes == kMinMinutes) {
        std::cout << " ровно";
    }

    std::cout << std::endl;
    return 0;
}
