#include <string>
#include <memory>
#include "Owner.h"
#include "Date.h"
#include "ExoticAnimalFactory.h"
#include "ExoticAnimal.h"

std::shared_ptr<Animal> ExoticAnimalFactory::CreateAnimal(std::shared_ptr<Owner> &owner, std::string &name, std::string &breeds, Date dob_val) {
    return ExoticAnimal::CreatePet(owner, name, breeds, dob_val);
}