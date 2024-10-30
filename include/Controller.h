#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_
#include "ControllerInterface.h"
#include "Model.h"
#include "View.h"

class View;

class Controller : public ControllerInterface {
private:
    Model *model;
    View *view;

public:

    Controller(Model *model_ptr);
    virtual ~Controller();

    bool user_register(string &fname, string &lname, unsigned short &year, unsigned short &month, unsigned short &day, string &mobile, char &rd, int &house_num);
    bool animal_register(string &name, int &species, string &breeds, unsigned short &year, unsigned short &month, unsigned short &day);
    void show_schedule() const;
    void show_vet_info() const;
    void shortest_path_to_hospital() const;
    void show_map() const;
    bool verify_input(char &rd, int &num) const;
    bool making_appointment(unsigned short &month, unsigned short &day, string &rsvn_clinic, string &animal_name) const;
    bool check_animal_name(string &animal_name) const;
    string recommend_vet(int &species_num, vector<int> &problem_num);
    void show_appointment() const;

};

#endif