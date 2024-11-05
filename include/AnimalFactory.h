#ifndef _ANIMALFACTORY_H_
#define _ANIMALFACTORY_H_
#include <memory>
#include <string>
#include "Owner.h"
#include "Animal.h"
#include "Date.h"

class AnimalFactory {
public:
    virtual ~AnimalFactory() = default;
    virtual std::shared_ptr<Animal> CreateAnimal(std::shared_ptr<Owner> &owner, std::string &name, std::string &breeds, Date dob_val) = 0;
};

#endif