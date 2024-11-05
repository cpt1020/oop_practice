#ifndef _EXOTICANIMALFACTORY_H_
#define _EXOTICANIMALFACTORY_H_
#include <memory>
#include <AnimalFactory.h>
#include "Owner.h"
#include "Animal.h"
#include "Date.h"

class ExoticAnimalFactory : public AnimalFactory {
public:
    virtual std::shared_ptr<Animal> CreateAnimal(std::shared_ptr<Owner> &owner, std::string &name, std::string &breeds, Date dob_val) override;
};

#endif