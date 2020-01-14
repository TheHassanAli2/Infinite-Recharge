/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
 
#include "commands/DriveWithJoystick.h"
DriveWithJoystick::DriveWithJoystick(DriveTrain* subsystem): m_drivetrain(subsystem){
        AddRequirements({subsystem});
    }
void DriveWithJoystick::Execute(){
    float m_speed = (0.95 * Robot::robotcontainer->driveStick2->GetRawAxis(RobotContainer::LEFT_Y_AXIS_E));
    float m_turn = (1.0 * Robot::robotcontainer->driveStick2->GetRawAxis(RobotContainer::RIGHT_X_AXIS_E));
    Robot::drivetrain->ArcadeDrive(m_speed, m_turn);
} 

bool DriveWithJoystick::IsFinished(){
    return false;
}

void DriveWithJoystick::End(){
    Robot::drivetrain->Stop();
}

void DriveWithJoystick::Interrupted(){
    End();
}