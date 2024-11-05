#ifndef _SHOWROUTECONTROLLER_H_
#define _SHOWROUTECONTROLLER_H_
#include <memory>
#include "Controller.h"
#include "Model.h"
#include "View.h"

class ShowRouteController : public Controller {
private:
    ShowRouteController(View &view_val, Model &model_val);
    ShowRouteController(const ShowRouteController &source) = delete;
    ShowRouteController &operator=(const ShowRouteController &source) = delete;
public:
    static std::unique_ptr<Controller> &CreateControllerPtr(View &view_val, Model &model_val) {
        static std::unique_ptr<Controller> controller_ptr {new ShowRouteController(view_val, model_val)};
        return controller_ptr;
    }
    virtual void Handle() override;
};

#endif