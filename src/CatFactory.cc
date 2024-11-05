#include <string>
#include <memory>
#include "Owner.h"
#include "Date.h"
#include "CatFactory.h"
#include "Cat.h"

std::shared_ptr<Animal> CatFactory::CreateAnimal(std::shared_ptr<Owner> &owner, std::string &name, std::string &breeds, Date dob_val) {
    return Cat::CreatePet(owner, name, breeds, dob_val);
}