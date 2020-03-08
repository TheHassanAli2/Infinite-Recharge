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
#include "commands/ClimbHook.h" 
#include "commands/ClimbRetract.h"
#include "subsystems/Climber.h"
#include <frc2/command/button/JoystickButton.h>

#include "Controller/PS4.h"
#include "Controller/Xbox.h"

namespace frc4783{

RobotContainer::RobotContainer()
{
    printf("RobotContainer: drivetrain -set default command\n");

    //m_controller = new frc4783::XboxController(0);
    m_controller = new frc4783::PS4Controller(1);

    //drivetrain = new frc4783::rrDifferentialDrive();
    m_drivetrain = new frc4783::rrTwoSpeed();
    m_drivetrain->SetDefaultCommand(std::move(frc4783::DriveWithJoystick(m_drivetrain, m_controller)));
    //frc2::CommandScheduler::GetInstance().RegisterSubsystem(&m_ctrlPanel);
    ConfigureButtonBindings();
}
void RobotContainer::ConfigureButtonBindings()
{
    printf("configure button bindings");
    // Drive Stick Buttons
    // --------------------------------
    // Left Button
    // --------------------------------

    m_controller->addCommand(frc4783::ControllerButtonType_e::Left_Button,
                                frc4783::JoystickButtonActions_e::ToggleWhenPressed,
                                new frc4783::GearShift(m_drivetrain));

    // --------------------------------
    // Right Button
    // --------------------------------
    //bButtonS->WhenPressed(new frc4783::ClimbRetract(&climber));

    m_controller->addCommand(frc4783::ControllerButtonType_e::Right_Button,
                                frc4783::JoystickButtonActions_e::WhenPressed,
                                new frc4783::ClimbRetract(&m_climber));

    // --------------------------------
    // Top Button
    // --------------------------------

    m_controller->addCommand(frc4783::ControllerButtonType_e::Top_Button,
                                frc4783::JoystickButtonActions_e::ToggleWhenPressed,
                                new frc4783::RotatePanel(&m_ctrlPanel));

    // --------------------------------
    // Bottom Button
    // --------------------------------
    //aButtonS->WhenPressed(new frc4783::ClimbHook(&climber, this));

    m_controller->addCommand(frc4783::ControllerButtonType_e::Bottom_Button,
                                frc4783::JoystickButtonActions_e::WhenPressed,
                                new frc4783::ClimbHook(&m_climber));

    // --------------------------------
    // Left Bumper
    // --------------------------------
    m_controller->addCommand(frc4783::ControllerButtonType_e::Left_Bumper,
                                frc4783::JoystickButtonActions_e::ToggleWhenPressed,
                                new frc4783::Solenoid(&m_ctrlPanel));

    // --------------------------------
    // Right Bumper
    // --------------------------------

    // --------------------------------
    // Left Trigger
    // --------------------------------

    // --------------------------------
    // Right Trigger
    // --------------------------------

    // --------------------------------
    // Left Stick
    // --------------------------------

    // --------------------------------
    // Right Stick
    // --------------------------------

    // --------------------------------
    // Fn Left
    // --------------------------------

    // --------------------------------
    // Fn Right
    // --------------------------------

    // --------------------------------
    // Centre
    // --------------------------------

    // --------------------------------
    // Touchpad
    // --------------------------------
    


}

}  //namespace
