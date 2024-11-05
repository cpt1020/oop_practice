#include <iostream>
#include "Reservation.h"

std::ostream &operator<<(std::ostream &os, const Reservation &obj) {
    os << obj.date_.GetMonth() << "/" << obj.date_.GetDay() << "/" << obj.date_.GetYear() << " | " << obj.clinic_ << " clinic | Dr. " << obj.vet_->GetFullName() << " | Animal: " << obj.pet_->GetPetName();
    return os;
}

Reservation::Reservation(Date d_val, std::string &clinic_val, std::shared_ptr<Animal> pet_val, std::shared_ptr<Vet> vet_val)
    : date_ {d_val}, clinic_ {clinic_val}, pet_ {pet_val}, vet_ {vet_val} {
}

Date Reservation::GetDate() const {
    return date_;
}

std::string Reservation::GetClinic() const {
    return clinic_;
}

std::string Reservation::GetPetName() const {
    return pet_->GetPetName();
}

std::string Reservation::GetVetName() const {
    std::string name {vet_->GetFirstName() + " " + vet_->GetLastName()};
    return name;
}