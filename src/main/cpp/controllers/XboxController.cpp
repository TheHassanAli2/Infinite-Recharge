#include "controllers/XboxController.hpp"

namespace frc4783 {

XboxController::XboxController(int id) : FrcController(id) {

    // allocate frc::JoystickButton objects
    m_buttons[frc4783::Bottom_Button] = new frc2::JoystickButton(m_driveStick.get(), buttonAId);
    m_buttons[frc4783::Right_Button] = new frc2::JoystickButton(m_driveStick.get(), buttonBId);
    m_buttons[frc4783::Left_Button] = new frc2::JoystickButton(m_driveStick.get(), buttonXId);
    m_buttons[frc4783::Top_Button] = new frc2::JoystickButton(m_driveStick.get(), buttonYId);
    m_buttons[frc4783::FnLeft] = new frc2::JoystickButton(m_driveStick.get(), buttonBackId);
    m_buttons[frc4783::FnRight] = new frc2::JoystickButton(m_driveStick.get(), buttonStartId);

    m_buttons[frc4783::Left_Bumper] = new frc2::JoystickButton(m_driveStick.get(), buttonLeftBumperId);
    m_buttons[frc4783::Right_Bumper] = new frc2::JoystickButton(m_driveStick.get(), buttonRightBumperId);
    m_buttons[frc4783::Left_Stick] = new frc2::JoystickButton(m_driveStick.get(), buttonLeftStickId);
    m_buttons[frc4783::Right_Stick] = new frc2::JoystickButton(m_driveStick.get(), buttonRightStickId);
}

XboxController::~XboxController() {
}

int XboxController::mapAxes(ControllerAxesType_e id) {
    int ret = 0;
    switch(id) {
        case Left_X_Axis: ret = leftXAxisId; break;
        case Left_Y_Axis: ret = leftYAxisId; break;
        case Right_X_Axis: ret = rightXAxisId; break;
        case Right_Y_Axis: ret = rightYAxisId; break;
    }
    return ret;
}

int XboxController::mapButton(ControllerButtonType_e id) {
    switch (id) {
        case Left_Button: return buttonXId;
        case Right_Button: return buttonBId;
        case Top_Button: return buttonYId;
        case Bottom_Button: return buttonAId;
        case Left_Bumper: return buttonLeftBumperId;
        case Right_Bumper: return buttonRightBumperId;
        case Left_Stick: return buttonLeftStickId;
        case Right_Stick: return buttonRightStickId;
        case FnLeft: return buttonBackId;
        case FnRight: return buttonStartId;
        case Left_Trigger: 
        case Right_Trigger:
        case Centre:
        case TouchPad:
        case Button_Max:
        default:
            return 0;
    }
    return 0;
}

}  // namespace frc4783
