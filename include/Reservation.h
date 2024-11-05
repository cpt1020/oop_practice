#ifndef _RESERVATION_H_
#define _RESERVATION_H_
#include "Date.h"
#include "Animal.h"
#include "Vet.h"
#include <iostream>
#include <memory>

class Animal;

class Reservation {
    friend std::ostream &operator<<(std::ostream &os, const Reservation &obj);
    
private:
    Date date_;
    std::string clinic_;  // morning/afternoon/evening
    std::shared_ptr<Animal> pet_;
    std::shared_ptr<Vet> vet_;

public:
    Reservation(Date d_val, std::string &clinic_val, std::shared_ptr<Animal> pet_val, std::shared_ptr<Vet> vet_val);

    Date GetDate() const;
    std::string GetClinic() const;
    std::string GetPetName() const;
    std::string GetVetName() const;
};

#endif