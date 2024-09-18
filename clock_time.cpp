#include <iostream>

namespace {
const int kOneHours = 1;   //
const int kFiveHours = 5;  //

const int kOneMinutes = 1;   //
const int kFourMinutes = 4;  //

const int kMinHoursInclude = 0;
const int kMinMinutesInclude = 0;
const int kMorningBeginsHours = 5;
const int kNumberToGetRemainderByTen = 10;        //
const int kNumberToGetIntegerDivisionByTen = 10;  //
const int kHalfADay = 12;
const int kEveningBeginsHours = 18;
const int kNightBeginsHours = 0;
const int kMaxHoursInclude = 23;
const int kMaxMinutesInclude = 59;
}  // namespace

int main() {
    int hours = kMinHoursInclude;
    int minutes = kMinMinutesInclude;

    std::cout << "Введите время в формате: часы(от 0 минут до 23 часов включительно) минуты(от 0 минут до 59 минут включительно)" << std::endl;
    std::cin >> hours >> minutes;

    if (hours < kMinHoursInclude || hours > kMaxHoursInclude || minutes < kMinMinutesInclude || minutes > kMaxMinutesInclude) {
        std::cout << "введены недопустимые данные" << std::endl;
        return 1;
    }

    if (hours == kHalfADay && minutes == kMinMinutesInclude) {
        std::cout << "полдень" << std::endl;
        return 0;
    } else if (hours == kMinHoursInclude && minutes == kMinMinutesInclude) {
        std::cout << "полночь" << std::endl;
        return 0;
    }

    int formatedHours = hours;
    if (hours > kHalfADay) {
        formatedHours = hours - kHalfADay;
    }
    std::cout << formatedHours;

    if (formatedHours == kOneHours) {
        std::cout << " час";
    } else if (formatedHours < kFiveHours) {
        std::cout << " часа";
    } else {
        std::cout << " часов";
    }

    int remainderOfMinutesByTena = minutes % kNumberToGetRemainderByTen;
    if (minutes != kMinMinutesInclude) {
        std::cout << " " << minutes;
        if (remainderOfMinutesByTena == kOneMinutes) {
            std::cout << " минута";
        } else if (minutes / kNumberToGetIntegerDivisionByTen != 1 && remainderOfMinutesByTena <= kFourMinutes) {
            std::cout << " минуты";
        } else {
            std::cout << " минут";
        }
    }

    if (hours < kMorningBeginsHours) {
        std::cout << " ночи";
    } else if (hours < kHalfADay) {
        std::cout << " утра";
    } else if (hours < kEveningBeginsHours) {
        std::cout << " дня";
    } else {
        std::cout << " вечера";
    }

    if (minutes == kMinMinutesInclude) {
        std::cout << " ровно";
    }

    std::cout << std::endl;
    return 0;
}
