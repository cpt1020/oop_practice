#ifndef _RESERVATION_H_
#define _RESERVATION_H_
#include "Date.h"
#include "Animal.h"
#include "Vet.h"
#include <iostream>
using namespace std;

class Animal;

class Reservation {
    friend ostream &operator<<(ostream &os, const Reservation &obj);
    
private:
    Date date;
    string clinic;  // morning/afternoon/evening
    Animal *pet;
    Vet *vet;

public:

    Reservation(Date d_val, string clinic_val, Animal *pet_val, Vet *vet_val);

    Date get_date() const;
    string get_clinic() const;
    string get_pet_name() const;
    string get_vet_name() const;

};

#endif