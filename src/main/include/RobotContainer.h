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
#include <Robots/RobotBase.h>

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

    frc::Joystick ps4{1};

    // Drive Stick Buttons
    frc2::JoystickButton *aButtonS;
    frc::JoystickButton *bButtonS;
    frc2::JoystickButton *xButtonS;
    frc2::JoystickButton *yButtonS;
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

#ifdef XBOX_CONTROLLER
    frc::Joystick xbox{0};

    frc::JoystickButton *aButtonP;
    frc::JoystickButton *bButtonP;
    frc2::JoystickButton *xButtonP;
    frc2::JoystickButton *yButtonP;
    frc::JoystickButton *leftBumperButtonP;
    frc::JoystickButton *rightBumperButtonP;
    frc::JoystickButton *selectButtonP;
    frc::JoystickButton *startButtonP;
    frc::JoystickButton *leftStickButtonP;
    frc::JoystickButton *rightStickButtonP;
#endif

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
    frc4783::RobotBase *m_robot;
    frc4783::ControlPanel  ctrlPanel;
    
    //Pointer Object of rrDriveTrain and object of rrTwoSpeed
    frc4783::rrDriveTrain *drivetrain;
    
    
    void ConfigureButtonBindings();
}; 
}
#endif // ROBOTMAP_H