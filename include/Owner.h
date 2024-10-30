#ifndef _OWNER_H_
#define _OWNER_H_
#include <iostream>
#include <set>
#include <vector>
#include "Date.h"
#include "Animal.h"
#include "Reservation.h"
using namespace std;

class Animal;
class Reservation;

class Owner {
    friend ostream &operator<<(ostream &os, const Owner &obj);

private:
    string first_name;
    string last_name;
    Date dob;
    string mobile;
    string address;
    set<Animal *> pets;
    vector<Reservation *> rsvn;

public:
    // Constructor
    Owner(string fname_val, string lname_val, Date dob_val, string mobile_val, string addr_val);

    // Destructor
    ~Owner();

    string get_fname() const;
    string get_lname() const;

    void add_pet(Animal *animal);
    void remove_pet(Animal *animal);
    void show_pet() const;
    int get_pet_num() const;
    bool check_animal_name(string &name) const;
    Animal *get_pet(string &animal_name) const;

    bool make_rsvn(Reservation *new_rsvn);
    void show_rsvn() const;

};

#endif