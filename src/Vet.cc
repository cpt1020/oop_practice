#include "Vet.h"
#include <vector>

Vet::Vet(std::string fname, std::string lname) 
    : first_name_ {fname}, last_name_ {lname}, specialty_ (kSpecialtyNum_, 0), species_ (kSpeciesNum_, 0) {}

std::string Vet::GetFirstName() const {
    return first_name_;
}
std::string Vet::GetLastName() const {
    return last_name_;
}
std::string Vet::GetFullName() const {
    return first_name_ + " " + last_name_;
}
int Vet::GetSpeciesNum() const {
    return kSpeciesNum_;
}
int Vet::GetSpecialtyNum() const {
    return kSpecialtyNum_;
}
int Vet::GetSpeciesScore(int &idx) const {
    return species_.at(idx);
}
int Vet::GetSpecialtyScore(int &idx) const {
    return specialty_.at(idx);
}
void Vet::SetSpecialty(std::vector<int> &&spec_vec) {
    for (int i {0}; i < kSpecialtyNum_; ++i) {
        specialty_.at(i) = spec_vec.at(i);
    }
}
void Vet::SetSpecies(std::vector<int> &&species_vec) {
    for (int i {0}; i < kSpeciesNum_; ++i) {
        species_.at(i) = species_vec.at(i);
    }
}