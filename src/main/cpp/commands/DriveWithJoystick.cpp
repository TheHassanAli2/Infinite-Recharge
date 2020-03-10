/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
 
#include "commands/DriveWithJoystick.h"

//ya feel?

namespace frc4783{

frc4783::DriveWithJoystick::DriveWithJoystick(frc4783::rrDriveTrain* subsystem, RobotContainer* contained) : drivetrain(subsystem), container(contained){
        AddRequirements(subsystem);
        printf("DriveWithJoystick init completed");
    }

void frc4783::DriveWithJoystick::Execute(){
   // float m_speed = (0.95 * container->ps4.GetRawAxis(RobotContainer::LEFT_Y_AXIS_E));
    //float m_turn = (1.0 * container->ps4.GetRawAxis(RobotContainer::RIGHT_X_AXIS_E));
    //drivetrain->ArcadeDrive(m_speed,m_turn);
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