/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
 
#include "commands/DriveWithJoystick.h"

//ya feel?

namespace frc4783{

frc4783::DriveWithJoystick::DriveWithJoystick(frc4783::rrDriveTrain* subsystem, frc4783::MainController *controller) : 
        drivetrain(subsystem), m_controller(controller){
        AddRequirements(subsystem);
        printf("DriveWithJoystick init completed");
    }

void frc4783::DriveWithJoystick::Execute(){
    float m_speed = (0.95 * m_controller->getRawAxis(Left_Y_Axis));
    float m_turn = (1.0 * m_controller->getRawAxis(Right_X_Axis));
    drivetrain->ArcadeDrive(m_speed,m_turn);
} 

bool frc4783::DriveWithJoystick::IsFinished(){
    return false;
}

void frc4783::DriveWithJoystick::End(){
    drivetrain->Stop();
}

void frc4783::DriveWithJoystick::Interrupted(){
    End();
}

void frc4783::DriveWithJoystick::Initialize() {
    
}}