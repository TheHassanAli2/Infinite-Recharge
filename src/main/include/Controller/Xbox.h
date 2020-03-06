#pragma once 
#include "Controller/MainController.h"

namespace frc4783{

class XboxController:
    public frc4783::MainController {

public:
    XboxController(int id);
    virtual ~XboxController();

protected:
    int mapAxes(ControllerAxesType_e id) override;
    int mapButton(ControllerButtonType_e id) override;

 enum buttonId {
        buttonAId = 1,
        buttonBId = 2,
        buttonXId = 3,
        buttonYId = 4,
        buttonLeftBumperId = 5,
        buttonRightBumperId = 6,
        buttonBackId = 7,
        buttonStartId = 8,
        buttonLeftStickId = 9,
        buttonRightStickId = 10
    };

    enum axisId {
        leftXAxisId = 0,
        leftYAxisId = 1,
        leftTriggerAxisId = 2,
        rightTriggerAxisId = 3,
        rightXAxisId = 4,
        rightYAxisId = 5
    };
};

} // namespace 4783