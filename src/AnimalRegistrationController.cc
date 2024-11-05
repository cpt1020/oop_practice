#include "AnimalRegistrationController.h"
#include <iostream>

AnimalRegistrationController::AnimalRegistrationController(View &view_val, Model &model_val)
    : Controller(view_val, model_val) {}

void AnimalRegistrationController::Handle() {

    if (Controller::CheckUserRegistered() == false) {
        return;
    }

    std::string pet_name {""};
    view_.DisplayMessage("Please enter the name of your animal:");
    std::getline(std::cin, pet_name);

    int species {0};
    view_.DisplayMessage("Please enter the number of your animal species, [1] Canine, [2] Feline, [3] Exotic Animal:");
    std::cin >> species;
    while (species < 1 || species > 3) {
        view_.DisplayMessage("You entered a wrong number.");
        view_.DisplayMessage("Please enter the number of your animal species, [1] Canine, [2] Feline, [3] Exotic Animal:");
        std::cin >> species;
    }
    std::cin.ignore();

    std::string breeds {""};
    view_.DisplayMessage("Please enter the breeds of your animal (Mongrel for mixed-breed, N/A for not applicable):");
    std::getline(std::cin, breeds);

    unsigned short month {0}, day {0}, year {0};
    Controller::GetDOB(year, month, day);

    if (model_.RegisterAnimal(pet_name, species, breeds, year, month, day) == true) {
        std::string msg {"You've successfully registered your animal "};
        msg += pet_name;
        msg += "!\n";
        view_.DisplayMessage(msg);
    }
    else {
        view_.DisplayMessage("Registration failed. Please register again.");
    }
    std::cin.ignore();
};
