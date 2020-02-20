/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include <frc/VictorSP.h>

#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>


using namespace DriveConstants;

namespace frc4783 {

DriveTrain::DriveTrain()

:   m_leftEncoder{0, 1},
    m_rightEncoder{2, 3},
    m_odometry{frc::Rotation2d(units::degree_t(GetHeading()))}
{
    printf("Drivetrain init completed\n");

    // Motorcontrollers
    frontLeftMotor.reset(new frc::VictorSP(0));
    backLeftMotor.reset(new frc::VictorSP(1));
    frontRightMotor.reset(new frc::VictorSP(2));
    backRightMotor.reset(new frc::VictorSP(3));
    //Motorcontroller groups
    leftDrive.reset(new frc::SpeedControllerGroup(*backLeftMotor, *frontLeftMotor));
    rightDrive.reset(new frc::SpeedControllerGroup(*backRightMotor, *frontRightMotor));
    differentialDrive.reset(new frc::DifferentialDrive(*leftDrive, *rightDrive));
    // Sensors
    // m_odometry.reset(new frc::DifferentialDriveOdometry());
    //m_gyro.Reset();
    
    // Set the distance per pulse for the encoders
    m_leftEncoder.SetDistancePerPulse(0.00498727);
    m_rightEncoder.SetDistancePerPulse(0.00498727);

    ResetEncoders();



    frontLeftMotor->SetInverted(true);
    backLeftMotor->SetInverted(true);
    frontRightMotor->SetInverted(true);
    backRightMotor->SetInverted(true);
    leftDrive->SetInverted(true);
    rightDrive->SetInverted(true);

}

void DriveTrain::Periodic()
{
    m_odometry.Update(frc::Rotation2d(units::degree_t(GetHeading())),
    units::meter_t(m_leftEncoder.GetDistance()),
    units::meter_t(m_rightEncoder.GetDistance()));
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

void DriveTrain::TankDriveVolts(units::volt_t left, units::volt_t right) {
    leftDrive->SetVoltage(left);
    rightDrive->SetVoltage(-right);
    differentialDrive->Feed();
}

void DriveTrain::ResetEncoders() {
    m_leftEncoder.Reset();
    m_rightEncoder.Reset();
}

double DriveTrain::GetAverageEncoderDistance() {
    return (m_leftEncoder.GetDistance() + m_rightEncoder.GetDistance()) / 2.0;
}

void DriveTrain::SetMaxOutput(double maxOutput) {
    differentialDrive->SetMaxOutput(maxOutput);
}

frc::DifferentialDriveWheelSpeeds DriveTrain::GetWheelSpeeds() {
  return {units::meters_per_second_t(m_leftEncoder.GetRate()),
          units::meters_per_second_t(m_rightEncoder.GetRate())};
}

double DriveTrain::GetHeading() {
    return std::remainder(m_gyro.GetAngle(), 360) * (DriveConstants::kGyroReversed ? -1.0 : 1.0);
}

double DriveTrain::GetTurnRate() {
    return m_gyro.GetRate() * (DriveConstants::kGyroReversed ? -1.0 : 1.0);
}

frc::Pose2d DriveTrain::GetPose() { return m_odometry.GetPose(); }

void DriveTrain::ResetOdometry(frc::Pose2d pose) {
    ResetEncoders();
    m_odometry.ResetPosition(pose,
    frc::Rotation2d(units::degree_t(GetHeading())));
}

} /* namespace frc4783 */