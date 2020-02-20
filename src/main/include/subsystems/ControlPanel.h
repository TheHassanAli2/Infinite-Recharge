/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Subsystem.h>
#include "Constants.h"
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h> 

#include "RoboRavensSubsystem.h"

namespace frc4783 {

class ControlPanel : public RoboRavensSubsystem {
  private:
    static const int ControlPanelMotorId = 0;
    static const int ControlPanelMotorPort = 9;
    static const int SolenoidId = 0;
    static const int SolenoidForwardPort = 4;
    static const int SolenoidReversePort = 5;


  public:
   ControlPanel();
    void GetColor();
    void ControlPanelInit();
    void GetIR();
    void PutNumber();
    void GetProximity();
    void RotateControlPanel(float speed);
    void SetSolenoidDirection(frc::DoubleSolenoid::Value direction);


  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;


};

  
}  // namespace frc4783