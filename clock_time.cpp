#include <iostream>

namespace {
const int kNominalCase = 1;
const int kGenitiveCaseHighBoundary = 4;
const int kPluralGenitiveCaseLowBoundary = 10;
const int kPluralGenitiveCaseHighBoundary = 19;

const int kNumberToGetRemainderByTen = 10;
const int kNumberToGetIntegerDivisionByTen = 10;

const int kNightMin = 0;
const int kNightMax = 4;
const int kMorningMin = 5;
const int kMorningMax = 11;
const int kMiddayMin = 12;
const int kMiddayMax = 17;
const int kEveningMin = 18;
const int kEveningMax = 23;

const int kMinHoursInclude = 0;
const int kMinMinutesInclude = 0;
const int kMaxHoursInclude = 23;
const int kMaxMinutesInclude = 59;
}  // namespace

int main() {
    int hours = kMinHoursInclude;
    int minutes = kMinMinutesInclude;

    std::cout << "Введите время в формате: часы(от 0 минут до 23 часов включительно) минуты(от 0 минут до 59 минут включительно)" << std::endl;
    std::cin >> hours >> minutes;

    if (!std::cin.good() || (hours < kMinHoursInclude || hours > kMaxHoursInclude || minutes < kMinMinutesInclude || minutes > kMaxMinutesInclude)) {
        std::cout << "введены недопустимые данные" << std::endl;
        return 1;
    }

    if (hours == kMiddayMin && minutes == kMinMinutesInclude) {
        std::cout << "полдень" << std::endl;
        return 0;
    } else if (hours == kMinHoursInclude && minutes == kMinMinutesInclude) {
        std::cout << "полночь" << std::endl;
        return 0;
    }

    int formatedHours = hours - kMiddayMin * (hours > kMiddayMin);
    std::cout << formatedHours;

    if (formatedHours == kNominalCase) {
        std::cout << " час";
    } else if (formatedHours <= kGenitiveCaseHighBoundary) {
        std::cout << " часа";
    } else {
        std::cout << " часов";
    }

    int remainderOfMinutesByTen = minutes % kNumberToGetRemainderByTen;
    if (minutes != kMinMinutesInclude) {
        std::cout << " " << minutes;
        if (minutes >= kPluralGenitiveCaseLowBoundary && minutes <= kPluralGenitiveCaseHighBoundary) {
            std::cout << " минут";
        } else if (remainderOfMinutesByTen == kNominalCase) {
            std::cout << " минута";
        } else if (remainderOfMinutesByTen <= kGenitiveCaseHighBoundary) {
            std::cout << " минуты";
        } else {
            std::cout << " минут";
        }
    }

    if (hours >= kMorningMin && hours <= kMorningMax) {
        std::cout << " утра";
    } else if (hours >= kMiddayMin && hours <= kMiddayMax) {
        std::cout << " дня";
    } else if (hours >= kEveningMin && hours <= kEveningMax) {
        std::cout << " вечера";
    } else if (hours >= kNightMin && hours <= kNightMax) {
        std::cout << " ночи";
    }

    if (minutes == kMinMinutesInclude) {
        std::cout << " ровно";
    }

    std::cout << std::endl;
    return 0;
}
