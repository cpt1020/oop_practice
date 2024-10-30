#include "Dog.h"
using namespace std;

Dog::Dog(string name_val, string breeds_val, Date dob_val)
    : Animal(name_val, "Dog", breeds_val, dob_val) {
}

Dog::~Dog() {}

void Dog::say_something() const {
    cout << "Hello, I'm a dog and my name is " << get_name() << endl;
}