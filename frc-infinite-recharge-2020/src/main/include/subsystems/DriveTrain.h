/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/WPILib.h>
#include <Constants.h>
#include <Robot.h>
#include <commands/DriveWithJoystick.h>
#include "ctre/Phoenix.h"

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

    // remember to put something here later ya feel?

  private:

};
