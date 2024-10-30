#include <iostream>
#include "Model.h"
#include "Controller.h"
#include "View.h"
using namespace std;

int main() {

    Model *model = new Model();
    Controller *controller = new Controller(model);

    return 0;
}