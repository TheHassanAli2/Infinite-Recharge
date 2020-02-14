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
{
    printf("Drivetrain init completed\n");
    frontLeftMotor.reset(new frc::VictorSP(0));
    backLeftMotor.reset(new frc::VictorSP(1));
    frontRightMotor.reset(new frc::VictorSP(2));
    backRightMotor.reset(new frc::VictorSP(3));
    leftDrive.reset(new frc::SpeedControllerGroup(*backLeftMotor, *frontLeftMotor));
    rightDrive.reset(new frc::SpeedControllerGroup(*backRightMotor, *frontRightMotor));
    differentialDrive.reset(new frc::DifferentialDrive(*leftDrive, *rightDrive));
    m_odometry.reset(new frc::DifferentialDriveOdometry());
    m_leftEncoder.reset(new frc::Encoder());
    m_rightEncoder.reset(new frc::Encoder());
    m_leftEncoder{kLeftEncoderPorts[0], kLeftEncoderPorts[1]},
    m_rightEncoder{kRightEncoderPorts[0], kRightEncoderPorts[1]},
    m_odometry{frc::Rotation2d(units::degree_t(GetHeading()))} 
    // Set the distance per pulse for the encoders
    m_leftEncoder.SetDistancePerPulse(kEncoderDistancePerPulse);
    m_rightEncoder.SetDistancePerPulse(kEncoderDistancePerPulse);

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
    leftDrive.SetVoltage(left);
    rightDrive.SetVoltage(-right);
    m_drive.Feed();
}

void DriveTrain::ResetEncoders() {
    m_leftEncoder.reset();
    m_rightEncoder.reset();
}

double DriveTrain::GetAverageEncoderDistance() {
    return (m_leftEncoder.GetDistance() + m_rightEncoder.GetDistance()) / 2.0;
}

void DriveTrain::SetMaxOutput(double maxOutput) {
    m_drive.SetMaxOutput(maxOutput);
}

frc::Encoder DriveTrain::GetLeftEncoder() { return m_leftEncoder; }

frc::Encoder DriveTrain::GetRightEncoder() { return m_rightEncoder; }


frc::DifferentialDriveWheelSpeeds DriveTrain::GetWheelSpeeds() {
    return {units::meters_per_second_t(m_leftEncoder.GetRate()),
    units::meters_per_second_t(m_rightEncoder.GetRate())};
}

double DriveTrain::GetHeading() {
    return std::remainder(m_gyro.GetAngle(), 360) * (kGyroReversed ? -1.0 : 1.0);
}

double DriveTrain::GetTurnRate() {
    return m_gyro.GetRate() * (kGyroReversed ? -1.0 : 1.0);
}

frc::Pose2d DriveTrain::GetPose() { return m_odometry.GetPose(); }

void DriveTrain::ResetOdometry(frc::Pose2d pose) {
    ResetEncoders();
    m_odometry.ResetPosition(pose,
    frc::Rotation2d(units::degree_t(GetHeading())));
}

} /* namespace frc4783 */