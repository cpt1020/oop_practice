#ifndef _VETRECOMMENDATIONCONTROLLER_H_
#define _VETRECOMMENDATIONCONTROLLER_H_
#include <memory>
#include "Controller.h"
#include "Model.h"
#include "View.h"

class VetRecommendationController : public Controller {
private:
    VetRecommendationController(View &view_val, Model &model_val);
    VetRecommendationController(const VetRecommendationController &source) = delete;
    VetRecommendationController &operator=(const VetRecommendationController &source) = delete;
public:
    static std::unique_ptr<Controller> &CreateControllerPtr(View &view_val, Model &model_val) {
        static std::unique_ptr<Controller> controller_ptr {new VetRecommendationController(view_val, model_val)};
        return controller_ptr;
    }
    virtual void Handle() override;
};

#endif