#include <iostream>

int zeroHours = 0;
int oneHours = 1;
int twoHours = 2;
int fiveHours = 5;
int twelveHours = 12;
int eighteenHours = 18;
int twentyFourHours = 24;

int zeroMinutes = 0;
int oneMinutes = 1;
int twoMinutes = 2;
int threeMinutes = 3;
int fourMinutes = 4;
int sixtyMinutes = 60;

int delimeterByTen = 10;

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
    int hours = zeroHours, minutes = zeroMinutes;
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
