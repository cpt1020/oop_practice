#ifndef _MODELINTERFACE_H_
#define _MODELINTERFACE_H_
#include <vector>
#include "ModelInterface.h"
#include "Owner.h"
#include "Animal.h"
#include "Date.h"
#include "Reservation.h"
#include "Vet.h"
#include "Schedule.h"
#include "Map.h"

class ModelInterface {
public:

    virtual bool user_register(string &fname, string &lname, unsigned short &year, unsigned short &month, unsigned short &day, string &mobile, char &rd, int &house_num) = 0;
    virtual bool animal_register(string &name, int &species, string &breeds, unsigned short &year, unsigned short &month, unsigned short &day) = 0;
    virtual void show_animals() const = 0;
    virtual void vet_initialize() = 0;
    virtual void show_vet_info() const = 0;
    virtual void show_schedule() const = 0;
    virtual void shortest_path_to_hospital() const = 0;
    virtual void show_map() const = 0;
    virtual bool verify_input(char &rd, int &num) const = 0;
    virtual bool check_animal_name(string &animal_name) const = 0;
    virtual bool make_rsvn(unsigned short &month, unsigned short &day, string &rsvn_clinic, string &animal_name) const = 0;
    virtual string recommed_vet(int &species_num, vector<int> &problem_num) = 0;
    virtual void show_appointment() const = 0;
};

#endif