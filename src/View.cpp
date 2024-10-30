#include "View.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

View::View(Model *model_ptr, Controller *controller_ptr)
    : model {model_ptr}, controller {controller_ptr} {}

void centered_output(const string &text) {
    int terminal_width {80};
    int padding {static_cast<int>((terminal_width - text.size())/2)};

    for (int i {0}; i < padding; ++i) {
        cout << " ";
    }
    cout << text << endl;
}

void View::clear_terminal() const {
    system("clear");
}

void View::display_start() const {
    clear_terminal();
    cout << "\n\n\n";
    centered_output("Welcome to HAPPY Veterinary Hospital!");
    centered_output("Please first register so you can make reservation");
    cout << "\n\n\n";
}

void View::display_menu() const {
    cout << "Please press the number of the item you want then press Enter" << endl;
    cout << "[1] Register Your Animal" << endl;
    cout << "[2] Show Registered Animal" << endl;
    cout << "[3] Our Vets" << endl;
    cout << "[4] Outpatient Schedule" << endl;
    cout << "[5] Vet Recommendation" << endl;
    cout << "[6] Make an Appointment" << endl;
    cout << "[7] Show Your Appointment" << endl;
    cout << "[8] Route to Our Hospital" << endl;
    cout << "[0] Exit" << endl;
}

void retrieve_dob(unsigned short &year, unsigned short &month, unsigned short &day) {
    string inputDate;
    cout << "Please enter the date of birth in this format MM/DD/YYYY:\n";
    cin >> inputDate;

    istringstream dateStream(inputDate);
    char delimiter;
    dateStream >> month >> delimiter >> day >> delimiter >> year;

    if (dateStream.fail() || delimiter != '/' || dateStream.peek() != EOF) {
        cerr << "Invalid format of date of birth" << endl;
    }
}

void View::user_register(bool &registered) {

    string fname {""};
    cout << "Please enter your first name:\n";
    getline(cin, fname);

    string lname {""};
    cout << "Please enter your last name:\n";
    getline(cin, lname);

    unsigned short month {0}, day {0}, year {0};
    retrieve_dob(year, month, day);

    string mobile {""};
    cout << "Please enter you mobile number:\n";
    getline(cin, mobile);
    clear_terminal();

    char rd;
    int house_num {0};
    controller->show_map();
    cout << "\nThis is the map of the city where our animal hospital is located." << endl;
    cout << "Please enter the alphabet corresponding to the road/street you live in and your house number, separated by a space." << endl;
    cout << "For example, for 100 North Ave., just enter '100 j'.\n";
    cin >> house_num >> rd;
    while (controller->verify_input(rd, house_num) == false) {
        cout << "Invalid input. Please enter again" << endl;
        cin >> house_num >> rd;
        cin.ignore();
    }

    if (controller->user_register(fname, lname, year, month, day, mobile, rd, house_num) == true) {
        clear_terminal();
        cout << "Congrats! You've successfully registered!\nNext, please register your animal\n";
        registered = true;
    }
    else {
        cout << "Registration failed. Please register again\n";
    }
    cin.ignore();
}

void View::animal_register(bool &animal_registered) {

    string name {""};
    cout << "Please enter the name of your animal:\n";
    getline(cin, name);

    int species {0};
    cout << "Please enter the number of your animal species, [1] Canine, [2] Feline, [3] Exotic Animal:\n";
    cin >> species;
    cin.ignore();

    string breeds {""};
    cout << "Please enter the breeds of your animal (Mongrel for mixed-breed, N/A for not applicable):\n";
    getline(cin, breeds);    

    unsigned short month {0}, day {0}, year {0};
    retrieve_dob(year, month, day);

    if (controller->animal_register(name, species, breeds, year, month, day) == true) {
        clear_terminal();
        cout << "You've successfully registered your animal " << name << "!\n\n";
        animal_registered = true;
    }
    else {
        clear_terminal();
        cout << "Registration failed. Please register again.\n";
    }
}

void View::show_registered_animal() const {
    model->show_animals();
}

void View::show_schedule() const {
    controller->show_schedule();
}

void View::show_vet_info() const {
    controller->show_vet_info();
}

void View::vet_recommendation() const {
    cout << "Not sure which vet to make an appointment with?" << endl;
    cout << "Then, you're in the right place!\nThis feature will find out the most suitable vet for you based on your animal's specis and it's problem!" << endl;

    int species {0};
    cout << "\nFirst, please enter the number corresponding to your animal's species, [1] Canine, [2] Feline, [3] Exotic Animal:\n";
    cin >> species;
    cin.ignore();

    vector<int> problem_num;
    string user_input;
    cout << "Next, please enter the numbers corresponding to your animal's issues, separated by spaces:\n";
    cout << "[1] Internal Medicine (including gastroenteral issues, etc)\n[2] Surgery\n[3] Oncology\n[4] Ophthalmology\n[5] Neurology\n[6] Orthopedics\n[7] Cardiology\n";
    getline(cin, user_input);
    istringstream inputStream(user_input);
    int num;

    while (inputStream >> num) {
        problem_num.push_back(num);
    }

    string recommended_vet {controller->recommend_vet(species, problem_num)};
    cout << "\nAccording to our algorithm, Dr. " << recommended_vet << " is our top choice for you!" << endl;
}

void View::shortest_path_to_hospital() const {
    controller->shortest_path_to_hospital();
}

void View::making_appointment() const {
    bool confirmed {false};
    unsigned short month {0}, day {0};
    string rsvn_clinic {""};
    string animal_name {""};

    while (confirmed == false) {
        show_schedule();

        string input_date {""};
        cout << "\nPlease enter the appointment date you prefer (e.g., '11/6'):\n";
        cin >> input_date;
        istringstream dateStream(input_date);
        char delimiter;
        dateStream >> month >> delimiter >> day;
        
        cout << "Please enter your preferred appointment time (e.g., 'Morning,' 'Afternoon,' 'Evening'):\n";
        cin >> rsvn_clinic;

        cout << "Please enter the animal name for this appointment:\n";
        show_registered_animal();
        cin.ignore();
        getline(cin, animal_name);

        while (controller->check_animal_name(animal_name) == false) {
            cout << "This animal has'nt been registered. Please enter registered animal name:\n";
            getline(cin, animal_name);
        }

        char input;
        cout << "\nPlease confirm your appointment information (y/n):\n";
        cout << "[Date] " << month << "/" << day << " " << rsvn_clinic << " clinic\n";
        cout << "[Animal name] " << animal_name << endl;
        cin >> input;

        if (input == 'Y' || input == 'y') {
            confirmed = true;
        }
        else {
            clear_terminal();
        }
    }

    if (controller->making_appointment(month, day, rsvn_clinic, animal_name)) {
        cout << "\nYou've successfully scheduled a " << rsvn_clinic << " appointment on " << month << "/" << day << " for " << animal_name << "!" << endl;
    }
    else {
        cout << "\nAppointment unsuccessful, please try again." << endl;
    }
}

void View::show_appointment() const {
    controller->show_appointment();
}

void View::run() {
    display_start();

    // user register
    bool registered {false};
    while (registered == false) {
        user_register(registered);
    }

    // register first animal
    bool animal_registered {false};
    while (animal_registered == false) {
        animal_register(animal_registered);
    }

    int input {0};
    display_menu();
    while (cin >> input) {
        cin.ignore();
        clear_terminal();
        switch (input) {
            case 1:
                // Register Your Animal
                animal_register(animal_registered);
                break;
            case 2:
                // Show Registered Animal
                show_registered_animal();
                break;
            case 3:
                // Our Vets
                show_vet_info();
                break;
            case 4:
                // Outpatient Schedule
                show_schedule();
                break;
            case 5:
                // Vet Recommendation
                vet_recommendation();
                break;
            case 6:
                // Make an Appointment
                making_appointment();
                cin.ignore();
                break;
            case 7:
                // Show Your Appointment
                show_appointment();
                break;
            case 8:
                // Route to Our Hospital
                shortest_path_to_hospital();
                break;
            case 0:
                // clear_terminal();
                cout << "\n\n\n\n";
                centered_output("~Thanks for your visiting~");
                centered_output("We wish you and your animals safe and sound :)");
                cout << "\n\n\n\n";
                goto stop;
            default:
                cout << "Invalid input, please enter again" << endl;
                break;
        }

        cout << "\nPress enter to back to main menu" << endl;
        cin.ignore();
        clear_terminal();
        display_menu();
    }

    stop: return;
}




/*
    while (cin >> input) {
        clear_terminal();

        if (input == 1) {
            display_menu();
        }
        else if (input == 2) {
            show_registered_animal();
        }
        else if (input == 3) {
            show_vet_info();
        }
        else if (input == 4) {
            show_schedule();
        }
        else if (input == 5) {
            vet_recommendation();
        }
        else if (input == 6) {
            making_appointment();
        }
        else if (input == 7) {
            show_appointment();
        }
        else if (input == 8) {
            shortest_path_to_hospital();
        }
        else if (input == 0) {
            cout << "\n\n\n\n";
            centered_output("~Thanks for your visiting~");
            centered_output("We wish you and your animals safe and sound :)");
            cout << "\n\n\n\n";
            goto stop;
        }
        else {
            cout << "Invalid input, please enter again" << endl;
        }

        cout << "Press enter to back to main menu" << endl;
        cin.ignore();
        clear_terminal();
        display_menu();
    }
*/