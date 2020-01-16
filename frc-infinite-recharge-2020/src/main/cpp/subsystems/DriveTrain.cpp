
/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"

using namespace DriveConstants;

DriveTrain::DriveTrain() : frontLeftMotor(2), backLeftMotor(3), frontRightMotor(0), backRightMotor(1)
{
frontLeftMotor.SetInverted(true);
backLeftMotor.SetInverted(true);
frontRightMotor.SetInverted(true);
backRightMotor.SetInverted(true);
}

void DriveTrain::Periodic()
{
}

void DriveTrain::ArcadeDrive(double speed, double turn)
{
  differentialDrive->ArcadeDrive(speed, turn);
}

void DriveTrain::Stop()
{
  ArcadeDrive(0, 0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrain::TankDrive(double leftspeed, double rightspeed)
{
  differentialDrive->TankDrive(leftspeed, rightspeed);
}
