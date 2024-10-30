#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include <iostream>
#include <string>
#include "Date.h"
#include "Owner.h"
using namespace std;

class Owner;

class Animal {
    // Overload << operator
    friend ostream &operator<<(ostream &os, const Animal &obj);

private:
    string name;
    string species;
    string breeds;
    Date dob;
    Owner *owner;

public:

    // Constructor
    Animal(string name_val, string species_val, string breeds_val, Date dob_val);

    // Virtual Destructor
    virtual ~Animal();

    // void set_name(string name_val);
    // void set_species(string species_val);
    // void set_dob(Date dob_val);
    void set_owner(Owner *own_val);

    void show_owner();

    string get_name() const;
    string get_species() const;
    string get_breeds() const;
    Date get_dob() const;

    virtual void say_something() const;

};

#endif