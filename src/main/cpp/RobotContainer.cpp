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

#include "Controller/PS4.h"
#include "Controller/Xbox.h"

namespace frc4783{

RobotContainer::RobotContainer()
{
    printf("RobotContainer: drivetrain -set default command\n");

    //m_controller = new frc4783::XboxController(0);
    m_controller = new frc4783::PS4Controller(1);

    //drivetrain = new frc4783::rrDifferentialDrive();
    drivetrain = new frc4783::rrTwoSpeed();
    drivetrain->SetDefaultCommand(std::move(frc4783::DriveWithJoystick(drivetrain, m_controller)));
    frc2::CommandScheduler::GetInstance().RegisterSubsystem(&ctrlPanel);
    ConfigureButtonBindings();
}
void RobotContainer::ConfigureButtonBindings()
{
    printf("configure button bindings");
    // Drive Stick Buttons

    m_controller->addCommand(frc4783::ControllerButtonType_e::Right_Button,
                                frc4783::JoystickButtonActions_e::ToggleWhenPressed,
                                new frc4783::GearShift(drivetrain));

    m_controller->addCommand(frc4783::ControllerButtonType_e::Bottom_Button,
                                frc4783::JoystickButtonActions_e::ToggleWhenPressed,
                                new frc4783::RotatePanel(&ctrlPanel));

    m_controller->addCommand(frc4783::ControllerButtonType_e::Top_Button,
                                frc4783::JoystickButtonActions_e::ToggleWhenPressed,
                                new frc4783::Solenoid(&ctrlPanel));

}

}  //namespace
