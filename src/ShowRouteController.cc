#include "ShowRouteController.h"
#include <string>
#include <vector>

ShowRouteController::ShowRouteController(View &view_val, Model &model_val)
    : Controller(view_val, model_val) {}

void ShowRouteController::Handle() {
    if (Controller::CheckUserRegistered() == false) {
        return;
    }

    std::vector<std::string> shortest_path;
    int total_dist {0};
    model_.GetShortestPath(shortest_path, total_dist);
    view_.DisplayMap(*model_.GetMapPtr());
    view_.DisplayShortestPath(shortest_path, total_dist);
};