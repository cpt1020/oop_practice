#ifndef _MODEL_H_
#define _MODEL_H_
#include <vector>
#include <array>
#include <memory>
#include <string>
#include "Owner.h"
#include "Animal.h"
#include "Date.h"
#include "Reservation.h"
#include "Vet.h"
#include "Schedule.h"
#include "Map.h"
#include "AnimalFactory.h"
#include "DogFactory.h"
#include "CatFactory.h"
#include "ExoticAnimalFactory.h"

class Model {
private:
    std::shared_ptr<Owner> user_ptr_;
    std::shared_ptr<Schedule> schedule_ptr_;
    std::shared_ptr<Map> map_ptr_;
    std::vector<std::shared_ptr<Vet>> vet_ptrs_;
    const std::array<std::string, 3> species_list_ {"Dog", "Cat", "Exotic Animal"};
    const std::array<std::string, 7> specialty_list_ {
        "Internal Medicine",
        "Surgery",
        "Oncology",
        "Opthalamology",
        "Neurology",
        "Orthopedics",
        "Cardiology"
    };
    std::unordered_map<int, std::shared_ptr<AnimalFactory>> animal_factory_ {
        {1, std::make_shared<DogFactory>()},
        {2, std::make_shared<CatFactory>()},
        {3, std::make_shared<ExoticAnimalFactory>()}
    };
    
public:
    Model();

    const std::vector<std::shared_ptr<Vet>> &GetVetPtrs() const;
    const std::array<std::string, 3> &GetSpeciesList() const;
    const std::array<std::string, 7> &GetSpecialtyList() const;
    std::string GetVetRankedSpecies(std::shared_ptr<Vet> vet);
    std::string GetVetRankedSpecialty(std::shared_ptr<Vet> vet);
    std::unordered_map<char, std::pair<int,int>> GetHouseNum();
    std::shared_ptr<Schedule> &GetSchedulePtr();
    std::shared_ptr<Map> &GetMapPtr();
    std::shared_ptr<Owner> &GetUserPtr();
    bool CheckAnimalName(std::string &name);
    bool MakeAnAppointment(unsigned short &month, unsigned short &day, std::string &rsvn_clinic, std::string &animal_name) const;
    void GetShortestPath(std::vector<std::string> &shortest_path, int &total_dist);
    bool RegisterAnimal(std::string &name, int &species, std::string &breeds, unsigned short &year, unsigned short &month, unsigned short &day);
    std::string RecommendVet(const int &species_num, const std::vector<int> &problem_num);
    bool RegisterUser(std::string &fname, std::string &lname, unsigned short &year, unsigned short &month, unsigned short &day, std::string &mobile, char &rd, int &house_num);
    bool IsUserRegistered() const;
    void InitializeVets();

};


#endif