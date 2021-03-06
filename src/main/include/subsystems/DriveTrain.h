/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <frc2/command/SubsystemBase.h>
#include <frc/SpeedController.h>

#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <Constants.h>

#include <frc/ADXRS450_Gyro.h>
#include <frc/Encoder.h>
#include <frc/PWMVictorSPX.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <units/units.h>
//#include <Robot.h>
//#include <commands/DriveWithJoystick.h>
#include "ctre/Phoenix.h"

namespace frc4783 {

class DriveTrain : public frc2::SubsystemBase {
public:
  DriveTrain();
  void TankDrive(double leftspeed, double rightspeed);
  void ArcadeDrive(double speed, double turn);
  void Stop();

    /**
     * Will be called periodically whenever the CommandScheduler runs.
     */
  void Periodic() override;

  void TankDriveVolts(units::volt_t left, units::volt_t right);
  void ResetEncoders();
  double GetAverageEncoderDistance();
  frc::Encoder GetLeftEncoder();
  frc::Encoder GetRightEncoder();
  void SetMaxOutput(double maxOutput);
  double GetHeading();
  double GetTurnRate();
  frc::Pose2d GetPose();
  frc::DifferentialDriveWheelSpeeds GetWheelSpeeds();
  void ResetOdometry(frc::Pose2d pose);


private:
    std::shared_ptr<frc::SpeedController> frontLeftMotor;
    std::shared_ptr<frc::SpeedController> backLeftMotor;
    std::shared_ptr<frc::SpeedController> frontRightMotor;
    std::shared_ptr<frc::SpeedController> backRightMotor;
    std::shared_ptr<frc::DifferentialDrive> differentialDrive;
    std::shared_ptr<frc::SpeedControllerGroup> leftDrive;
    std::shared_ptr<frc::SpeedControllerGroup> rightDrive;
    frc::Encoder m_leftEncoder;
    frc::Encoder m_rightEncoder;
    frc::ADXRS450_Gyro m_gyro;
    frc::DifferentialDriveOdometry m_odometry;
};

} /* namespace frc4783 */

#endif // DRIVETRAIN_H