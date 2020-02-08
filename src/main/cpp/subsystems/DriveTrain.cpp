/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include <frc/VictorSP.h>

using namespace DriveConstants;

namespace frc4783 {

DriveTrain::DriveTrain()
{
    printf("Drivetrain init completed\n");
    frontLeftMotor.reset(new frc::VictorSP(5));
    backLeftMotor.reset(new frc::VictorSP(1));
    frontRightMotor.reset(new frc::VictorSP(2));
    backRightMotor.reset(new frc::VictorSP(3));
    leftDrive.reset(new frc::SpeedControllerGroup(*backLeftMotor, *frontLeftMotor));
    rightDrive.reset(new frc::SpeedControllerGroup(*backRightMotor, *frontRightMotor));
    differentialDrive.reset(new frc::DifferentialDrive(*leftDrive, *rightDrive));


    frontLeftMotor->SetInverted(true);
    backLeftMotor->SetInverted(true);
    frontRightMotor->SetInverted(true);
    backRightMotor->SetInverted(true);
    leftDrive->SetInverted(true);
    rightDrive->SetInverted(true);

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

} /* namespace frc4783 */