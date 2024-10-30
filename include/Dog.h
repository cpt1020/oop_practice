#ifndef _DOG_H_
#define _DOG_H_
#include <string>
#include "Animal.h"
#include "Date.h"
using namespace std;

class Dog: public Animal {

public:

    Dog(string name_val, string breeds_val, Date dob_val);
    virtual ~Dog();
    virtual void say_something() const override;

};

#endif