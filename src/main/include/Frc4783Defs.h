#ifndef DEFS_H_
#define DEFS_H_

namespace frc4783 {

typedef enum roboType {
    PROTOCASE,
    STEAMWORKS,
    POWERUP,
    DEEPSPACE
} robotType_e;

typedef enum motorControllerFunction {
    DriveLeftFront,
    DriveLeftRear,
    DriveRightFront,
    DriveRightRear,
    ElevatorLeft,
    ElevatorCentre,
    ElevatorRight,
    ManipulatorLeft,
    ManipulatorCentre,
    ManipulatorRight
} MotorControllerFunction_e;

typedef enum motorControllerGroups {
    DriveGroupLeft,
    DriveGroupRight,
    DriveGroupMax
} MotorControllerGroups_e;

typedef enum motorControllerType {
    VictorSP,
    VictorSPX,
    TalonSRX,
    Sparx,
    SparxMax
} MotorControllerType_e;

typedef enum signalType {
    PWM,
    CAN
} SignalType_e;

typedef enum solenoidType {
    Single,
    Double
} SolenoidType_e;

typedef enum driveTrainGearType {
    Low,
    High,
} DriveTrainGearType_e;

typedef enum controllerButtonType {
    Left_Button,
    Right_Button,
    Top_Button,
    Bottom_Button,
    Left_Bumper,
    Right_Bumper,
    Left_Trigger,
    Right_Trigger,
    Left_Stick,
    Right_Stick,
    FnLeft,
    FnRight,
    Centre,
    TouchPad,
    Button_Max,
} ControllerButtonType_e;

typedef enum controllerAxesType {
    Left_X_Axis,
    Left_Y_Axis,
    Right_X_Axis,
    Right_Y_Axis
} ControllerAxesType_e;

typedef enum joystickButtonAction {
    // Trigger actions
    WhenActive,
    WhileActive,
    WhenInactive,
    CancelWhenActive,
    ToggleWhenActive,
    // Button actions
    WhenPressed,
    WhileHeld,
    WhenReleased,
    CancelWhenPressed,
    ToggleWhenPressed
} JoystickButtonActions_e;

} // namespace frc4783

#endif 