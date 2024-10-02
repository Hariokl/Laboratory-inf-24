#include <iostream>

namespace {
const int kNominativeSingularMinutes = 1;
const int kSingularGenitiveLowerBoundaryMinutes = 2;
const int kSingularGenitiveUpperBoundaryMinutes = 4;
const int kPluralGenitiveLowerBoundaryMinutes = 10;
const int kPluralGenitiveUpperBoundaryMinutes = 19;

const int kNominativeSingularHours = 1;
const int kSingularGenitiveLowerBoundaryHours = 2;
const int kSingularGenitiveUpperBoundaryHours = 4;

const int kDecimalBase = 10;

const int kNightHoursBegin = 0;
const int kNightHoursEnd = 4;
const int kMorningHoursBegin = 5;
const int kMorningHoursEnd = 11;
const int kDayHoursBegin = 12;
const int kDayHoursEnd = 17;
const int kEveningHoursBegin = 18;
const int kEveningHoursEnd = 23;

const int kMinHours = 0;
const int kMinMinutes = 0;
const int kMaxHours = 23;
const int kMaxMinutes = 59;
}  // namespace

int main() {
    int hours = 0;
    int minutes = 0;

    std::cout << "Введите время в формате: часы (от 0 минут до 23 часов включительно) минуты (от 0 минут до 59 минут включительно)" << std::endl;
    std::cin >> hours >> minutes;

    if (!std::cin.good() || hours < kMinHours || hours > kMaxHours || minutes < kMinMinutes || minutes > kMaxMinutes) {
        std::cout << "введены недопустимые данные" << std::endl;
        return 1;
    }

    if (hours == kDayHoursBegin && minutes == kMinMinutes) {
        std::cout << "полдень" << std::endl;
        return 0;
    } else if (hours == kNightHoursBegin && minutes == kMinMinutes) {
        std::cout << "полночь" << std::endl;
        return 0;
    }

    int hours12Format = hours > kDayHoursBegin ? hours - kDayHoursBegin : hours;
    std::cout << hours12Format;

    if (hours12Format == kNominativeSingularHours) {
        std::cout << " час";
    } else if (hours12Format >= kSingularGenitiveLowerBoundaryHours && hours12Format <= kSingularGenitiveUpperBoundaryHours) {
        std::cout << " часа";
    } else {
        std::cout << " часов";
    }

    if (minutes != kMinMinutes) {
        int lastDigitMinutes = minutes % kDecimalBase;
        std::cout << ' ' << minutes;
        if (lastDigitMinutes == kNominativeSingularMinutes &&
            (minutes < kPluralGenitiveLowerBoundaryMinutes || minutes > kPluralGenitiveUpperBoundaryMinutes)) {
            std::cout << " минута";
        } else if (lastDigitMinutes >= kSingularGenitiveLowerBoundaryMinutes && lastDigitMinutes <= kSingularGenitiveUpperBoundaryMinutes &&
                   (minutes < kPluralGenitiveLowerBoundaryMinutes || minutes > kPluralGenitiveUpperBoundaryMinutes)) {
            std::cout << " минуты";
        } else {
            std::cout << " минут";
        }
    }

    if (hours >= kMorningHoursBegin && hours <= kMorningHoursEnd) {
        std::cout << " утра";
    } else if (hours >= kDayHoursBegin && hours <= kDayHoursEnd) {
        std::cout << " дня";
    } else if (hours >= kEveningHoursBegin && hours <= kEveningHoursEnd) {
        std::cout << " вечера";
    } else if (hours >= kNightHoursBegin && hours <= kNightHoursEnd) {
        std::cout << " ночи";
    }

    if (minutes == kMinMinutes) {
        std::cout << " ровно";
    }

    std::cout << std::endl;
    return 0;
}
