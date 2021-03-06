/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#ifndef ROBOTCONTAINER_H
#define ROBOTCONTAINER_H

#include <frc/Joystick.h>
#include <frc/buttons/JoystickButton.h>
#include <frc2/command/Command.h>
#include <subsystems/DriveTrain.h>

#include <frc/controller/PIDController.h>
#include <frc/controller/RamseteController.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/RamseteCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/button/JoystickButton.h>

#include <frc/Filesystem.h>
#include <wpi/Path.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <wpi/SmallString.h>

#include "Constants.h"


/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */

namespace frc4783 {
class RobotContainer {
public:
    RobotContainer();
    frc2::Command* GetAutonomousCommand();

    frc::Joystick xbox{0};
    frc::Joystick ps4{1};

    // Drive Stick Buttons
    frc::JoystickButton *aButtonS;
    frc::JoystickButton *bButtonS;
    frc::JoystickButton *xButtonS;
    frc::JoystickButton *yButtonS;
    frc::JoystickButton *leftBumperButtonS;
    frc::JoystickButton *rightBumperButtonS;
    frc::JoystickButton *selectButtonS;
    frc::JoystickButton *startButtonS;
    frc::JoystickButton *leftStickButtonS;
    frc::JoystickButton *rightStickButtonS;
    frc::JoystickButton *leftTriggerButtonS;
    frc::JoystickButton *rightTriggerButtonS;
    frc::JoystickButton *homeButtonS;
    frc::JoystickButton *touchpadButtonS;

    frc::JoystickButton *aButtonP;
    frc::JoystickButton *bButtonP;
    frc::JoystickButton *xButtonP;
    frc::JoystickButton *yButtonP;
    frc::JoystickButton *leftBumperButtonP;
    frc::JoystickButton *rightBumperButtonP;
    frc::JoystickButton *selectButtonP;
    frc::JoystickButton *startButtonP;
    frc::JoystickButton *leftStickButtonP;
    frc::JoystickButton *rightStickButtonP;

    // Axies for controller
    static const int LEFT_X_AXIS = 0;	//Logitech
    static const int LEFT_Y_AXIS = 1;
    static const int LEFT_TRIGGER_AXIS = 3;
    static const int RIGHT_TRIGGER_AXIS = 2;
    static const int RIGHT_X_AXIS = 4;
    static const int RIGHT_Y_AXIS = 5;

    static const int LEFT_X_AXIS_E = 0; 	//PS4
    static const int LEFT_Y_AXIS_E = 1;
    static const int LEFT_TRIGGER_AXIS_E = 3;
    static const int RIGHT_TRIGGER_AXIS_E = 4;
    static const int RIGHT_X_AXIS_E = 2;
    static const int RIGHT_Y_AXIS_E = 5;

private:
    frc4783::DriveTrain drivetrain;

    wpi::SmallString<64> deployDirectory;
    frc::Trajectory exampleTrajectory;

    frc::DifferentialDriveKinematics kDriveKinematics;

    void ConfigureButtonBindings();
}; 

} // frc4783

#endif // ROBOTMAP_H