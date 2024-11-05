#include "ShowRegisteredAnimalController.h"
#include <unordered_set>
#include <memory>

ShowRegisteredAnimalController::ShowRegisteredAnimalController(View &view_val, Model &model_val)
    : Controller(view_val, model_val) {}

void ShowRegisteredAnimalController::Handle() {

    if (Controller::CheckUserRegistered() == false) {
        return;
    }

    if (model_.GetUserPtr()->GetPetNum() == 0) {
        view_.DisplayMessage("You've not registered any animal.");
        return;
    }

    std::unordered_set<std::shared_ptr<Animal>> &pets {model_.GetUserPtr()->GetPets()};
    for (const auto &pet : pets) {
        view_.DisplayMessage(pet->GetAnimalInfo());
    }
};