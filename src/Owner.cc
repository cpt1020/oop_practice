#include <algorithm>
#include "Owner.h"
#include "Date.h"
#include "Animal.h"

// static std::shared_ptr<Owner> &Owner::CreateOwner(std::string fname_val, std::string lname_val, Date dob_val, std::string mobile_val, std::string addr_val) {
//     static std::shared_ptr<Owner> owner_ptr {new Owner(fname_val, lname_val, dob_val, mobile_val, addr_val)};
//     return owner_ptr;
// }

void Owner::AddPet(std::shared_ptr<Animal> &pet) {
    pets_.insert(pet);
}

int Owner::GetPetNum() const {
    return static_cast<int>(pets_.size());
}

std::vector<std::shared_ptr<Reservation>> &Owner::GetRSVN() {
    return rsvn_;
}

std::string Owner::GetFirstName() const {
    return first_name_;
};

std::string Owner::GetLastName() const {
    return last_name_;
}

void Owner::RemovePet(std::shared_ptr<Animal> &animal) {
    pets_.erase(animal);
}

std::unordered_set<std::shared_ptr<Animal>> &Owner::GetPets() {
    return pets_;
}

void Owner::ShowPetInfo() const {
    int idx {1};
    for (const auto &pet : pets_) {
        std::cout << "[" << idx << "] " << pet->GetAnimalInfo() << std::endl;
    }
}

bool Owner::IsMyPet(std::string &pet_name) {
    for (const auto &pet : pets_) {
        if (pet->GetPetName() == pet_name) {
            return true;
        }
    }
    return false;
}

std::shared_ptr<Animal> Owner::GetPetWithName(std::string &name_val) {
    for (const auto &pet : pets_) {
        if (pet->GetPetName() == name_val) {
            return pet;
        }
    }
    return nullptr;
}

bool Owner::MakeRSVN(std::shared_ptr<Reservation> &new_rsvn) {
    int size {static_cast<int>(rsvn_.size())};
    rsvn_.push_back(new_rsvn);

    std::sort(rsvn_.begin(), rsvn_.end(), [](std::shared_ptr<Reservation> &r1, std::shared_ptr<Reservation> &r2) {
        if ((r1->GetDate().GetYear() == r2->GetDate().GetYear()) && (r1->GetDate().GetMonth() == r2->GetDate().GetMonth())) {
            return r1->GetDate().GetDay() < r2->GetDate().GetDay();
        }
        else if ((r1->GetDate().GetYear() == r2->GetDate().GetYear()) && (r1->GetDate().GetMonth() != r2->GetDate().GetMonth())) {
            return r1->GetDate().GetMonth() < r2->GetDate().GetMonth();
        }
        else {
            return r1->GetDate().GetYear() < r2->GetDate().GetYear();
        }
    });

    return (size + 1 == rsvn_.size());
}

bool Owner::HasRSVN() const {
    return (rsvn_.size() != 0);
}