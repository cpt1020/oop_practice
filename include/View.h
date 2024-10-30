#ifndef _VIEW_H_
#define _VIEW_H_
#include "Model.h"
#include "Controller.h"

class Controller;

class View {
private:
    Model *model;
    Controller *controller;
public:
    View(Model *model, Controller *controller);

    void display_start() const;
    void display_menu() const;
    void back_to_menu() const;
    void clear_terminal() const;
    void user_register(bool &registered);
    void animal_register(bool &animal_registered);
    void show_registered_animal() const;
    void show_schedule() const;
    void show_vet_info() const;
    void vet_recommendation() const;
    void shortest_path_to_hospital() const;
    void making_appointment() const;
    void show_appointment() const;
    void run();

};

#endif