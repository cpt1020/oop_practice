#include "AppointmentMakingController.h"
#include <string>
#include <unordered_set>
#include <iostream>
#include <memory>
#include <sstream>

AppointmentMakingController::AppointmentMakingController(View &view_val, Model &model_val)
    : Controller(view_val, model_val) {}

void AppointmentMakingController::Handle() {
    if (Controller::CheckUserRegistered() == false) {
        return;
    }

    if (model_.GetUserPtr()->GetPetNum() == 0) {
        view_.DisplayMessage("You've not registered any animal. Please register your animal before making an appointment.");
        return;
    }

    bool confirmed {false};
    unsigned short month {0}, day {0};
    std::string rsvn_clinic {""};
    std::string animal_name {""};

    while (confirmed == false) {
        view_.DisplaySchedule(*model_.GetSchedulePtr());

        std::string input_date {""};
        view_.DisplayMessage("\nPlease enter the appointment date you prefer (e.g., '11/6'):");
        std::cin >> input_date;
        std::istringstream date_stream(input_date);
        char delimiter;
        date_stream >> month >> delimiter >> day;

        view_.DisplayMessage("Please enter your preferred appointment time (e.g., 'Morning,' 'Afternoon,' 'Evening'):");
        std::cin >> rsvn_clinic;

        view_.DisplayMessage("Please enter the animal name for this appointment:");
        std::unordered_set<std::shared_ptr<Animal>> &pets {model_.GetUserPtr()->GetPets()};
        for (const auto &pet : pets) {
            view_.DisplayMessage(pet->GetAnimalInfo());
        }
        std::cin.ignore();
        std::getline(std::cin, animal_name);

        while (model_.CheckAnimalName(animal_name) == false) {
            view_.DisplayMessage("This animal has'nt been registered. Please enter registered animal name:");
            std::getline(std::cin, animal_name);
        }

        char input;
        view_.DisplayMessage("\nPlease confirm your appointment information (y/n):");
        std::string appointment_info {"[Date] " + std::to_string(month) + "/" + std::to_string(day) + " " + rsvn_clinic + " clinic\n[Animal name] " + animal_name};
        view_.DisplayMessage(appointment_info);
        std::cin >> input;

        if (input == 'Y' || input == 'y') {
            confirmed = true;
        }
        else {
            view_.ClearTerminal();
        }
    }

    if (model_.MakeAnAppointment(month, day, rsvn_clinic, animal_name) == true) {
        std::string success_msg {"\nYou've successfully scheduled a " + rsvn_clinic + " appointment on " + std::to_string(month) + "/" + std::to_string(day) + " for " + animal_name + "!"};
        view_.DisplayMessage(success_msg);
    }
    else {
        view_.DisplayMessage("\nAppointment unsuccessful, please try again.");
    }
    std::cin.ignore();
};