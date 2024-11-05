#include <string>
#include <memory>
#include "Owner.h"
#include "Date.h"
#include "DogFactory.h"
#include "Dog.h"

std::shared_ptr<Animal> DogFactory::CreateAnimal(std::shared_ptr<Owner> &owner, std::string &name, std::string &breeds, Date dob_val) {
    return Dog::CreatePet(owner, name, breeds, dob_val);
}