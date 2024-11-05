#include "ExitController.h"

ExitController::ExitController(View &view_val, Model &model_val) : Controller(view_val, model_val) {}

void ExitController::Handle() {
    view_.DisplayMessage("\n\n\n\n");
    view_.CenteredOutput("~Thanks for your visiting~");
    view_.CenteredOutput("We wish you and your animals safe and sound :)");
    view_.DisplayMessage("\n\n\n\n");
};