#include "Controller/MainController.h"
#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>

namespace frc4783 {

MainController::MainController(int ControllerId) :
    m_id(ControllerId) {
    m_driveStick.reset(new frc::Joystick (ControllerId));

}

MainController::~MainController() {
        for(int i = 0; i < frc4783::Button_Max; ++i) {
        if (m_buttons[i] != nullptr) {
            delete m_buttons[i];
        }
    }
}

double MainController::getRawAxis(int id) {
    double ret = 0.0;
    if (m_driveStick != nullptr) {
        ret = m_driveStick->GetRawAxis(mapAxes(id));
    }
    return ret;
}

}
//namespace 4783

