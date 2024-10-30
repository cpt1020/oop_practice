#include <iostream>
#include "Animal.h"
using namespace std;

// Overload << operator
ostream &operator<<(ostream &os, const Animal &obj) {
    os << "Name: " << obj.name << " | Species: " << obj.species << " | Breeds: " << obj.breeds << " | Date of Birth: " << obj.dob.get_MMDDYYYY();
    
    // if (obj.owner != nullptr) {
    //     cout << ", Owner: " << *obj.owner;
    // }

    return os;
}

// Constructor
Animal::Animal(std::string name_val, std::string species_val, std::string breeds_val, Date dob_val)
    : name {name_val}, species {species_val}, breeds {breeds_val}, dob {dob_val}, owner {nullptr} {
        // cout << "Three-arg constructor called for " << name << endl;
}

// Destructor
Animal::~Animal() {
    // cout << "Destructor called for " << name << endl;
}

void Animal::set_owner(Owner *own_val) {
    owner = own_val;
}

string Animal::get_name() const {
    return this->name;
}

string Animal::get_species() const {
    return this->species;
}

string Animal::get_breeds() const {
    return this->breeds;
}

Date Animal::get_dob() const {
    return this->dob;
}

void Animal::say_something() const {
    cout << "Hello, I'm an animal and my name is " << name << endl;
}

void Animal::show_owner() {
    if (owner == nullptr) {
        cout << "I still don't have an owner QQ" << endl;
    }
    else {
        cout << "Owner: " << owner->get_fname() << " " << owner->get_lname() << endl;
    }
}