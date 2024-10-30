#include <algorithm>
#include "Owner.h"
#include "Animal.h"
using namespace std;

ostream &operator<<(ostream &os, const Owner &obj) {
    cout << "Name: " << obj.first_name << " " << obj.last_name;
    return os;
}

Owner::Owner(string fname_val, string lname_val, Date dob_val, string mobile_val, string addr_val)
    : first_name {fname_val}, last_name {lname_val}, dob {dob_val}, mobile {mobile_val}, address {addr_val} {
        // cout << "Constructor called for " << *this << endl;
}

Owner::~Owner() {
    for (int i {0}; i < rsvn.size(); ++i) {
        delete rsvn.at(i);
    }
}

string Owner::get_fname() const {
    return first_name;
}

string Owner::get_lname() const {
    return last_name;
}

void Owner::add_pet(Animal *animal) {
    pets.insert(animal);
    animal->set_owner(this);
}

void Owner::remove_pet(Animal *animal) {
    pets.erase(animal);
}

void Owner::show_pet() const {
    int idx {1};
    for (auto const &pet: pets) {
        cout << "[" << idx++ << "] " << *pet << endl;
    }
}

int Owner::get_pet_num() const {
    return static_cast<int>(pets.size());
}

bool Owner::make_rsvn(Reservation *new_rsvn) {
    int rsvn_size {static_cast<int>(rsvn.size())};

    rsvn.push_back(new_rsvn);
    sort(rsvn.begin(), rsvn.end(), [](Reservation *r1, Reservation *r2){
        if ((r1->get_date().get_year() == r2->get_date().get_year()) && (r1->get_date().get_month() == r2->get_date().get_month())) {
            return r1->get_date().get_day() < r2->get_date().get_day();
        }
        else if ((r1->get_date().get_year() == r2->get_date().get_year()) && (r1->get_date().get_month() != r2->get_date().get_month())) {
            return r1->get_date().get_month() < r2->get_date().get_month();
        }
        else {
            return r1->get_date().get_year() < r2->get_date().get_year();
        }
    });

    if (rsvn_size + 1 == rsvn.size()) {
        return true;
    }
    else {
        return false;
    }
}

void Owner::show_rsvn() const {
    if (rsvn.size() == 0) {
        cout << "You haven't made any appointment." << endl;
        return;
    }

    for (int i {0}; i < rsvn.size(); ++i) {
        cout << "[" << i + 1 << "] " << *rsvn.at(i) << endl;
    }
}

bool Owner::check_animal_name(string &name) const {
    for (auto const &p : pets) {
        if (p->get_name() == name) {
            return true;
        }
    }
    return false;
}

Animal* Owner::get_pet(string &animal_name) const {
    for (auto const &pet : pets) {
        if (pet->get_name() == animal_name) {
            return pet;
        }
    }
    return nullptr;
}