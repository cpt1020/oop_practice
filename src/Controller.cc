#include "Controller.h"
#include <iostream>
#include <sstream>

Controller::Controller(View &view_val, Model &model_val)
    : view_ {view_val}, model_ {model_val} {}

bool Controller::CheckUserRegistered() {
    if (model_.IsUserRegistered() == false) {
        view_.DisplayMessage("Please register yourself first in order to use this function. Thank you!");
        return false;
    }
    return true;
}

void Controller::GetDOB(unsigned short &year, unsigned short &month, unsigned short &day) {
    std::string input_date;
    view_.DisplayMessage("Please enter the date of birth in this format MM/DD/YYYY:");
    std::cin >> input_date;

    std::istringstream date_stream(input_date);
    char delimiter;
    date_stream >> month >> delimiter >> day >> delimiter >> year;

    if (date_stream.fail() || delimiter != '/' || date_stream.peek() != EOF) {
        std::cerr << "Invalid format of date of birth" << std::endl;
    }
}