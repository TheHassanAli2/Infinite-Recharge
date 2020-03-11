/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

//ya feel?

#include "RobotContainer.h"
#include "ctre/Phoenix.h"
#include "commands/DriveWithJoystick.h"
#include "commands/GearShift.h"
#include <frc2/command/button/JoystickButton.h>

#include "commands/Intake.h"
#include "commands/ReverseIntake.h"
#include "commands/Outtake45.h"



namespace frc4783{

RobotContainer::RobotContainer()
{
    printf("RobotContainer: drivetrain -set default command\n");
    //drivetrain = new frc4783::rrDifferentialDrive();
    drivetrain = new frc4783::rrTwoSpeed();
    drivetrain->SetDefaultCommand(std::move(frc4783::DriveWithJoystick(drivetrain, this)));
    //frc2::CommandScheduler::GetInstance().RegisterSubsystem(&ctrlPanel);
    ConfigureButtonBindings();
}
void RobotContainer::ConfigureButtonBindings()
{
    printf("configure button bindings");
    // Drive Stick Buttons

//#ifdef XBOX_CONTROLLER
    aButtonP = new frc2::JoystickButton(&xbox,1);
    //bButtonP = new frc2::JoystickButton(&xbox, 2);
    xButtonP = new frc2::JoystickButton(&xbox, 3);
    yButtonP = new frc2::JoystickButton(&xbox, 4);
    leftBumperButtonP = new frc2::JoystickButton(&xbox, 5);
    rightBumperButtonP = new frc2::JoystickButton(&xbox, 6);
    selectButtonP = new frc2::JoystickButton(&xbox, 7);
    startButtonP = new frc2::JoystickButton(&xbox, 8);
    leftStickButtonP = new frc2::JoystickButton(&xbox, 9);
    rightStickButtonP = new frc2::JoystickButton(&xbox, 10);
//#endif
#ifdef PS4_CONTROLLER
    // Drive Stick Buttons
    xButtonS = new frc2::JoystickButton(&ps4, 1);			 //'[]' on PS
    aButtonS = new frc2::JoystickButton(&ps4, 2);			 //'X' on PS
    bButtonS = new frc2::JoystickButton(&ps4, 3);			 //'O' on PS
    yButtonS = new frc2::JoystickButton(&ps4, 4);			 //'/\' on PS
    leftBumperButtonS = new frc2::JoystickButton(&ps4, 5);   //'L1' on PS
    rightBumperButtonS = new frc2::JoystickButton(&ps4, 6);  //'R1' on PS
    leftTriggerButtonS = new frc2::JoystickButton(&ps4, 7);  //'L2' on PS
    rightTriggerButtonS = new frc2::JoystickButton(&ps4, 8); //'R2' on PS
    selectButtonS = new frc2::JoystickButton(&ps4, 9);		 //'Share/Back' on PS
    startButtonS = new frc2::JoystickButton(&ps4, 10);		 //'Start' on PS
    leftStickButtonS = new frc2::JoystickButton(&ps4, 11);   //'L3' on PS
    rightStickButtonS = new frc2::JoystickButton(&ps4, 12);  //'R3' on PS
    homeButtonS = new frc2::JoystickButton(&ps4, 13);		 //'PS' on PS
#endif
    /*xButtonS->ToggleWhenPressed(new frc4783::GearShift(drivetrain));

    printf("configure button bindings - init rotatepanel command\n");
    aButtonS->ToggleWhenPressed(new frc4783::RotatePanel(&ctrlPanel));
    yButtonS->ToggleWhenPressed(new frc4783::Solenoid(&ctrlPanel));

    leftBumperButtonS
        ->WhenPressed(new frc4783::Intake(&powercell));

    rightBumperButtonS
        ->ToggleWhenPressed(new frc4783::ReverseIntake(&powercell));
      
    rightTriggerButtonS
        ->WhenReleased(new frc4783::Outtake90Reverse(&powercell));

    rightTriggerButtonS
        ->WhenPressed(new frc4783::Outtake90(&powercell));
      
    leftTriggerButtonS
        ->WhenReleased(new frc4783::Outtake40Reverse(&powercell));

    leftTriggerButtonS*/
    aButtonP
        ->WhenPressed(new frc4783::Outtake45(&powercell));
     leftBumperButtonP->WhenPressed(new frc4783::Intake(&powercell));
     rightBumperButtonP->WhenPressed(new frc4783::ReverseIntake(&powercell));

#ifdef XBOX_CONTROLLER
    xButtonP->ToggleWhenPressed(new frc4783::RotatePanel(&ctrlPanel));
    yButtonP->ToggleWhenPressed(new frc4783::Solenoid(&ctrlPanel));
#endif
    
}

}  //namespace
