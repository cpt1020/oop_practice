#ifndef _APPOINTMENTMAKINGCONTROLLER_H_
#define _APPOINTMENTMAKINGCONTROLLER_H_
#include <memory>
#include "Controller.h"
#include "Model.h"
#include "View.h"

class AppointmentMakingController : public Controller {
private:
    AppointmentMakingController(View &view_val, Model &model_val);
    AppointmentMakingController(const AppointmentMakingController &source) = delete;
    AppointmentMakingController &operator=(const AppointmentMakingController &source) = delete;
public:
    static std::unique_ptr<Controller> &CreateControllerPtr(View &view_val, Model &model_val) {
        static std::unique_ptr<Controller> controller_ptr {new AppointmentMakingController(view_val, model_val)};
        return controller_ptr;
    }
    virtual void Handle() override;
};

#endif