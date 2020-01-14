
/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"

using namespace DriveConstants;

DriveTrain::DriveTrain()
{
void frc2::CommandScheduler::RegisterSubsystem();	
#define FRONT_LEFT_DRIVE_PORT 2
#define BACK_LEFT_DRIVE_PORT 3
#define FRONT_RIGHT_DRIVE_PORT 0
#define BACK_RIGHT_DRIVE_PORT 1

  backLeftDrive = DriveConstants::backLeftDrive;
  frontLeftDrive = DriveConstants::frontLeftDrive;
  backRightDrive = DriveConstants::backRightDrive;
  frontRightDrive = DriveConstants::frontRightDrive;

  backLeftDrive.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(3));

  frontLeftDrive.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(2));

  backRightDrive.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(1));

  frontRightDrive.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(0));
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
