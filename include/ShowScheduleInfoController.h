#ifndef _SHOWSCHEDULEINFOCONTROLLER_H_
#define _SHOWSCHEDULEINFOCONTROLLER_H_
#include <memory>
#include "Controller.h"
#include "Model.h"
#include "View.h"

class ShowScheduleInfoController : public Controller {
private:
    ShowScheduleInfoController(View &view_val, Model &model_val);
    ShowScheduleInfoController(const ShowScheduleInfoController &source) = delete;
    ShowScheduleInfoController &operator=(const ShowScheduleInfoController &source) = delete;
public:
    static std::unique_ptr<Controller> &CreateControllerPtr(View &view_val, Model &model_val) {
        static std::unique_ptr<Controller> controller_ptr {new ShowScheduleInfoController(view_val, model_val)};
        return controller_ptr;
    }
    virtual void Handle() override;
};

#endif