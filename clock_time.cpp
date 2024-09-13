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

auto func_timeOfDay(int hours) {
    if (fiveHours <= hours && hours < twelveHours) {
        return "утра";
    } else if (twelveHours <= hours && hours < eighteenHours) {
        return "дня";
    } else if (eighteenHours <= hours && hours < twentyFourHours) {
        return "вечера";
    }
    return "ночи";
}

auto func_hoursChar(int hours) {
    if (hours == oneHours) {
        return "час";
    } else if (hours >= twoHours && hours < fiveHours) {
        return "часа";
    }
    return "часов";
}

auto func_minutesChar(int minutes) {
    if (minutes % delimeterByTen == oneMinutes) {
        return "минута";
    } else if (minutes % delimeterByTen == twoMinutes || minutes % delimeterByTen == threeMinutes || minutes % delimeterByTen == fourMinutes) {
        return "минуты";
    }
    return "минут";
}

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

    auto timeOfDay = func_timeOfDay(hours);
    auto hoursChar = func_hoursChar(hours);
    auto minutesChar = func_minutesChar(minutes);

    if (minutes == zeroMinutes) {
        std::cout << hours << " " << hoursChar << " " << timeOfDay << " ровно";
        return 0;
    }

    std::cout << hours << " " << hoursChar << " " << minutes << " " << minutesChar << " " << timeOfDay;

    return 0;
}
