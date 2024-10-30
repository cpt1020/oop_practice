#include "Controller.h"
#include <iostream>
using namespace std;

Controller::Controller(Model *model_ptr)
    : model {model_ptr}, view {nullptr} {
    view = new View(model_ptr, this);
    view->run();
}

Controller::~Controller() {
    delete view;
}

bool Controller::user_register(string &fname, string &lname, unsigned short &year, unsigned short &month, unsigned short &day, string &mobile, char &rd, int &house_num) {
    return model->user_register(fname, lname, year, month, day, mobile, rd, house_num);
}

bool Controller::animal_register(string &name, int &species, string &breeds, unsigned short &year, unsigned short &month, unsigned short &day) {
    return model->animal_register(name, species, breeds, year, month, day);
}

void Controller::show_schedule() const {
    model->show_schedule();
}

void Controller::show_vet_info() const {
    model->show_vet_info();
}

string Controller::recommend_vet(int &species_num, vector<int> &problem_num) {
    return model->recommed_vet(species_num, problem_num);
}

void Controller::shortest_path_to_hospital() const {
    model->shortest_path_to_hospital();
}

void Controller::show_map() const {
    model->show_map();
}

bool Controller::verify_input(char &rd, int &num) const {
    return model->verify_input(rd, num);
}

bool Controller::check_animal_name(string &animal_name) const {
    return model->check_animal_name(animal_name);
}

bool Controller::making_appointment(unsigned short &month, unsigned short &day, string &rsvn_clinic, string &animal_name) const {
    return model->make_rsvn(month, day, rsvn_clinic, animal_name);
}

void Controller::show_appointment() const {
    model->show_appointment();
}