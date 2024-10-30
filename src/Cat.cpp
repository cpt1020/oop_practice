#include "Cat.h"
using namespace std;

Cat::Cat(string name_val, string breeds_val, Date dob_val)
    : Animal(name_val, "Cat", breeds_val, dob_val) {
}

Cat::~Cat() {}

void Cat::say_something() const {
    cout << "Hello, I'm a cat and my name is " << get_name() << endl;
}