#ifndef _EXOTICANIMAL_H_
#define _EXOTICANIMAL_H_
#include <string>
#include "Animal.h"
#include "Date.h"
using namespace std;

class ExoticAnimal: public Animal {

public:

    ExoticAnimal(string name_val, string breeds_val, Date dob_val);
    virtual ~ExoticAnimal();
    virtual void say_something() const override;

};

#endif