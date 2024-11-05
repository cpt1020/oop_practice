#include "Cat.h"

Cat::Cat(std::shared_ptr<Owner> &owner, std::string &name_val, std::string &breeds_val, Date &dob_val) 
    : Animal(owner, name_val, breeds_val, dob_val) {}

std::string Cat::GetAnimalInfo() const {
    std::string info {"Name: " + this->name_ + " | Species: Cat | Breeds: " + this->breeds_ + " | Date of Birth: " + this->dob_.GetMMDDYYYY()};
    return info;
}