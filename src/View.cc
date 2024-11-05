#include "View.h"
#include "Reservation.h"
#include "Schedule.h"
#include "Map.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

void View::ClearTerminal() const {
    system("clear");
}

void View::CenteredOutput(const std::string &text) const {
    int terminal_width {80};
    int padding {static_cast<int>((terminal_width - text.size())/2)};

    for (int i {0}; i < padding; ++i) {
        std::cout << " ";
    }
    std::cout << text << std::endl;
}

void View::DisplayMainMenu() const {
    ClearTerminal();
    std::cout << "\n\n";
    CenteredOutput("Welcome to HAPPY Veterinary Hospital!");
    std::cout << "\n";
    std::cout << "Please press the number of the item you want then press Enter" << std::endl;
    std::cout << "[1] Register Yourself" << std::endl;
    std::cout << "[2] Register Your Animal" << std::endl;
    std::cout << "[3] Show Registered Animal" << std::endl;
    std::cout << "[4] Our Vets" << std::endl;
    std::cout << "[5] Outpatient Schedule" << std::endl;
    std::cout << "[6] Vet Recommendation" << std::endl;
    std::cout << "[7] Make an Appointment" << std::endl;
    std::cout << "[8] Show Your Appointment" << std::endl;
    std::cout << "[9] Route to Our Hospital" << std::endl;
    std::cout << "[0] Exit" << std::endl;
}

void View::DisplayMessage(const std::string &message) const {
    std::cout << message << std::endl;
}

void View::DisplaySchedule(const Schedule &schedule) const {
    std::cout << schedule << std::endl;
}

void View::DisplayAppointment(const std::vector<std::shared_ptr<Reservation>> rsvn) const {
    for (int i {0}; i < rsvn.size(); ++i) {
        std::cout << "[" << i + 1 << "] " << *(rsvn.at(i)) << std::endl;
    }
}

void View::DisplayMap(const Map &map) const {
    std::cout << map << std::endl;
}

void View::DisplayShortestPath(const std::vector<std::string> &shortest_path, const int &total_dist) const {
    std::cout << "\nThe recommended route to our hospital is: ";

    for (int i {0}; i < shortest_path.size(); ++i) {
        std::cout << shortest_path.at(i) << ((i == shortest_path.size() - 1) ? "\n" : " -> ");
    }

    std::cout << "Total distance: " << total_dist << " meters" << std::endl;
}