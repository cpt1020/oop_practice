#include "ShowScheduleInfoController.h"

ShowScheduleInfoController::ShowScheduleInfoController(View &view_val, Model &model_val)
    : Controller(view_val, model_val) {}

void ShowScheduleInfoController::Handle() {
    view_.DisplaySchedule(*model_.GetSchedulePtr());
};