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
#include "commands/Outtake45.h"
#include "commands/Intake.h"
#include "commands/ReverseIntake.h"
#include "subsystems/Climber.h"
#include "commands/ControllerTest.h"

#include <frc2/command/button/JoystickButton.h>

#include "Controller/PS4.h"
#include "Controller/Xbox.h"

#include <string>

namespace frc4783{

RobotContainer::RobotContainer()
{
    printf("RobotContainer: drivetrain -set default command\n");

    //m_controller = new frc4783::XboxController(0);
    m_controller = new frc4783::PS4Controller(1);

    //drivetrain = new frc4783::rrDifferentialDrive();
    //m_drivetrain = new frc4783::rrTwoSpeed();
    //m_drivetrain->SetDefaultCommand(std::move(frc4783::DriveWithJoystick(m_drivetrain, m_controller)));
    //frc2::CommandScheduler::GetInstance().RegisterSubsystem(&m_ctrlPanel);
    ConfigureButtonBindings();
}
void RobotContainer::ConfigureButtonBindings()
{
    printf("configure button bindings");
    std::string buttonStr;
    // Drive Stick Buttons
    // --------------------------------
    // Left Button
    // --------------------------------
#if 0
    m_controller->addCommand(frc4783::ControllerButtonType_e::Left_Button,
                                frc4783::JoystickButtonActions_e::ToggleWhenPressed,
                                new frc4783::GearShift(m_drivetrain));
#endif

    m_controller->addCommand(
        frc4783::ControllerButtonType_e::Left_Button,
        frc4783::JoystickButtonActions_e::WhenPressed,
        new frc4783::ControllerTest("LeftButton", 
            m_controller->mapButton(frc4783::ControllerButtonType_e::Left_Button)) );

    // --------------------------------
    // Right Button
    // --------------------------------
#if 0
    m_controller->addCommand(frc4783::ControllerButtonType_e::Right_Button,
                                frc4783::JoystickButtonActions_e::WhenPressed,
                                new frc4783::ClimbRetract(&m_climber));
#endif

    m_controller->addCommand(
        frc4783::ControllerButtonType_e::Right_Button,
        frc4783::JoystickButtonActions_e::WhenPressed,
        new frc4783::ControllerTest("RightButton", 
            m_controller->mapButton(frc4783::ControllerButtonType_e::Right_Button)) );

    // --------------------------------
    // Top Button
    // --------------------------------

    /**
     * Used for Vision Alignment
     */

    m_controller->addCommand(
        frc4783::ControllerButtonType_e::Top_Button,
        frc4783::JoystickButtonActions_e::WhenPressed,
        new frc4783::ControllerTest("TopButton", 
            m_controller->mapButton(frc4783::ControllerButtonType_e::Top_Button)) );


    // --------------------------------
    // Bottom Button
    // --------------------------------
#if 0
    m_controller->addCommand(frc4783::ControllerButtonType_e::Bottom_Button,
                                frc4783::JoystickButtonActions_e::WhenPressed,
                                new frc4783::ClimbHook(&m_climber));
#endif

    m_controller->addCommand(
        frc4783::ControllerButtonType_e::Bottom_Button,
        frc4783::JoystickButtonActions_e::WhenPressed,
        new frc4783::ControllerTest("BottomButton", 
            m_controller->mapButton(frc4783::ControllerButtonType_e::Bottom_Button)) );

    // --------------------------------
    // Left Bumper
    // --------------------------------
#if 0
    m_controller->addCommand(frc4783::ControllerButtonType_e::Left_Bumper,
                                frc4783::JoystickButtonActions_e::WhenPressed,
                                new frc4783::ReverseIntake(&m_powercell));
#endif

    m_controller->addCommand(
        frc4783::ControllerButtonType_e::Left_Bumper,
        frc4783::JoystickButtonActions_e::WhenPressed,
        new frc4783::ControllerTest("LeftBumper", 
            m_controller->mapButton(frc4783::ControllerButtonType_e::Left_Bumper)) );

    // --------------------------------
    // Right Bumper
    // --------------------------------
#if 0
    m_controller->addCommand(frc4783::ControllerButtonType_e::Right_Bumper,
                                frc4783::JoystickButtonActions_e::WhenPressed,
                                new frc4783::Intake(&m_powercell));
#endif

    m_controller->addCommand(
        frc4783::ControllerButtonType_e::Right_Bumper,
        frc4783::JoystickButtonActions_e::WhenPressed,
        new frc4783::ControllerTest("RightBumper", 
            m_controller->mapButton(frc4783::ControllerButtonType_e::Right_Bumper)) );

    // --------------------------------
    // Left Trigger
    // --------------------------------

    // --------------------------------
    // Right Trigger
    // --------------------------------
#if 0
    m_controller->addCommand(frc4783::ControllerButtonType_e::Right_Trigger,
                                frc4783::JoystickButtonActions_e::WhenPressed,
                                new frc4783::Outtake45(&m_powercell));
#endif
    // --------------------------------
    // Left Stick
    // --------------------------------

    // --------------------------------
    // Right Stick
    // --------------------------------

    // --------------------------------
    // Fn Left
    // --------------------------------
#if 0
    m_controller->addCommand(frc4783::ControllerButtonType_e::FnLeft,
                                frc4783::JoystickButtonActions_e::ToggleWhenPressed,
                                new frc4783::RotatePanel(&m_ctrlPanel));
#endif
    m_controller->addCommand(
        frc4783::ControllerButtonType_e::FnLeft,
        frc4783::JoystickButtonActions_e::WhenPressed,
        new frc4783::ControllerTest("FnLeft", 
            m_controller->mapButton(frc4783::ControllerButtonType_e::FnLeft)) );


    // --------------------------------
    // Fn Right
    // --------------------------------
#if 0
    m_controller->addCommand(frc4783::ControllerButtonType_e::FnRight,
                                frc4783::JoystickButtonActions_e::ToggleWhenPressed,
                                new frc4783::Solenoid(&m_ctrlPanel));
#endif

    m_controller->addCommand(
        frc4783::ControllerButtonType_e::FnRight,
        frc4783::JoystickButtonActions_e::WhenPressed,
        new frc4783::ControllerTest("FnRight", 
            m_controller->mapButton(frc4783::ControllerButtonType_e::FnRight)) );

    // --------------------------------
    // Centre
    // --------------------------------

    m_controller->addCommand(
        frc4783::ControllerButtonType_e::Centre,
        frc4783::JoystickButtonActions_e::WhenPressed,
        new frc4783::ControllerTest("Centre", 
            m_controller->mapButton(frc4783::ControllerButtonType_e::Centre)) );

    // --------------------------------
    // Touchpad
    // --------------------------------
    


}

}  //namespace
