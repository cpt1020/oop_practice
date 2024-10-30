#include "Date.h"
#include <string>

// Overload << operator
std::ostream &operator<<(std::ostream &os, const Date &obj) {
    os << "Year: " << *obj.year << ", Month: " << *obj.month << ", Day: " << *obj.day;
    return os;
}

// Overload no-arg constructor
Date::Date()
    : Date {1, 1, 1} {
        // std::cout << "No-arg constructor called for " << *this << std::endl;
}

// Overload three-arg constructor
Date::Date(unsigned short year_val, unsigned short month_val, unsigned short day_val) {
    year = new unsigned short;
    month = new unsigned short;
    day = new unsigned short;
    *year = year_val;
    *month = month_val;
    *day = day_val;
    // std::cout << "Three-arg constructor called for " << *this << std::endl;
}

// Deep copy constructor
Date::Date(const Date &source)
    : Date {*source.year, *source.month, *source.day} {
    // std::cout << "Copy constructor called for " << *this << std::endl;
}

// Move constructor
Date::Date(Date &&source)
    : year {source.year}, month {source.month}, day {source.day} {
        source.year = nullptr;
        source.month = nullptr;
        source.day = nullptr;
        // std::cout << "Move constructor called for " << *this << std::endl;
}

// Destructor
Date::~Date() {
    // if (year != nullptr && month != nullptr && day != nullptr) {
    //     std::cout << "Destructor called for " << *this << std::endl;
    // }
    // else {
    //     std::cout << "Destructor called" << std::endl;
    // }

    delete year;
    delete month;
    delete day;
}

void Date::set_year(unsigned short year_val) {
    *year = year_val;
}
void Date::set_month(unsigned short month_val) {
    *year = month_val;
}
void Date::set_day(unsigned short day_val) {
    *year = day_val;
}

unsigned short Date::get_year() const {
    return *year;
}
unsigned short Date::get_month() const {
    return *month;
}
unsigned short Date::get_day() const {
    return *day;
}

std::string Date::get_MMDD() const {
    return std::to_string(*month) + "/" + std::to_string(*day);
}

std::string Date::get_MMDDYYYY() const {
    return std::to_string(*month) + "/" + std::to_string(*day) + "/" + std::to_string(*year);
}