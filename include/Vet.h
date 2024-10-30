#ifndef _VET_H_
#define _VET_H_
#include <string>
#include <vector>
using namespace std;

class Vet {
private:
    string first_name;
    string last_name;

    const int specialty_num {7};
    const int species_num {3};
    vector<int> specialty;
    // Internal Medicine, Surgery, Oncology, Opthalamology, Neurology, Orthopedics, Cardiology
    vector<int> species;
    // dog, cat, exotic animal


public:

    Vet(string fname, string lname);

    string get_fname() const;
    string get_lname() const;
    string get_full_name() const;
    int get_species_num() const;
    int get_specialty_num() const;
    int get_species_score(int &idx) const;
    int get_specialty_score(int &idx) const;
    void set_specialty(vector<int> &&spec_vec);
    void set_species(vector<int> &&species_vec);

};

#endif