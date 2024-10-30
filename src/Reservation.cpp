#include <iostream>
#include "Reservation.h"
using namespace std;

ostream &operator<<(ostream &os, const Reservation &obj) {
    os << obj.date.get_month() << "/" << obj.date.get_day() << "/" << obj.date.get_year() << " | " << obj.clinic << " clinic | Dr. " << obj.vet->get_full_name() << " | Animal: " << obj.pet->get_name();
    return os;
}

Reservation::Reservation(Date d_val, string clinic_val, Animal *pet_val, Vet *vet_val)
    : date {d_val}, clinic {clinic_val}, pet {pet_val}, vet {vet_val} {
}

Date Reservation::get_date() const {
    return date;
}

string Reservation::get_clinic() const {
    return clinic;
}

string Reservation::get_pet_name() const {
    return pet->get_name();
}

string Reservation::get_vet_name() const {
    string name {vet->get_fname() + " " + vet->get_lname()};
    return name;
}

// void Reservation::print_rsnv() const {
//     cout << "[ " << date.get_month() << "/" << date.get_day() << "/" << date.get_year() << " ] " 
//          << clinic << " clinic | Dr. " << vet->get_fname() << " " << vet->get_lname() 
//          << " | Owner: " << owner->get_fname() << " " << owner->get_lname() 
//          << " | Animal: " << pet->get_name() << endl;
// }
