#ifndef _SCHEDULE_H_
#define _SCHEDULE_H_
#include <vector>
#include <tuple>
#include <string>
#include "Date.h"
#include "Vet.h"
using namespace std;

class Schedule {
    friend ostream &operator<<(ostream &os, const Schedule &obj);

private:
    vector<tuple<Date, string, Vet*, Vet*, Vet*>> weekly_schedule;

public:
    Schedule(vector<Vet *> &vets);
    ~Schedule() {};

    void schedule_initialization(vector<Vet *> &vets);
    Vet* get_vet(unsigned short &month, unsigned short &day, string &clinic) const;
    Date get_date(unsigned short &month, unsigned short &day);

};

#endif