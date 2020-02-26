#pragma once

#include <map>
#include <memory>

#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/Command.h>

#include "Frc4783Defs.h"

namespace frc4783 {

class FrcController {

public:

    /**
     * constructor
     * @param  id  controller id
     */
    FrcController(int id);
    virtual ~FrcController();

    double getRawAxis(ControllerAxesType_e id);
    bool getRawButton(ControllerButtonType_e id);

    /**
     * Add frc::Command to frc::JoystickButton object
     * 
     * @param button  indicates the controller button associated with the command
     * @param action  indicates which JoystickButton action is associated with the command
     * @param command  ptr to frc::Command object
     */
    int addCommand(ControllerButtonType_e button, JoystickButtonActions_e action, frc2::Command *command);

protected:

    /**
     *  Map ControllerAxesType_e to axis id (based on driver station)
     * 
     * @param id  ControllerAxesType_e enum indicating axis
     */
    virtual int mapAxes(ControllerAxesType_e id) = 0;

    /**
     *  Map ControllerButtonType_e to button id (based on driver station)
     * 
     * @param id  ControllerButtonType_e enum indicating button
     */
    virtual int mapButton(ControllerButtonType_e id) = 0;

    /**
     * Joystick USB id (based on driver station)
     */
    int m_id;

    std::shared_ptr<frc::Joystick> m_driveStick;

    /**
     *  array of frc::JoystickButton ptrs
     *  indexed by ControllerButtonType_e
     */
    frc2::JoystickButton *m_buttons[frc4783::Button_Max] = {0};
};

} // namespace frc4783
