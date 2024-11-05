#include "UserRegistrationController.h"
#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>

UserRegistrationController::UserRegistrationController(View &view_val, Model &model_val)
    : Controller(view_val, model_val) {
}

bool UserRegistrationController::VerifyAddrInput(char &road, int &num) {
    std::unordered_map<char, std::pair<int,int>> house_num {model_.GetHouseNum()};

    // if we can't find user input's road on the map
    if (house_num.find(road) == house_num.end()) {
        return false;
    }

    if (num >= house_num[road].first && num <= house_num[road].second) {
        return true;
    }
    else {
        return false;
    }
}

void UserRegistrationController::Handle() {

    if (model_.IsUserRegistered() == true) {
        view_.DisplayMessage("You've registered.");
        return;
    }
    
    std::string first_name {""};
    view_.DisplayMessage("Please enter your first name:");
    std::getline(std::cin, first_name);

    std::string last_name {""};
    view_.DisplayMessage("Please enter your last name:");
    std::getline(std::cin, last_name);

    unsigned short month {0}, day {0}, year {0};
    Controller::GetDOB(year, month, day);

    std::string mobile {""};
    view_.DisplayMessage("Please enter you mobile number:");
    std::getline(std::cin, mobile);
    view_.ClearTerminal();

    char road;
    int house_num {0};
    view_.DisplayMap(*model_.GetMapPtr());
    view_.DisplayMessage("\nThis is the map of the city where our animal hospital is located.");
    view_.DisplayMessage("Please enter the alphabet corresponding to the road/street you live in and your house number, separated by a space.");
    view_.DisplayMessage("For example, for 100 North Ave., just enter '100 j'.");
    std::cin >> house_num >> road;
    std::cin.ignore();
    while (VerifyAddrInput(road, house_num) == false) {
        view_.DisplayMessage("Invalid input. Please enter again");
        std::cin >> house_num >> road;
        std::cin.ignore();
    }

    if (model_.RegisterUser(first_name, last_name, year, month, day, mobile, road, house_num) == true) {
        view_.DisplayMessage("You've successfully registered!");
    }
    else {
        view_.DisplayMessage("Registration failed. Please try again.");
    }
}