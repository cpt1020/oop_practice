#include "ExoticAnimal.h"
using namespace std;

ExoticAnimal::ExoticAnimal(string name_val, string breeds_val, Date dob_val)
    : Animal(name_val, "Exotic Animal", breeds_val, dob_val) {
}

ExoticAnimal::~ExoticAnimal() {}

void ExoticAnimal::say_something() const {
    cout << "Hello, I'm an exotic animal and my name is " << get_name() << endl;
}