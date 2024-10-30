#ifndef _CAT_H_
#define _CAT_H_
#include <string>
#include "Animal.h"
#include "Date.h"
using namespace std;

class Cat: public Animal {

public:

    Cat(string name_val, string breeds_val, Date dob_val);
    virtual ~Cat();
    virtual void say_something() const override;

};

#endif