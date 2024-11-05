#include "Date.h"
#include <string>

// Overload << operator
std::ostream &operator<<(std::ostream &os, const Date &obj) {
    os << "Year: " << obj.year_ << ", Month: " << obj.month_ << ", Day: " << obj.day_;
    return os;
}

// Overload no-arg constructor
Date::Date()
    : Date {1, 1, 1} { }

// Overload three-arg constructor
Date::Date(unsigned short year_val, unsigned short month_val, unsigned short day_val)
    : year_ {year_val}, month_ {month_val}, day_ {day_val} {
}

// Deep copy constructor
Date::Date(const Date &source)
    : Date {source.year_, source.month_, source.day_} {}

void Date::SetYear(unsigned short year_val) {
    year_ = year_val;
}
void Date::SetMonth(unsigned short month_val) {
    month_ = month_val;
}
void Date::SetDay(unsigned short day_val) {
    day_ = day_val;
}
unsigned short Date::GetYear() const {
    return year_;
}
unsigned short Date::GetMonth() const {
    return month_;
}
unsigned short Date::GetDay() const {
    return day_;
}

std::string Date::GetMMDD() const {
    return std::to_string(month_) + "/" + std::to_string(day_);
}

std::string Date::GetMMDDYYYY() const {
    return std::to_string(month_) + "/" + std::to_string(day_) + "/" + std::to_string(year_);
}