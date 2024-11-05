#ifndef _SHOWVETINFOCONTROLLER_H_
#define _SHOWVETINFOCONTROLLER_H_
#include <memory>
#include "Controller.h"
#include "Model.h"
#include "View.h"

class ShowVetInfoController : public Controller {
private:
    ShowVetInfoController(View &view_val, Model &model_val);
    ShowVetInfoController(const ShowVetInfoController &source) = delete;
    ShowVetInfoController &operator=(const ShowVetInfoController &source) = delete;
public:
    static std::unique_ptr<Controller> &CreateControllerPtr(View &view_val, Model &model_val) {
        static std::unique_ptr<Controller> controller_ptr {new ShowVetInfoController(view_val, model_val)};
        return controller_ptr;
    }
    virtual void Handle() override;
};

#endif