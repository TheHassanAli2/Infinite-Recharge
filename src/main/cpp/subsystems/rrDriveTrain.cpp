/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/rrDriveTrain.h"

#include <frc/VictorSP.h>
#include "ctre/Phoenix.h"
#include "frc/PWMVictorSPX.h"
#include "frc/PWMTalonSRX.h"

#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>

using namespace DriveConstants;

namespace frc4783{

rrDriveTrain::rrDriveTrain() :
    m_leftEncoder{0, 1},
    m_rightEncoder{2, 3},
    m_odometry{frc::Rotation2d(units::degree_t(GetHeading()))}
{
    //Motor Controller and Signal type enumeration
    /**
     * @todo: motor type and signal type should be parameters to rrDriveTrain constructor
     */
    motors = VictorSPX; 
    signal = CAN;

    //Port numeration
    frontLeftPort = 0;
    frontRightPort = 1;
    backLeftPort = 2;
    backRightPort = 3;

    //Automated decleration of motors
    if (motors == VictorSPX && signal == CAN){
        frontLeftMotor.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(frontLeftPort));
        frontRightMotor.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(frontRightPort));
        backLeftMotor.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(backLeftPort));
        backRightMotor.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(backRightPort));
    }
    else if (motors == VictorSPX && signal == PWM){
        frontLeftMotor.reset(new frc::VictorSP(frontLeftPort));
        backLeftMotor.reset(new frc::VictorSP(frontRightPort));
        frontRightMotor.reset(new frc::VictorSP(backLeftPort));
        backRightMotor.reset(new frc::VictorSP(backRightPort));
    }
    else if (motors == TalonSRX && signal == CAN){
        frontLeftMotor.reset(new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(frontLeftPort));
        frontRightMotor.reset(new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(frontRightPort));
        backLeftMotor.reset(new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(backLeftPort));
        backRightMotor.reset(new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(backRightPort));
    }
    else if (motors == TalonSRX && signal == PWM){
        frontLeftMotor.reset(new frc::PWMTalonSRX(frontLeftPort));
        backLeftMotor.reset(new frc::PWMTalonSRX(frontRightPort));
        frontRightMotor.reset(new frc::PWMTalonSRX(backLeftPort));
        backRightMotor.reset(new frc::PWMTalonSRX(backRightPort));
    }

    // Set the distance per pulse for the encoders
    m_leftEncoder.SetDistancePerPulse(0.00498727);
    m_rightEncoder.SetDistancePerPulse(0.00498727);

    ResetEncoders();

    frontLeftMotor->SetInverted(true);
    backLeftMotor->SetInverted(true);
    frontRightMotor->SetInverted(true);
    backRightMotor->SetInverted(true);
    
    printf("rrDriveTrain init completed\n");
}

void rrDriveTrain::Periodic()
{
    m_odometry.Update(frc::Rotation2d(units::degree_t(GetHeading())),
    units::meter_t(m_leftEncoder.GetDistance()),
    units::meter_t(m_rightEncoder.GetDistance()));

}

void rrDriveTrain::setSpeed(int port, double speed)
{
    switch(port){
        case 0: 
        frontLeftMotor->Set(speed);
        break;
        case 1:
        frontRightMotor->Set(speed);
        break;
        case 2:
        backLeftMotor->Set(speed);
        break;
        case 3:
        backRightMotor->Set(speed);
        break;
    }
}

void rrDriveTrain::ArcadeDrive(double speed, double turn){
}

void rrDriveTrain::Stop(){
    frontLeftMotor->Set(0);
    frontRightMotor->Set(0);
    backLeftMotor->Set(0);
    backRightMotor->Set(0);
}

void rrDriveTrain::TankDrive(double leftspeed, double rightspeed){
}

void rrDriveTrain::TankDriveVolts(units::volt_t left, units::volt_t right) {
}

void rrDriveTrain::ReverseGear(){
    printf("Rev Gear - DriveTrain\n");
}

void rrDriveTrain::ForwardGear(){
    printf("Fwd Gear - DriveTrain\n");
}

void rrDriveTrain::GearOff() {

}

bool rrDriveTrain::isHighGear() {
    return true;
}

void rrDriveTrain::ResetEncoders() {
    m_leftEncoder.Reset();
    m_rightEncoder.Reset();
}

double rrDriveTrain::GetAverageEncoderDistance() {
    return (m_leftEncoder.GetDistance() + m_rightEncoder.GetDistance()) / 2.0;
}

void rrDriveTrain::SetMaxOutput(double maxOutput) {
    
}

frc::DifferentialDriveWheelSpeeds rrDriveTrain::GetWheelSpeeds() {
  return {units::meters_per_second_t(m_leftEncoder.GetRate()),
          units::meters_per_second_t(m_rightEncoder.GetRate())};
}

double rrDriveTrain::GetHeading() {
    return std::remainder(m_gyro.GetAngle(), 360) * (DriveConstants::kGyroReversed ? -1.0 : 1.0);
}

double rrDriveTrain::GetTurnRate() {
    return m_gyro.GetRate() * (DriveConstants::kGyroReversed ? -1.0 : 1.0);
}

frc::Pose2d rrDriveTrain::GetPose() { return m_odometry.GetPose(); }

void rrDriveTrain::ResetOdometry(frc::Pose2d pose) {
    ResetEncoders();
    m_odometry.ResetPosition(pose,
    frc::Rotation2d(units::degree_t(GetHeading())));
}


} // namespace frc4783