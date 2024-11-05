#include <iostream>
#include <memory>
#include "Model.h"
#include "Controller.h"
#include "MainMenuController.h"
#include "View.h"

int main() {

    View view;
    Model model;
    std::unique_ptr<Controller> controller_ptr {std::move(MainMenuController::CreateControllerPtr(view, model))};
    controller_ptr->Handle();

    return 0;
}