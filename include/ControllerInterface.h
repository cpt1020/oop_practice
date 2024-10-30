#ifndef _CONTROLLERINTERFACE_H_
#define _CONTROLLERINTERFACE_H_
#include "ControllerInterface.h"
#include "Model.h"
#include "View.h"

class ControllerInterface {
public:

    virtual bool user_register(string &fname, string &lname, unsigned short &year, unsigned short &month, unsigned short &day, string &mobile, char &rd, int &house_num) = 0;
    virtual bool animal_register(string &name, int &species, string &breeds, unsigned short &year, unsigned short &month, unsigned short &day) = 0;
    virtual void show_schedule() const = 0;
    virtual void show_vet_info() const = 0;
    virtual void shortest_path_to_hospital() const = 0;
    virtual void show_map() const = 0;
    virtual bool verify_input(char &rd, int &num) const = 0;
    virtual bool making_appointment(unsigned short &month, unsigned short &day, string &rsvn_clinic, string &animal_name) const = 0;
    virtual bool check_animal_name(string &animal_name) const = 0;
    virtual string recommend_vet(int &species_num, vector<int> &problem_num) = 0;
    virtual void show_appointment() const = 0;
};

#endif