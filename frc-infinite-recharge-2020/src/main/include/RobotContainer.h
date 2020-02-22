/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#ifndef ROBOTCONTAINER_H
#define ROBOTCONTAINER_H

#include "subsystems/Climber.h"
#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/buttons/JoystickButton.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/Command.h>

//#include <subsystems/DriveTrain.h>

namespace frc4783{

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
public:
    RobotContainer();

    frc::Joystick xbox{0};
    frc::Joystick ps4{1};

    // Drive Stick Buttons
    frc2::JoystickButton *aButtonS;
    frc2::JoystickButton *bButtonS;
    frc2::JoystickButton *xButtonS;
    frc2::JoystickButton *yButtonS;
    frc2::JoystickButton *leftBumperButtonS;
    frc2::JoystickButton *rightBumperButtonS;
    frc2::JoystickButton *selectButtonS;
    frc2::JoystickButton *startButtonS;
    frc2::JoystickButton *leftStickButtonS;
    frc2::JoystickButton *rightStickButtonS;
    frc2::JoystickButton *leftTriggerButtonS;
    frc2::JoystickButton *rightTriggerButtonS;
    frc2::JoystickButton *homeButtonS;
    frc2::JoystickButton *touchpadButtonS;

    frc2::JoystickButton *aButtonP;
    frc2::JoystickButton *bButtonP;
    frc2::JoystickButton *xButtonP;
    frc2::JoystickButton *yButtonP;
    frc2::JoystickButton *leftBumperButtonP;
    frc2::JoystickButton *rightBumperButtonP;
    frc2::JoystickButton *selectButtonP;
    frc2::JoystickButton *startButtonP;
    frc2::JoystickButton *leftStickButtonP;
    frc2::JoystickButton *rightStickButtonP;

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
    bool isExtended;
    
private:
    //frc4783::DriveTrain drivetrain;
    frc4783::Climber climber;
    RobotContainer* container;
    
    void ConfigureButtonBindings();
}; 

} //namespace frc4783
#endif // ROBOTMAP_H