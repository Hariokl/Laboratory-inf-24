#include <iostream>

auto func_timeOfDay(int hours) {
    if (5 <= hours && hours < 12) {
        return "утра";
    } else if (12 <= hours && hours < 18) {
        return "дня";
    } else if (18 <= hours && hours < 24) {
        return "вечера";
    }
    return "ночи";
}

auto func_hoursChar(int hours) {
    if (hours == 1) {
        return "час";
    } else if (hours >= 2 && hours < 5) {
        return "часа";
    }
    return "часов";
}

auto func_minutesChar(int minutes) {
    if (minutes % 10 == 1) {
        return "минута";
    } else if (minutes % 10 == 2 || minutes % 10 == 3 || minutes % 10 == 4) {
        return "минуты";
    }
    return "минут";
}

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

    auto timeOfDay = func_timeOfDay(hours);
    auto hoursChar = func_hoursChar(hours);
    auto minutesChar = func_minutesChar(minutes);

    if (minutes == 0) {
        std::cout << hours << " " << hoursChar << " " << timeOfDay << " ровно";
        return 0;
    }

    std::cout << hours << " " << hoursChar << " " << minutes << " " << minutesChar << " " << timeOfDay;

    return 0;
}
