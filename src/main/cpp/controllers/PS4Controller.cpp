#include "controllers/PS4Controller.hpp"

namespace frc4783 {

PS4Controller::PS4Controller(int id) : FrcController(id) {

    // allocate frc::JoystickButton objects
    m_buttons[frc4783::Left_Button] = new frc2::JoystickButton(m_driveStick.get(), buttonSquareId);
    m_buttons[frc4783::Right_Button] = new frc2::JoystickButton(m_driveStick.get(), buttonCircleId);
    m_buttons[frc4783::Bottom_Button] = new frc2::JoystickButton(m_driveStick.get(), buttonXId);
    m_buttons[frc4783::Top_Button] = new frc2::JoystickButton(m_driveStick.get(), buttonTriangleId);
    m_buttons[frc4783::FnLeft] = new frc2::JoystickButton(m_driveStick.get(), buttonShareId);
    m_buttons[frc4783::FnRight] = new frc2::JoystickButton(m_driveStick.get(), buttonOptionId);
    m_buttons[frc4783::Centre] = new frc2::JoystickButton(m_driveStick.get(), buttonPs4Id);
    
    m_buttons[frc4783::Left_Bumper] = new frc2::JoystickButton(m_driveStick.get(), buttonLeftBumperId);
    m_buttons[frc4783::Right_Bumper] = new frc2::JoystickButton(m_driveStick.get(), buttonRightBumperId);
    m_buttons[frc4783::Left_Trigger] = new frc2::JoystickButton(m_driveStick.get(), buttonLeftTriggerId);
    m_buttons[frc4783::Right_Trigger] = new frc2::JoystickButton(m_driveStick.get(), buttonRightTriggerId);
    m_buttons[frc4783::Left_Stick] = new frc2::JoystickButton(m_driveStick.get(), buttonLeftStickId);
    m_buttons[frc4783::Right_Stick] = new frc2::JoystickButton(m_driveStick.get(), buttonRightStickId);
    m_buttons[frc4783::TouchPad] = new frc2::JoystickButton(m_driveStick.get(), buttonPadId);
}

PS4Controller::~PS4Controller() {
}

int PS4Controller::mapAxes(ControllerAxesType_e id) {
    int ret = 0;
    switch(id) {
        case Left_X_Axis: ret = leftXAxisId; break;
        case Left_Y_Axis: ret = leftYAxisId; break;
        case Right_X_Axis: ret = rightXAxisId; break;
        case Right_Y_Axis: ret = rightYAxisId; break;
    }
    return ret;
}

int PS4Controller::mapButton(ControllerButtonType_e id) {
    switch (id) {
        case Left_Button: return buttonSquareId;
        case Right_Button: return buttonCircleId;
        case Top_Button: return buttonTriangleId;
        case Bottom_Button: return buttonXId;
        case Left_Bumper: return buttonLeftBumperId;
        case Right_Bumper: return buttonRightBumperId;
        case Left_Trigger: buttonLeftTriggerId;
        case Right_Trigger: buttonRightTriggerId;
        case Left_Stick: return buttonLeftStickId;
        case Right_Stick: return buttonRightStickId;
        case FnLeft: return buttonShareId;
        case FnRight: return buttonOptionId;
        case Centre: return buttonPs4Id;
        case TouchPad: return buttonPadId;
        case Button_Max:
        default:
            return 0;
    }
    return 0;
}

} // namespace 4783