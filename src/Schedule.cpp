#include "Schedule.h"
#include "Vet.h"
#include <iostream>
#include <iomanip>
#include <tuple>
#include <vector>
using namespace std;

// Overload << operator
ostream &operator<<(ostream &os, const Schedule &obj) {
    os << "              " << get<0>(obj.weekly_schedule.at(0)).get_MMDD() << "      "
                           << get<0>(obj.weekly_schedule.at(1)).get_MMDD() << "      "
                           << get<0>(obj.weekly_schedule.at(2)).get_MMDD() << "      "
                           << get<0>(obj.weekly_schedule.at(3)).get_MMDD() << "      "
                           << get<0>(obj.weekly_schedule.at(4)).get_MMDD() << endl;
    os << "               Mon       Tue       Wed      Thurs      Fri    " << endl;
    os << "            --------- --------- --------- --------- --------- " << endl;
    os << "   Morning | " << get<2>(obj.weekly_schedule.at(0))->get_fname() << " |  " 
                          << get<2>(obj.weekly_schedule.at(1))->get_fname() << "   |  " 
                          << get<2>(obj.weekly_schedule.at(2))->get_fname() << "  |  " 
                          << get<2>(obj.weekly_schedule.at(3))->get_fname() << " |  "
                          << get<2>(obj.weekly_schedule.at(4))->get_fname() << "   |" << endl;
    os << "            --------- --------- --------- --------- --------- " << endl;
    os << " Afternoon |  " << get<3>(obj.weekly_schedule.at(0))->get_fname() << " |  " 
                           << get<3>(obj.weekly_schedule.at(1))->get_fname() << "   | " 
                           << get<3>(obj.weekly_schedule.at(2))->get_fname() << " |  " 
                           << get<3>(obj.weekly_schedule.at(3))->get_fname() << "   |  "
                           << get<3>(obj.weekly_schedule.at(4))->get_fname() << "  |" << endl;
    os << "            --------- --------- --------- --------- --------- " << endl;
    os << "   Evening |  " << get<4>(obj.weekly_schedule.at(0))->get_fname() << "   |  " 
                           << get<4>(obj.weekly_schedule.at(1))->get_fname() << "  |  " 
                           << get<4>(obj.weekly_schedule.at(2))->get_fname() << " |  " 
                           << get<4>(obj.weekly_schedule.at(3))->get_fname() << "   | "
                           << get<4>(obj.weekly_schedule.at(4))->get_fname() << " |" << endl;
    os << "            --------- --------- --------- --------- --------- " << endl;                                 
    return os;
}

Schedule::Schedule(vector<Vet *> &vets) {
    schedule_initialization(vets);
}

void Schedule::schedule_initialization(vector<Vet *> &vets) {

    tuple<Date, string, Vet*, Vet*, Vet*> monday {Date {2023, 11, 6}, "Monday", vets.at(0), vets.at(3), vets.at(1)};
    tuple<Date, string, Vet*, Vet*, Vet*> tuesday {Date {2023, 11, 7}, "Tuesday", vets.at(1), vets.at(4), vets.at(2)};
    tuple<Date, string, Vet*, Vet*, Vet*> wednesday {Date {2023, 11, 8}, "Wednesday", vets.at(2), vets.at(0), vets.at(3)};
    tuple<Date, string, Vet*, Vet*, Vet*> thursday {Date {2023, 11, 9}, "Thursday", vets.at(3), vets.at(1), vets.at(4)};
    tuple<Date, string, Vet*, Vet*, Vet*> friday {Date {2023, 11, 10}, "Friday", vets.at(4), vets.at(2), vets.at(0)};

    weekly_schedule.push_back(monday);
    weekly_schedule.push_back(tuesday);
    weekly_schedule.push_back(wednesday);
    weekly_schedule.push_back(thursday);
    weekly_schedule.push_back(friday);
}

Vet* Schedule::get_vet(unsigned short &month, unsigned short &day, string &clinic) const {
    for (auto const &daily_schedule : weekly_schedule) {
        if (get<0>(daily_schedule).get_month() == month && get<0>(daily_schedule).get_day() == day) {
            if (clinic == "Morning") {
                return get<2>(daily_schedule);
            }
            else if (clinic == "Afternoon") {
                return get<3>(daily_schedule);
            }
            else {
                return get<4>(daily_schedule);
            }
        }
    }
    return nullptr;
}

Date Schedule::get_date(unsigned short &month, unsigned short &day) {
    for (auto const &daily_schedule : weekly_schedule) {
        if (get<0>(daily_schedule).get_month() == month && get<0>(daily_schedule).get_day() == day) {
            // return &get<0>(daily_schedule);
            auto [d, c, v1, v2, v3] = daily_schedule;
            return d;
        }
    }
    return Date();
}