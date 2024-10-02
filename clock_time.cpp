#include <iostream>

namespace {
const int kNominativeMinutes = 1;
const int kSingularGenitiveMinutesLowerBoundary = 2;
const int kSingularGenitiveMinutesUpperBoundary = 4;
const int kPluralGenitiveMinutesLowerBoundary = 10;
const int kPluralGenitiveMinutesUpperBoundary = 19;

const int kNominativeHours = 1;
const int kGenitiveHoursLowerBoundary = 2;
const int kGenitiveHoursUpperBoundary = 4;

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

int main(int, char**) {
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

    int hoursIn12HoursFormat = hours > kDayHoursBegin ? hours - kDayHoursBegin : hours;
    std::cout << hours12Format;

    if (hoursIn12HoursFormat == kNominativeHours) {
        std::cout << " час";
    } else if (hoursIn12HoursFormat >= kGenitiveHoursLowerBoundary && hoursIn12HoursFormat <= kGenitiveHoursUpperBoundary) {
        std::cout << " часа";
    } else {
        std::cout << " часов";
    }

    if (minutes != kMinMinutes) {
        int lastDigitMinutes = minutes % kDecimalBase;
        std::cout << ' ' << minutes;
        if (lastDigitMinutes == kNominativeMinutes &&
            (minutes < kPluralGenitiveMinutesLowerBoundary || minutes > kPluralGenitiveMinutesUpperBoundary)) {
            std::cout << " минута";
        } else if (lastDigitMinutes >= kSingularGenitiveMinutesLowerBoundary && lastDigitMinutes <= kSingularGenitiveMinutesUpperBoundary &&
                   (minutes < kPluralGenitiveMinutesLowerBoundary || minutes > kPluralGenitiveMinutesUpperBoundary)) {
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
