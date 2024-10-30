#include "Vet.h"
#include <vector>
using namespace std;

Vet::Vet(string fname, string lname)
    : first_name {fname}, last_name {lname}, specialty (specialty_num, 0), species (species_num, 0) {
}

string Vet::get_fname() const {
    return first_name;
}

string Vet::get_lname() const {
    return last_name;
}

string Vet::get_full_name() const {
    return first_name + " " + last_name;
}

int Vet::get_species_num() const {
    return species_num;
}

int Vet::get_specialty_num() const {
    return specialty_num;
}

int Vet::get_species_score(int &idx) const {
    return species.at(idx);
}

int Vet::get_specialty_score(int &idx) const {
    return specialty.at(idx);
}

void Vet::set_specialty(vector<int> &&spec_vec) {
    for (int i {0}; i < specialty_num; ++i) {
        specialty.at(i) = spec_vec.at(i);
    }
}

void Vet::set_species(vector<int> &&species_vec) {
    for (int i {0}; i < species_num; ++i) {
        species.at(i) = species_vec.at(i);
    }
}