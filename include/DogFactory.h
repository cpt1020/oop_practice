#ifndef _DOGFACTORY_H_
#define _DOGFACTORY_H_
#include <memory>
#include <string>
#include "AnimalFactory.h"
#include "Owner.h"
#include "Animal.h"
#include "Date.h"

class DogFactory : public AnimalFactory {
public:
    virtual std::shared_ptr<Animal> CreateAnimal(std::shared_ptr<Owner> &owner, std::string &name, std::string &breeds, Date dob_val) override;
};

#endif