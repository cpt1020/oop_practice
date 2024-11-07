#include "MainMenuController.h"
#include "UserRegistrationController.h"
#include "AnimalRegistrationController.h"
#include "ShowRegisteredAnimalController.h"
#include "ShowVetInfoController.h"
#include "ShowScheduleInfoController.h"
#include "VetRecommendationController.h"
#include "AppointmentMakingController.h"
#include "ShowAppointmentController.h"
#include "ShowRouteController.h"
#include "ExitController.h"
#include <iostream>

MainMenuController::MainMenuController(View &view_val, Model &model_val) : Controller(view_val, model_val) {
    controller_ptrs_[1] = std::move(UserRegistrationController::CreateControllerPtr(view_val, model_val));
    controller_ptrs_[2] = std::move(AnimalRegistrationController::CreateControllerPtr(view_val, model_val));
    controller_ptrs_[3] = std::move(ShowRegisteredAnimalController::CreateControllerPtr(view_val, model_val));
    controller_ptrs_[4] = std::move(ShowVetInfoController::CreateControllerPtr(view_val, model_val));
    controller_ptrs_[5] = std::move(ShowScheduleInfoController::CreateControllerPtr(view_val, model_val));
    controller_ptrs_[6] = std::move(VetRecommendationController::CreateControllerPtr(view_val, model_val));
    controller_ptrs_[7] = std::move(AppointmentMakingController::CreateControllerPtr(view_val, model_val));
    controller_ptrs_[8] = std::move(ShowAppointmentController::CreateControllerPtr(view_val, model_val));
    controller_ptrs_[9] = std::move(ShowRouteController::CreateControllerPtr(view_val, model_val));
    controller_ptrs_[0] = std::move(ExitController::CreateControllerPtr(view_val, model_val));
}

int MainMenuController::GetUserChoice() {
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear input cache
    return choice;
}

void MainMenuController::Handle() {
    int choice;

    do {
        view_.DisplayMainMenu();
        choice = GetUserChoice();
        view_.ClearTerminal();

        if (choice < 0 || choice > 9) {
            view_.DisplayMessage("Invalid input, please enter again");
        }
        else if (choice == 0) {
            controller_ptrs_[choice]->Handle();
            return;
        }
        else {
            controller_ptrs_[choice]->Handle();
        }
        
        view_.DisplayMessage("\nPress enter to back to main menu");
        std::cin.ignore();
        view_.ClearTerminal();
    } while (choice != 0);

}