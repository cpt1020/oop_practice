#ifndef _DATE_H_
#define _DATE_H_
#include <iostream>
#include <string>

class Date {
    // Overload << operator
    friend std::ostream &operator<<(std::ostream &os, const Date &obj);
private:
    unsigned short year_;
    unsigned short month_;
    unsigned short day_;
public:
    // Overload constructors
    Date();
    Date(unsigned short year_val, unsigned short month_val, unsigned short day_val);

    // Copy constructor
    Date(const Date &source);

    // Setter function
    void SetYear(unsigned short year_val);
    void SetMonth(unsigned short month_val);
    void SetDay(unsigned short day_val);

    // Getter function
    unsigned short GetYear() const;
    unsigned short GetMonth() const;
    unsigned short GetDay() const;
    std::string GetMMDD() const;
    std::string GetMMDDYYYY() const;
};

#endif