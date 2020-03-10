/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#ifndef ROBOTCONTAINER_H
#define ROBOTCONTAINER_H

#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/Command.h>
#include <frc/buttons/JoystickButton.h>
#include <frc/Joystick.h>
#include <subsystems/rrTwoSpeed.h>
#include <frc2/command/ParallelRaceGroup.h>

#include <subsystems/ControlPanel.h>
#include <commands/RotatePanel.h>
#include <commands/Solenoid.h>

#include <subsystems/Powercell.h>


/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */

//ya feel?

namespace frc4783{
class RobotContainer {
public:
    RobotContainer();

    frc2::Command* GetAutonomousCommand();
#ifdef PS4_CONTROLLER
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
#endif

//#ifdef XBOX_CONTROLLER
    frc::Joystick xbox{0};

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
//#endif

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
    frc4783::ControlPanel  ctrlPanel;
    
    //Pointer Object of rrDriveTrain and object of rrTwoSpeed
    
    frc4783::rrDriveTrain *drivetrain;
    frc4783::Powercell powercell;
    void ConfigureButtonBindings();
}; 
}
#endif // ROBOTMAP_H
