#ifndef _ANIMALREGISTRATIONCONTROLLER_H_
#define _ANIMALREGISTRATIONCONTROLLER_H_
#include <memory>
#include "Controller.h"
#include "Model.h"
#include "View.h"

class AnimalRegistrationController : public Controller {
private:
    AnimalRegistrationController(View &view_val, Model &model_val);
    AnimalRegistrationController(const AnimalRegistrationController &source) = delete;
    AnimalRegistrationController &operator=(const AnimalRegistrationController &source) = delete;
public:
    static std::unique_ptr<Controller> &CreateControllerPtr(View &view_val, Model &model_val) {
        static std::unique_ptr<Controller> controller_ptr {new AnimalRegistrationController(view_val, model_val)};
        return controller_ptr;
    }
    virtual void Handle() override;
};

#endif