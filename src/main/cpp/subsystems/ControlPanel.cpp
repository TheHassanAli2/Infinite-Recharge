/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ControlPanel.h"
#include <frc/VictorSP.h>
ControlPanel::ControlPanel() {
  controlpanelMotor.reset(new frc::VictorSP(1));

  // Implementation of subsystem constructor goes here.
}

void ControlPanel::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void ControlPanel::InitDefaultCommand (){
}

void ControlPanel::SetMotorSpeed(float speed){  
  controlpanelMotor->Set(speed);
}

void ControlPanel::SpinClockwise(){
  controlpanelMotor->Set(1);
}

void ControlPanel::SpinCounterClockwise(){
  controlpanelMotor->Set(-1);
}

void ControlPanel::StopMotor(){
  controlpanelMotor->Set(0);
}
