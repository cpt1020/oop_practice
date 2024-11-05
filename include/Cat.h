#ifndef _CAT_H_
#define _CAT_H_
#include <string>
#include <memory>
#include "Animal.h"
#include "Date.h"

class Cat : public Animal {
private:
    Cat(std::shared_ptr<Owner> &owner, std::string &name_val, std::string &breeds_val, Date &dob_val);

public:
    static std::shared_ptr<Animal> CreatePet(std::shared_ptr<Owner> &owner, std::string &name_val, std::string &breeds_val, Date dob_val) {
        std::shared_ptr<Animal> animal_ptr {new Cat(owner, name_val, breeds_val, dob_val)};
        owner->AddPet(animal_ptr);
        return animal_ptr;
    }
    virtual std::string GetAnimalInfo() const override;

};

#endif