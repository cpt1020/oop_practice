#include "Model.h"
#include "Owner.h"
#include "Vet.h"
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "ExoticAnimal.h"
#include "Date.h"
#include "Schedule.h"
#include "Map.h"
#include "Reservation.h"
#include <iostream>
#include <unordered_map>
#include <utility>
#include <queue>

auto MaxHeapComp = [](std::pair<int, std::string> &p1, std::pair<int, std::string> &p2) {
    return p1.first < p2.first;
};

Model::Model() : user_ptr_ {nullptr}, map_ptr_ {new Map()} {
    InitializeVets();
    schedule_ptr_ = std::make_shared<Schedule>(vet_ptrs_);
}

const std::vector<std::shared_ptr<Vet>> &Model::GetVetPtrs() const {
    return vet_ptrs_;
}

const std::array<std::string, 3> &Model::GetSpeciesList() const {
    return species_list_;
}

const std::array<std::string, 7> &Model::GetSpecialtyList() const {
    return specialty_list_;
}

std::string Model::GetVetRankedSpecies(std::shared_ptr<Vet> vet) {
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, decltype(MaxHeapComp)> max_heap(MaxHeapComp);
    for (int i {0}; i < vet->GetSpeciesNum(); ++i) {
        if (vet->GetSpeciesScore(i) >= 2) {
            max_heap.push(std::make_pair(vet->GetSpeciesScore(i), species_list_[i]));
        }
    }

    std::string ranked_species_info {""};
    while (max_heap.empty() != true) {
        ranked_species_info += max_heap.top().second;
        ranked_species_info += ((max_heap.size() == 1) ? " " : ", ");
        max_heap.pop();
    }
    return ranked_species_info;
}

std::string Model::GetVetRankedSpecialty(std::shared_ptr<Vet> vet) {
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, decltype(MaxHeapComp)> max_heap(MaxHeapComp);
    for (int i {0}; i < vet->GetSpecialtyNum(); ++i) {
        if (vet->GetSpecialtyScore(i) >= 2) {
            max_heap.push({vet->GetSpecialtyScore(i), specialty_list_[i]});
        }
    }

    std::string ranked_specialty_info {""};
    while (max_heap.empty() != true) {
        ranked_specialty_info += max_heap.top().second;
        ranked_specialty_info += ((max_heap.size() == 1) ? " " : ", ");
        max_heap.pop();
    }
    return ranked_specialty_info;
}

std::unordered_map<char, std::pair<int,int>> Model::GetHouseNum() {
    return map_ptr_->GetHouseNum();
}

std::shared_ptr<Schedule> &Model::GetSchedulePtr() {
    return schedule_ptr_;
}

std::shared_ptr<Map> &Model::GetMapPtr() {
    return map_ptr_;
}

std::shared_ptr<Owner> &Model::GetUserPtr() {
    return user_ptr_;
}

bool Model::CheckAnimalName(std::string &name) {
    return user_ptr_->IsMyPet(name);
}

bool Model::MakeAnAppointment(unsigned short &month, unsigned short &day, std::string &rsvn_clinic, std::string &animal_name) const {
    std::shared_ptr<Reservation> rsvn = std::make_shared<Reservation>(schedule_ptr_->GetDate(month, day), rsvn_clinic, user_ptr_->GetPetWithName(animal_name), schedule_ptr_->GetVet(month, day, rsvn_clinic));
    if (rsvn == nullptr) {
        return false;
    }
    return user_ptr_->MakeRSVN(rsvn);
}

void Model::GetShortestPath(std::vector<std::string> &shortest_path, int &total_dist) {
    map_ptr_->Dijkstra(shortest_path, total_dist);
}

bool Model::RegisterAnimal(std::string &name, int &species, std::string &breeds, unsigned short &year, unsigned short &month, unsigned short &day) {
    std::shared_ptr<Animal> registered_animal {nullptr};
    int pet_num {user_ptr_->GetPetNum()};
    
    registered_animal = animal_factory_[species]->CreateAnimal(user_ptr_, name, breeds, Date {year, month, day});

    if (registered_animal == nullptr) {
        return false;
    }

    user_ptr_->AddPet(registered_animal);

    return (pet_num + 1 == user_ptr_->GetPetNum()) ? true : false;
}

std::string Model::RecommendVet(const int &species_num, const std::vector<int> &problem_num) {
    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, decltype(MaxHeapComp)> max_heap(MaxHeapComp);
    
    for (auto const &vet : vet_ptrs_) {
        int score {0};
        std::string vet_name {vet->GetFullName()};

        int idx {species_num - 1};
        score += vet->GetSpeciesScore(idx) * 50;

        for (auto const &num : problem_num) {
            idx = num - 1;
            score += vet->GetSpecialtyScore(idx) * 10;
        }

        max_heap.push({score, vet_name});
    }

    return max_heap.top().second;
}

bool Model::RegisterUser(std::string &fname, std::string &lname, unsigned short &year, unsigned short &month, unsigned short &day, std::string &mobile, char &rd, int &house_num) {
    std::string road {map_ptr_->GetRoadName(rd)};
    std::string addr {std::to_string(house_num) + " " + road};
    user_ptr_ = Owner::CreateOwner(fname, lname, std::move(Date {year, month, day}), mobile, addr);
    map_ptr_->SetUserAddrRoad(rd);
    map_ptr_->SetUserAddrHouseNum(house_num);

    return (user_ptr_ != nullptr) ? true : false;
}

bool Model::IsUserRegistered() const {
    return (user_ptr_ != nullptr);
}

void Model::InitializeVets() {
    std::shared_ptr<Vet> valerie {std::make_shared<Vet>("Valerie", "Smith")};
    std::shared_ptr<Vet> lisa {std::make_shared<Vet>("Lisa", "Chen")};
    std::shared_ptr<Vet> chris {std::make_shared<Vet>("Chris", "Horton")};
    std::shared_ptr<Vet> amanda {std::make_shared<Vet>("Amanda", "Wang")};
    std::shared_ptr<Vet> jeff {std::make_shared<Vet>("Jeff", "Evans")};

    valerie->SetSpecies({4,4,0});
    lisa->SetSpecies({2,4,0});
    chris->SetSpecies({4,3,1});
    amanda->SetSpecies({1,1,4});
    jeff->SetSpecies({1,1,4});

    valerie->SetSpecialty({3,1,1,0,2,0,4});
    lisa->SetSpecialty({1,4,0,2,0,3,0});
    chris->SetSpecialty({2,1,4,3,3,1,2});
    amanda->SetSpecialty({4,2,3,1,0,1,0});
    jeff->SetSpecialty({3,4,1,2,0,3,0});

    vet_ptrs_.push_back(valerie);
    vet_ptrs_.push_back(lisa);
    vet_ptrs_.push_back(chris);
    vet_ptrs_.push_back(amanda);
    vet_ptrs_.push_back(jeff);
}