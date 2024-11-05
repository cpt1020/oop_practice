#include "Schedule.h"
#include "Vet.h"
#include <iostream>
#include <iomanip>
#include <tuple>
#include <memory>
#include <vector>

// Overload << operator
std::ostream &operator<<(std::ostream &os, const Schedule &obj) {
    os << "              " << std::get<0>(obj.weekly_schedule_.at(0)).GetMMDD() << "      "
                           << std::get<0>(obj.weekly_schedule_.at(1)).GetMMDD() << "      "
                           << std::get<0>(obj.weekly_schedule_.at(2)).GetMMDD() << "      "
                           << std::get<0>(obj.weekly_schedule_.at(3)).GetMMDD() << "      "
                           << std::get<0>(obj.weekly_schedule_.at(4)).GetMMDD() << std::endl;
    os << "               Mon       Tue       Wed      Thurs      Fri    " << std::endl;
    os << "            --------- --------- --------- --------- --------- " << std::endl;
    os << "   Morning | " << std::get<2>(obj.weekly_schedule_.at(0))->GetFirstName() << " |  " 
                          << std::get<2>(obj.weekly_schedule_.at(1))->GetFirstName() << "   |  " 
                          << std::get<2>(obj.weekly_schedule_.at(2))->GetFirstName() << "  |  " 
                          << std::get<2>(obj.weekly_schedule_.at(3))->GetFirstName() << " |  "
                          << std::get<2>(obj.weekly_schedule_.at(4))->GetFirstName() << "   |" << std::endl;
    os << "            --------- --------- --------- --------- --------- " << std::endl;
    os << " Afternoon |  " << std::get<3>(obj.weekly_schedule_.at(0))->GetFirstName() << " |  " 
                           << std::get<3>(obj.weekly_schedule_.at(1))->GetFirstName() << "   | " 
                           << std::get<3>(obj.weekly_schedule_.at(2))->GetFirstName() << " |  " 
                           << std::get<3>(obj.weekly_schedule_.at(3))->GetFirstName() << "   |  "
                           << std::get<3>(obj.weekly_schedule_.at(4))->GetFirstName() << "  |" << std::endl;
    os << "            --------- --------- --------- --------- --------- " << std::endl;
    os << "   Evening |  " << std::get<4>(obj.weekly_schedule_.at(0))->GetFirstName() << "   |  " 
                           << std::get<4>(obj.weekly_schedule_.at(1))->GetFirstName() << "  |  " 
                           << std::get<4>(obj.weekly_schedule_.at(2))->GetFirstName() << " |  " 
                           << std::get<4>(obj.weekly_schedule_.at(3))->GetFirstName() << "   | "
                           << std::get<4>(obj.weekly_schedule_.at(4))->GetFirstName() << " |" << std::endl;
    os << "            --------- --------- --------- --------- --------- " << std::endl;                                 
    return os;
}

Schedule::Schedule(std::vector<std::shared_ptr<Vet>> &vets) {
    InitializeSchedule(vets);
}

void Schedule::InitializeSchedule(std::vector<std::shared_ptr<Vet>> &vets) {

    std::tuple<Date, std::string, std::shared_ptr<Vet>, std::shared_ptr<Vet>, std::shared_ptr<Vet>> monday {Date {2023, 11, 6}, "Monday", vets.at(0), vets.at(3), vets.at(1)};
    std::tuple<Date, std::string, std::shared_ptr<Vet>, std::shared_ptr<Vet>, std::shared_ptr<Vet>> tuesday {Date {2023, 11, 7}, "Tuesday", vets.at(1), vets.at(4), vets.at(2)};
    std::tuple<Date, std::string, std::shared_ptr<Vet>, std::shared_ptr<Vet>, std::shared_ptr<Vet>> wednesday {Date {2023, 11, 8}, "Wednesday", vets.at(2), vets.at(0), vets.at(3)};
    std::tuple<Date, std::string, std::shared_ptr<Vet>, std::shared_ptr<Vet>, std::shared_ptr<Vet>> thursday {Date {2023, 11, 9}, "Thursday", vets.at(3), vets.at(1), vets.at(4)};
    std::tuple<Date, std::string, std::shared_ptr<Vet>, std::shared_ptr<Vet>, std::shared_ptr<Vet>> friday {Date {2023, 11, 10}, "Friday", vets.at(4), vets.at(2), vets.at(0)};

    weekly_schedule_.push_back(monday);
    weekly_schedule_.push_back(tuesday);
    weekly_schedule_.push_back(wednesday);
    weekly_schedule_.push_back(thursday);
    weekly_schedule_.push_back(friday);
}

std::shared_ptr<Vet> Schedule::GetVet(unsigned short &month, unsigned short &day, std::string &clinic) const {
    for (auto const &daily_schedule : weekly_schedule_) {
        if (std::get<0>(daily_schedule).GetMonth() == month && std::get<0>(daily_schedule).GetDay() == day) {
            if (clinic == "Morning") {
                return std::get<2>(daily_schedule);
            }
            else if (clinic == "Afternoon") {
                return std::get<3>(daily_schedule);
            }
            else {
                return std::get<4>(daily_schedule);
            }
        }
    }
    return nullptr;
}

Date Schedule::GetDate(unsigned short &month, unsigned short &day) {
    for (auto const &daily_schedule : weekly_schedule_) {
        if (std::get<0>(daily_schedule).GetMonth() == month && std::get<0>(daily_schedule).GetDay() == day) {
            auto [date, clinic, vet1, vet2, vet3] = daily_schedule;
            return date;
        }
    }
    return Date();
}