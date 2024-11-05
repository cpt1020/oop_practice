#ifndef _MAINMENUCONTROLLER_H_
#define _MAINMENUCONTROLLER_H_
#include <memory>
#include <unordered_map>
#include "Controller.h"
#include "Model.h"
#include "View.h"

class MainMenuController : public Controller {
private:
    std::unordered_map<int, std::unique_ptr<Controller>> controller_ptrs_;
    MainMenuController(View &view_val, Model &model_val);
    MainMenuController(const MainMenuController &source) = delete;
    MainMenuController &operator=(const MainMenuController &source) = delete;
public:
    static std::unique_ptr<Controller> &CreateControllerPtr(View &view_val, Model &model_val) {
        static std::unique_ptr<Controller> controller_ptr {new MainMenuController(view_val, model_val)};
        return controller_ptr;
    }
    int GetUserChoice();
    virtual void Handle() override;
};

#endif