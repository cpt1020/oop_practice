#ifndef _USERREGISTRATIONCONTROLLER_H_
#define _USERREGISTRATIONCONTROLLER_H_
#include <memory>
#include "Controller.h"
#include "Model.h"
#include "View.h"

class UserRegistrationController : public Controller {
private:
    UserRegistrationController(View &view_val, Model &model_val);
    UserRegistrationController(const UserRegistrationController &source) = delete;
    UserRegistrationController &operator=(const UserRegistrationController &source) = delete;
public:
    static std::unique_ptr<Controller> &CreateControllerPtr(View &view_val, Model &model_val) {
        static std::unique_ptr<Controller> controller_ptr {new UserRegistrationController(view_val, model_val)};
        return controller_ptr;
    }

    bool VerifyAddrInput(char &road, int &num);
    virtual void Handle() override;

};

#endif