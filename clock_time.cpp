#include <iostream>

namespace {
const int kNominalCase = 1;
const int kGenitiveCaseLowBoundary = 2;
const int kGenitiveCaseHighBoundary = 4;
const int kPluralGenitiveCaseLowBoundary = 10;
const int kPluralGenitiveCaseHighBoundary = 19;

const int kNumberToGetRemainderByTen = 10;
const int kNumberToGetIntegerDivisionByTen = 10;

const int kNightMinHours = 0;
const int kNightMaxHours = 4;
const int kMorningMinHours = 5;
const int kMorningMaxHours = 11;
const int kMiddayMinHours = 12;
const int kMiddayMaxHours = 17;
const int kEveningMinHours = 18;
const int kEveningMaxHours = 23;

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

    if (hours == kMiddayMinHours && minutes == kMinMinutesInclude) {
        std::cout << "полдень" << std::endl;
        return 0;
    } else if (hours == kMinHoursInclude && minutes == kMinMinutesInclude) {
        std::cout << "полночь" << std::endl;
        return 0;
    }

    int formatedHours = hours - kMiddayMinHours * (hours > kMiddayMinHours);
    std::cout << formatedHours;

    if (formatedHours == kNominalCase) {
        std::cout << " час";
    } else if (formatedHours >= kGenitiveCaseLowBoundary && formatedHours <= kGenitiveCaseHighBoundary) {
        std::cout << " часа";
    } else {
        std::cout << " часов";
    }

    int remainderOfMinutesByTen = minutes % kNumberToGetRemainderByTen;
    if (minutes != kMinMinutesInclude) {
        std::cout << ' ' << minutes;
        if (remainderOfMinutesByTen == kNominalCase && (minutes < kPluralGenitiveCaseLowBoundary || minutes > kPluralGenitiveCaseHighBoundary)) {
            std::cout << " минута";
        } else if (remainderOfMinutesByTen <= kGenitiveCaseHighBoundary &&
                   (minutes < kPluralGenitiveCaseLowBoundary || minutes > kPluralGenitiveCaseHighBoundary)) {
            std::cout << " минуты";
        } else {
            std::cout << " минут";
        }
    }

    if (hours >= kMorningMinHours && hours <= kMorningMaxHours) {
        std::cout << " утра";
    } else if (hours >= kMiddayMinHours && hours <= kMiddayMaxHours) {
        std::cout << " дня";
    } else if (hours >= kEveningMinHours && hours <= kEveningMaxHours) {
        std::cout << " вечера";
    } else if (hours >= kNightMinHours && hours <= kNightMaxHours) {
        std::cout << " ночи";
    }

    if (minutes == kMinMinutesInclude) {
        std::cout << " ровно";
    }

    std::cout << std::endl;
    return 0;
}
