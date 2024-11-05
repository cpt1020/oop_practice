#ifndef _OWNER_H_
#define _OWNER_H_
#include <iostream>
#include <unordered_set>
#include <vector>
#include "Date.h"
#include "Animal.h"
#include "Reservation.h"

class Animal;
class Reservation;
class Date;

class Owner : public std::enable_shared_from_this<Owner> {
private:
    std::string first_name_;
    std::string last_name_;
    Date dob_;
    std::string mobile_;
    char addr_road_;
    int addr_house_num_;
    std::string address_;
    std::unordered_set<std::shared_ptr<Animal>> pets_;
    std::vector<std::shared_ptr<Reservation>> rsvn_;

    // apply singleton pattern to Owner class to ensure only one instance of Owner will be created
    // make constructor private
    Owner(std::string fname_val, std::string lname_val, Date dob_val, std::string mobile_val, std::string addr_val)
        : first_name_ {fname_val}, last_name_ {lname_val}, dob_ {std::move(dob_val)}, mobile_ {mobile_val}, address_ {addr_val} {}

    // delete copy constructor and assignment operator
    Owner(const Owner &source) = delete;
    Owner &operator=(const Owner &source) = delete;
public:

    // static std::shared_ptr<Owner> &CreateOwner(std::string fname_val, std::string lname_val, Date dob_val, std::string mobile_val, std::string addr_val);
    static std::shared_ptr<Owner> &CreateOwner(std::string fname_val, std::string lname_val, Date dob_val, std::string mobile_val, std::string addr_val) {
        static std::shared_ptr<Owner> owner_ptr {new Owner(fname_val, lname_val, dob_val, mobile_val, addr_val)};
        return owner_ptr;
    }

    void AddPet(std::shared_ptr<Animal> &pet);
    int GetPetNum() const;
    std::vector<std::shared_ptr<Reservation>> &GetRSVN();
    std::string GetFirstName() const;
    std::string GetLastName() const;
    void RemovePet(std::shared_ptr<Animal> &animal);
    std::unordered_set<std::shared_ptr<Animal>> &GetPets();
    std::shared_ptr<Animal> GetPetWithName(std::string &name_val);
    bool IsMyPet(std::string &pet_name);
    void ShowPetInfo() const;
    bool MakeRSVN(std::shared_ptr<Reservation> &new_rsvn);
    bool HasRSVN() const;

};

#endif