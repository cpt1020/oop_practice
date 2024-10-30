#ifndef _DATE_H_
#define _DATE_H_
#include <iostream>
#include <string>

class Date {
    // Overload << operator
    friend std::ostream &operator<<(std::ostream &os, const Date &obj);

private:
    unsigned short *year;
    unsigned short *month;
    unsigned short *day;

public:
    // Overload constructors
    Date();
    Date(unsigned short year_val, unsigned short month_val, unsigned short day_val);

    // Copy constructor
    Date(const Date &source);

    // Move constructor
    Date(Date &&source);

    // Destructor
    ~Date();

    // Setter function
    void set_year(unsigned short year_val);
    void set_month(unsigned short month_val);
    void set_day(unsigned short day_val);

    // Getter function
    unsigned short get_year() const;
    unsigned short get_month() const;
    unsigned short get_day() const;
    std::string get_MMDD() const;
    std::string get_MMDDYYYY() const;

};

#endif