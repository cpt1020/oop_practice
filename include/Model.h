#ifndef _MODEL_H_
#define _MODEL_H_
#include <vector>
#include "ModelInterface.h"
#include "Owner.h"
#include "Animal.h"
#include "Date.h"
#include "Reservation.h"
#include "Vet.h"
#include "Schedule.h"
#include "Map.h"

class Model : public ModelInterface {
private:
    Owner *user;
    Schedule *schedule;
    Map *map;

    vector<Vet *> vets;

public:

    Model();
    virtual ~Model();
    bool user_register(string &fname, string &lname, unsigned short &year, unsigned short &month, unsigned short &day, string &mobile, char &rd, int &house_num);
    bool animal_register(string &name, int &species, string &breeds, unsigned short &year, unsigned short &month, unsigned short &day);
    void show_animals() const;
    void vet_initialize();
    void show_vet_info() const;
    void show_schedule() const;
    void shortest_path_to_hospital() const;
    void show_map() const;
    bool verify_input(char &rd, int &num) const;
    bool check_animal_name(string &animal_name) const;
    bool make_rsvn(unsigned short &month, unsigned short &day, string &rsvn_clinic, string &animal_name) const;
    string recommed_vet(int &species_num, vector<int> &problem_num);
    void show_appointment() const;

};

#endif