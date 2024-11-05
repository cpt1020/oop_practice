#ifndef _SHOWAPPOINTMENTCONTROLLER_H_
#define _SHOWAPPOINTMENTCONTROLLER_H_
#include <memory>
#include "Controller.h"
#include "Model.h"
#include "View.h"

class ShowAppointmentController : public Controller {
private:
    ShowAppointmentController(View &view_val, Model &model_val);
    ShowAppointmentController(const ShowAppointmentController &source) = delete;
    ShowAppointmentController &operator=(const ShowAppointmentController &source) = delete;
public:
    static std::unique_ptr<Controller> &CreateControllerPtr(View &view_val, Model &model_val) {
        static std::unique_ptr<Controller> controller_ptr {new ShowAppointmentController(view_val, model_val)};
        return controller_ptr;
    }
    virtual void Handle() override;
};

#endif