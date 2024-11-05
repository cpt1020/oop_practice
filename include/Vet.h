#ifndef _VET_H_
#define _VET_H_
#include <string>
#include <vector>
using namespace std;

class Vet {
private:
    std::string first_name_;
    std::string last_name_;

    const int kSpecialtyNum_ {7};
    std::vector<int> specialty_; // Internal Medicine, Surgery, Oncology, Opthalamology, Neurology, Orthopedics, Cardiology
    
    const int kSpeciesNum_ {3};
    std::vector<int> species_; // dog, cat, exotic animal
    
public:
    Vet(std::string fname, std::string lname);

    std::string GetFirstName() const;
    std::string GetLastName() const;
    std::string GetFullName() const;
    int GetSpeciesNum() const;
    int GetSpecialtyNum() const;
    int GetSpeciesScore(int &idx) const;
    int GetSpecialtyScore(int &idx) const;
    void SetSpecialty(std::vector<int> &&spec_vec);
    void SetSpecies(std::vector<int> &&species_vec);
};

#endif