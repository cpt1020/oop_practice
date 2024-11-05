#include "ShowVetInfoController.h"
#include <string>

ShowVetInfoController::ShowVetInfoController(View &view_val, Model &model_val)
    : Controller(view_val, model_val) {}

void ShowVetInfoController::Handle() {
    for (const auto &vet : model_.GetVetPtrs()) {
        std::string msg {"\n" + vet->GetFullName() + 
                            "  D.V.M\n[Expertise in Animal Species] " + 
                            model_.GetVetRankedSpecies(vet) + 
                            "\n[Expertise in Specialties] " + 
                            model_.GetVetRankedSpecialty(vet)};
        view_.DisplayMessage(msg);
    }
};