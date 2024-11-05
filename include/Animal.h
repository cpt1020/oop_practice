#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include <iostream>
#include <string>
#include <memory>
#include "Date.h"
#include "Owner.h"

class Owner;

class Animal : public std::enable_shared_from_this<Animal> {
private:
protected:
    std::string name_;
    std::string breeds_;
    Date dob_;
    std::weak_ptr<Owner> owner_;
public:
    Animal(std::shared_ptr<Owner> &owner, std::string &name_val, std::string &breeds_val, Date &dob_val)
        : owner_ {owner}, name_ {name_val}, breeds_ {breeds_val}, dob_ {dob_val} {
    }
    virtual ~Animal() = default;
    virtual std::string GetAnimalInfo() const = 0;
    std::string GetPetName() const;

};

#endif