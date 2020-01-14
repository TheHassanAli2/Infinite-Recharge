/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

namespace DriveConstants
{
  std::shared_ptr<frc::ADXRS450_Gyro> gyro;
  std::shared_ptr<frc::Encoder> leftDriveEncoder;
  std::shared_ptr<frc::Encoder> rightDriveEncoder;
  std::shared_ptr<frc::DifferentialDrive> differentialDrive;

  std::shared_ptr<frc::SpeedControllerGroup> leftDrive;
  std::shared_ptr<frc::SpeedControllerGroup> rightDrive;
  std::shared_ptr<frc::SpeedController> frontLeftDrive;  
  std::shared_ptr<frc::SpeedController> backLeftDrive;
  std::shared_ptr<frc::SpeedController> frontRightDrive;
  std::shared_ptr<frc::SpeedController> backRightDrive;
  std::shared_ptr<frc::DoubleSolenoid> gearSolenoid;
  std::shared_ptr<frc::DoubleSolenoid> climbSolenoid;
  std::shared_ptr<frc::Compressor> compressor;
}
/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
