#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_
#include "Model.h"
#include "View.h"

class Controller {
protected:
    Model &model_;
    View &view_;

public:
    Controller(View &view_val, Model &model_val);
    virtual ~Controller() = default;
    virtual void Handle() = 0;
    bool CheckUserRegistered();
    void GetDOB(unsigned short &year, unsigned short &month, unsigned short &day);

};

#endif