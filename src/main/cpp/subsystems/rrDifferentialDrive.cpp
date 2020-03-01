/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/rrDifferentialDrive.h"


namespace frc4783{

rrDifferentialDrive::rrDifferentialDrive()
{
    leftDrive.reset(new frc::SpeedControllerGroup(*backLeftMotor, *frontLeftMotor));
    rightDrive.reset(new frc::SpeedControllerGroup(*backRightMotor, *frontRightMotor));
    rightDrive->SetInverted(true);

    differentialDrive.reset(new frc::DifferentialDrive(*leftDrive, *rightDrive));

    printf("rrDifferentialDrive init completed\n");
}

void rrDifferentialDrive::Periodic(){

}

void rrDifferentialDrive::ArcadeDrive(double speed, double turn){
    differentialDrive->ArcadeDrive(speed, turn);
}

void rrDifferentialDrive::Stop(){
    ArcadeDrive(0, 0);
}

void rrDifferentialDrive::TankDrive(double leftspeed, double rightspeed){
    differentialDrive->TankDrive(leftspeed, rightspeed);
}

void rrDifferentialDrive::TankDriveVolts(units::volt_t left, units::volt_t right) {
    leftDrive->SetVoltage(left);
    rightDrive->SetVoltage(-right);
    differentialDrive->Feed();
}

void rrDifferentialDrive::SetMaxOutput(double maxOutput) {
    differentialDrive->SetMaxOutput(maxOutput);
}

frc::DifferentialDriveWheelSpeeds rrDifferentialDrive::GetWheelSpeeds() {
  return {units::meters_per_second_t(m_leftEncoder.GetRate()),
          units::meters_per_second_t(m_rightEncoder.GetRate())};
}


} // namespace frc4783