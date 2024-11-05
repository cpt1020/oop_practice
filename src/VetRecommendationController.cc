#include "VetRecommendationController.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

VetRecommendationController::VetRecommendationController(View &view_val, Model &model_val)
    : Controller(view_val, model_val) {}

void VetRecommendationController::Handle() {
    view_.DisplayMessage("Not sure which vet to make an appointment with?");
    view_.DisplayMessage("Then, you're in the right place!\nThis feature will find out the most suitable vet for you based on your animal's specis and it's problem!");

    int species {0};
    view_.DisplayMessage("\nFirst, please enter the number corresponding to your animal's species, [1] Canine, [2] Feline, [3] Exotic Animal:");
    std::cin >> species;
    std::cin.ignore();

    std::vector<int> problem_num;
    std::string user_input;
    view_.DisplayMessage("Next, please enter the numbers corresponding to your animal's issues, separated by spaces:");
    view_.DisplayMessage("[1] Internal Medicine (including gastroenteral issues, etc)\n[2] Surgery\n[3] Oncology\n[4] Ophthalmology\n[5] Neurology\n[6] Orthopedics\n[7] Cardiology");
    std::getline(std::cin, user_input);
    std::istringstream input_stream(user_input);
    int num;

    while (input_stream >> num) {
        problem_num.push_back(num);
    }

    std::string recommended_vet {model_.RecommendVet(species, problem_num)};
    std::string res {"\nAccording to our algorithm, Dr. "};
    res += recommended_vet;
    res += " is our top choice for you!";
    view_.DisplayMessage(res);
};