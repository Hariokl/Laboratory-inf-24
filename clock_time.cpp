#include <iostream>

int main() {
    int hours = 0, minutes = 0;
    std::cin >> hours >> minutes;

    if (!(hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60)) {
        std::cout << "введены недопустимые данные";
        return 1;
    }

    if (hours == 12 && minutes == 0) {
        std::cout << "полдень";
        return 0;
    } else if (hours == 0 && minutes == 0) {
        std::cout << "полночь";
        return 0;
    }

    char timeOfDay[10] = "утра";
    if (5 <= hours && hours < 12) {
        *timeOfDay = *"утра";
    } else if (12 <= hours && hours < 18) {
        *timeOfDay = *"дня";
    } else if (18 <= hours && hours < 24) {
        *timeOfDay = *"вечера";
    } else {
        *timeOfDay = *"ночи";
    }

    char hoursChar[20] = "час";
    if (hours == 1) {
        *hoursChar = *"час";
    } else if (hours >= 2 && hours < 5) {
        *hoursChar = *"часа";
    } else {
        *hoursChar = *"часов";
    }

    char minutesChar[20] = "минут";
    if (minutes % 10 == 1) {
        *minutesChar = *"минута";
    } else if (minutes % 10 == 2 || minutes % 10 == 3 || minutes % 10 == 4) {
        *minutesChar = *"минуты";
    } else {
        *minutesChar = *"минут";
    }

    if (minutes == 0) {
        std::cout << hours << " " << hoursChar << " " << timeOfDay << " ровно";
        return 0;
    }

    std::cout << hours << " " << hoursChar << " " << minutes << " " << minutesChar << " " << timeOfDay;

    return 0;
}
