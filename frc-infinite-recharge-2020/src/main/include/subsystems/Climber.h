/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef CLIMBER_H
#define CLIMBER_H

#include <frc2/command/SubsystemBase.h>
#include <frc/WPILib.h>
#include <Constants.h>

class Climber : public frc2::SubsystemBase {
 public:
  Climber();
  void ClimbReset();
  void ClimbMotor();
  void ClimbSolenoid();
  void ClimbPart1();
  void ClimbPart2();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  std::shared_ptr<frc::SpeedController> pivotMotor;
  std::shared_ptr<frc::DoubleSolenoid> climbSolenoid;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
#endif // CLIMBER_H
