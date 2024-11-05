#include "ShowAppointmentController.h"

ShowAppointmentController::ShowAppointmentController(View &view_val, Model &model_val)
    : Controller(view_val, model_val) {}

void ShowAppointmentController::Handle() {
    if (Controller::CheckUserRegistered() == false) {
        return;
    }

    if (model_.GetUserPtr()->HasRSVN() == false) {
        view_.DisplayMessage("You haven't made any appointment.");
        return;
    }

    view_.DisplayAppointment(model_.GetUserPtr()->GetRSVN());
};