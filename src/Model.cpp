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
using namespace std;

Model::Model()
    : user {nullptr} {
        vet_initialize();
        schedule = new Schedule(vets);
        map = new Map();
}

Model::~Model() {
    delete user;
    delete schedule;
    delete map;

    for (int i {0}; i < vets.size(); ++i) {
        delete vets.at(i);
    }
}

bool Model::user_register(string &fname, string &lname, unsigned short &year, unsigned short &month, unsigned short &day, string &mobile, char &rd, int &house_num) {
    string road {map->get_rd_name(rd)};
    string addr {to_string(house_num) + " " + road};
    user = new Owner(fname, lname, Date {year, month, day}, mobile, addr);

    return (user != nullptr) ? true : false;
}

bool Model::animal_register(string &name, int &species, string &breeds, unsigned short &year, unsigned short &month, unsigned short &day) {
    Animal *new_pet {nullptr};
    
    switch (species) {
        case 1:
            // Dog
            new_pet = new Dog(name, breeds, Date {year, month, day});
            break;
        case 2:
            // Cat
            new_pet = new Cat(name, breeds, Date {year, month, day});
            break;
        case 3:
            // Exotic Animals
            new_pet = new ExoticAnimal(name, breeds, Date {year, month, day});
            break;
        default:
            break;
    }

    if (new_pet == nullptr) {
        return false;
    }

    int pet_num {user->get_pet_num()};
    user->add_pet(new_pet);

    return (pet_num + 1 == user->get_pet_num()) ? true : false;
}

void Model::show_animals() const {
    user->show_pet();
}

void Model::vet_initialize() {

    Vet *valerie = new Vet("Valerie", "Smith");
    Vet *lisa = new Vet("Lisa", "Chen");
    Vet *chris = new Vet("Chris", "Horton");
    Vet *amanda = new Vet("Amanda", "Wang");
    Vet *jeff = new Vet("Jeff", "Evans");

    valerie->set_species({4,4,0});
    lisa->set_species({2,4,0});
    chris->set_species({4,3,1});
    amanda->set_species({1,1,4});
    jeff->set_species({1,1,4});

    valerie->set_specialty({3,1,1,0,2,0,4});
    lisa->set_specialty({1,4,0,2,0,3,0});
    chris->set_specialty({2,1,4,3,3,1,2});
    amanda->set_specialty({4,2,3,1,0,1,0});
    jeff->set_specialty({3,4,1,2,0,3,0});

    vets.push_back(valerie);
    vets.push_back(lisa);
    vets.push_back(chris);
    vets.push_back(amanda);
    vets.push_back(jeff);

}

auto comp = [](pair<int, string> &p1, pair<int, string> &p2) {
    return p1.first < p2.first;
};

void show_ranked_species(Vet *vet, unordered_map<int, string> &species_list) {
    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> max_heap(comp);
    for (int i {0}; i < vet->get_species_num(); ++i) {
        if (vet->get_species_score(i) >= 2) {
            max_heap.push({vet->get_species_score(i), species_list[i]});
        }
    }

    while (max_heap.empty() != true) {
        cout << max_heap.top().second << ((max_heap.size() == 1) ? " " : ", ");
        max_heap.pop();
    }
    cout << endl;
}

void show_ranked_specialty(Vet *vet, unordered_map<int, string> &specialty_list) {
    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> max_heap(comp);
    for (int i {0}; i < vet->get_specialty_num(); ++i) {
        if (vet->get_specialty_score(i) >= 2) {
            max_heap.push({vet->get_specialty_score(i), specialty_list[i]});
        }
    }

    while (max_heap.empty() != true) {
        cout << max_heap.top().second << ((max_heap.size() == 1) ? " " : ", ");
        max_heap.pop();
    }
    cout << endl;
}

void Model::show_vet_info() const {
    unordered_map<int, string> species_list;
    species_list[0] = "Dog";
    species_list[1] = "Cat";
    species_list[2] = "Exotic Animal";

    unordered_map<int, string> specialty_list;
    // Internal Medicine, Surgery, Oncology, Opthalamology, Neurology, Orthopedics, Cardiology
    specialty_list[0] = "Internal Medicine";
    specialty_list[1] = "Surgery";
    specialty_list[2] = "Oncology";
    specialty_list[3] = "Opthalamology";
    specialty_list[4] = "Neurology";
    specialty_list[5] = "Orthopedics";
    specialty_list[6] = "Cardiology";

    for (auto const &vet: this->vets) {
        cout << "\n" << vet->get_full_name() << "   D.V.M" << endl;
        cout << "[Expertise in Animal Species] ";
        show_ranked_species(vet, species_list);
        cout << "[Expertise in Specialties] ";
        show_ranked_specialty(vet, specialty_list);
    }
}

void Model::show_schedule() const {
    cout << *schedule;
}

string Model::recommed_vet(int &species_num, vector<int> &problem_num) {
    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> max_heap(comp);
    
    for (auto const &vet : vets) {
        int score {0};
        string vet_name {vet->get_full_name()};

        int idx {species_num - 1};
        score += vet->get_species_score(idx) * 50;

        for (auto const &num : problem_num) {
            idx = num - 1;
            score += vet->get_specialty_score(idx) * 10;
        }

        max_heap.push({score, vet_name});
    }

    return max_heap.top().second;
}

bool Model::verify_input(char &rd, int &num) const {
    return map->verify_input(rd, num);
}

void Model::show_map() const {
    cout << *map;
}

void Model::shortest_path_to_hospital() const {
    map->dijkstra();
}

bool Model::check_animal_name(string &animal_name) const {
    return user->check_animal_name(animal_name);
}

bool Model::make_rsvn(unsigned short &month, unsigned short &day, string &rsvn_clinic, string &animal_name) const {
    Reservation *rsvn = new Reservation(schedule->get_date(month, day), rsvn_clinic, user->get_pet(animal_name), schedule->get_vet(month, day, rsvn_clinic));
    if (rsvn == nullptr) {
        return false;
    }

    return user->make_rsvn(rsvn);
}

void Model::show_appointment() const {
    user->show_rsvn();
}