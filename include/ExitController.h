#ifndef _EXITCONTROLLER_H_
#define _EXITCONTROLLER_H_
#include <memory>
#include "Controller.h"
#include "Model.h"
#include "View.h"

class ExitController : public Controller {
private:
    ExitController(View &view_val, Model &model_val);
    ExitController(const ExitController &source) = delete;
    ExitController &operator=(const ExitController &source) = delete;
public:
    static std::unique_ptr<Controller> &CreateControllerPtr(View &view_val, Model &model_val) {
        static std::unique_ptr<Controller> controller_ptr {new ExitController(view_val, model_val)};
        return controller_ptr;
    }
    virtual void Handle() override;
};

#endif