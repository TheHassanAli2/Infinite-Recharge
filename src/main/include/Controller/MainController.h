#pragma once
#include <map>
#include <memory>
#include "Frc4783Defs.h"
#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>

namespace frc4783 {

class MainController {

public:
    MainController(int ControllerId);
    virtual ~MainController();
    double getRawAxis(ControllerAxesType_e id);  
    bool getRawButton(ControllerButtonType_e id);
    int addCommand(ControllerButtonType_e button, JoystickButtonActions_e action, frc2::Command * command);

protected:
    virtual int mapAxes(ControllerAxesType_e id) = 0; 
    virtual int mapButton(ControllerButtonType_e id) = 0;

    int m_id;

    std::shared_ptr<frc::Joystick> m_driveStick;

    frc2::JoystickButton *m_buttons[Button_Max] = {0};

};

} // namespace frc4783

