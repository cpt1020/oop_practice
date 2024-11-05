#ifndef _VIEW_H_
#define _VIEW_H_
#include <string>
#include <vector>
#include <memory>
#include "Schedule.h"
#include "Reservation.h"
#include "Map.h"

class View {
public:
    void ClearTerminal() const;
    void CenteredOutput(const std::string &text) const;
    void DisplayMainMenu() const;
    void DisplayMessage(const std::string &message) const;
    void DisplaySchedule(const Schedule &schedule) const;
    void DisplayAppointment(const std::vector<std::shared_ptr<Reservation>> rsvn) const;
    void DisplayMap(const Map &map) const;
    void DisplayShortestPath(const std::vector<std::string> &shortest_path, const int &total_dist) const;
};


#endif