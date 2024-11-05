#ifndef _SCHEDULE_H_
#define _SCHEDULE_H_
#include <vector>
#include <tuple>
#include <string>
#include <memory>
#include "Date.h"
#include "Vet.h"

class Schedule {
    friend std::ostream &operator<<(std::ostream &os, const Schedule &obj);

private:
    std::vector<std::tuple<Date, std::string, std::shared_ptr<Vet>, std::shared_ptr<Vet>, std::shared_ptr<Vet>>> weekly_schedule_;

public:
    Schedule(std::vector<std::shared_ptr<Vet>> &vets);

    void InitializeSchedule(std::vector<std::shared_ptr<Vet>> &vets);
    std::shared_ptr<Vet> GetVet(unsigned short &month, unsigned short &day, std::string &clinic) const;
    Date GetDate(unsigned short &month, unsigned short &day);

};

#endif