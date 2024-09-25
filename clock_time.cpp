#include <iostream>

namespace {
const int kNominalCase = 1;
const int kGenitiveCaseLowBoundary = 2;
const int kGenitiveCaseHighBoundary = 4;
const int kPluralGenitiveCaseLowBoundary = 10;
const int kPluralGenitiveCaseHighBoundary = 19;

const int kNumberToGetRemainderByTen = 10;
const int kNumberToGetIntegerDivisionByTen = 10;

const int kNightBeginHours = 0;
const int kNightEndHours = 4;
const int kMorningBeginHours = 5;
const int kMorningEndHours = 11;
const int kMiddayBeginHours = 12;
const int kMiddayEndHours = 17;
const int kEveningBeginHours = 18;
const int kEveningEndHours = 23;

const int kBeginHours = 0;
const int kBeginMinutes = 0;
const int kEndHours = 23;
const int kEndMinutes = 59;
}  // namespace

int main() {
    int hours = kBeginHours;
    int minutes = kBeginMinutes;

    std::cout << "Введите время в формате: часы(от 0 минут до 23 часов включительно) минуты(от 0 минут до 59 минут включительно)" << std::endl;
    std::cin >> hours >> minutes;

    if (!std::cin.good() || (hours < kBeginHours || hours > kEndHours || minutes < kBeginMinutes || minutes > kEndMinutes)) {
        std::cout << "введены недопустимые данные" << std::endl;
        return 1;
    }

    if (hours == kMiddayBeginHours && minutes == kBeginMinutes) {
        std::cout << "полдень" << std::endl;
        return 0;
    } else if (hours == kBeginHours && minutes == kBeginMinutes) {
        std::cout << "полночь" << std::endl;
        return 0;
    }

    int formatedHours = hours - kMiddayBeginHours * (hours > kMiddayBeginHours);
    std::cout << formatedHours;

    if (formatedHours == kNominalCase) {
        std::cout << " час";
    } else if (formatedHours >= kGenitiveCaseLowBoundary && formatedHours <= kGenitiveCaseHighBoundary) {
        std::cout << " часа";
    } else {
        std::cout << " часов";
    }

    int remainderOfBeginMinutesByTen = minutes % kNumberToGetRemainderByTen;
    if (minutes != kBeginMinutes) {
        std::cout << ' ' << minutes;
        if (remainderOfBeginMinutesByTen == kNominalCase && (minutes < kPluralGenitiveCaseLowBoundary || minutes > kPluralGenitiveCaseHighBoundary)) {
            std::cout << " минута";
        } else if (remainderOfBeginMinutesByTen <= kGenitiveCaseHighBoundary &&
                   (minutes < kPluralGenitiveCaseLowBoundary || minutes > kPluralGenitiveCaseHighBoundary)) {
            std::cout << " минуты";
        } else {
            std::cout << " минут";
        }
    }

    if (hours >= kMorningBeginHours && hours <= kMorningEndHours) {
        std::cout << " утра";
    } else if (hours >= kMiddayBeginHours && hours <= kMiddayEndHours) {
        std::cout << " дня";
    } else if (hours >= kEveningBeginHours && hours <= kEveningEndHours) {
        std::cout << " вечера";
    } else if (hours >= kNightBeginHours && hours <= kNightEndHours) {
        std::cout << " ночи";
    }

    if (minutes == kBeginMinutes) {
        std::cout << " ровно";
    }

    std::cout << std::endl;
    return 0;
}
