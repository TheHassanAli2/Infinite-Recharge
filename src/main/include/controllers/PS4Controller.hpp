#pragma once

#include "controllers/FrcController.hpp"

namespace frc4783 {

class PS4Controller : public frc4783::FrcController {

public:

    /**
     * constructor
     * @param  id  controller id
     */
    PS4Controller(int id);

    virtual ~PS4Controller();

protected:

    int mapAxes(ControllerAxesType_e id) override;
    int mapButton(ControllerButtonType_e id) override;

    enum buttonId {
        buttonSquareId = 1,
        buttonXId = 2,
        buttonCircleId = 3,
        buttonTriangleId = 4,
        buttonLeftBumperId =5,
        buttonRightBumperId = 6,
        buttonLeftTriggerId = 7,
        buttonRightTriggerId = 8,
        buttonShareId = 9,
        buttonOptionId = 10,
        buttonLeftStickId = 11,
        buttonRightStickId = 12,
        buttonPs4Id = 13,
        buttonPadId = 14
    };

    enum axisId {
        leftXAxisId = 0,
        leftYAxisId = 1,
        rightXAxisId = 2,
        rightYAxisId  =5
    };
};

} // namespace frc4783
