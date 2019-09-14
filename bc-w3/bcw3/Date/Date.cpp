#include <iostream>
#include "Date.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {
    try {
        this->validate(day, month, year);
    } catch (InvalidDate e) {
        std::cout << "Value error: " << e.text << " is invalid date." << std::endl;
        throw e;
    }
}

Date::~Date() {}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::validate(int day, int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string text = std::to_string(day) + '/' + std::to_string(month) + '/' + std::to_string(year);
    
    if ( month > 0 && month <= 12 && year >= 0 && day > 0 ) {
        if ( (!(year % 400) || !(year % 4)) && month == 2 ) {
            if ( day <= daysInMonth[month-1] + 1 ) {
                return;
            }
        } else {
            if ( day <= daysInMonth[month-1] ) {
                return;
            }
        }
    }
    throw InvalidDate(text);
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
    return out << date.getDay() << '/' << date.getMonth() << '/' << date.getYear();
}
