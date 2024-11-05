#ifndef _SHOWREGISTEREDANIMALCONTROLLER_H_
#define _SHOWREGISTEREDANIMALCONTROLLER_H_
#include <memory>
#include "Controller.h"
#include "Model.h"
#include "View.h"

class ShowRegisteredAnimalController : public Controller {
private:
    ShowRegisteredAnimalController(View &view_val, Model &model_val);
    ShowRegisteredAnimalController(const ShowRegisteredAnimalController &source) = delete;
    ShowRegisteredAnimalController &operator=(const ShowRegisteredAnimalController &source) = delete;
public:
    static std::unique_ptr<Controller> &CreateControllerPtr(View &view_val, Model &model_val) {
        static std::unique_ptr<Controller> controller_ptr {new ShowRegisteredAnimalController(view_val, model_val)};
        return controller_ptr;
    }

    virtual void Handle() override;
};

#endif