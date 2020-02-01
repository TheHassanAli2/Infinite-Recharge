/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Climber.h"
#include "frc/SpeedController.h"
#include "frc/DoubleSolenoid.h"

Climber::Climber() {
  pivotMotor.reset(new frc::VictorSP(4));
  climbSolenoid.reset(new frc::DoubleSolenoid(#))

  pivotMotor->SetInverted(true);
}

void Climber::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void Climber::ClimbReset(){
  climbSolenoid->Set(frc::DoubleSolenoid::Value::kReverse);
  pivotMotor.Set(0);
}

void Climber::ClimbMotor(bool clockwise) {
  if (clockwise == true){
    pivotMotor.Set(1);
  }
  else {
    pivotMotor.Set(-1);
  }
}

void Climber::ClimbSolenoid(bool extended) {
  if (extended == true){
    climbSolenoid->Set(frc::DoubleSolenoid::Value::kForward);
  }
  else {
    climbSolenoid->Set(frc::DoubleSolenoid::Value::kReverse);
  }
}

void Climber::ClimbPart1() {
  pivotMotor.Set(1);
  // might add pause
  climbSolenoid->Set(frc::DoubleSolenoid::Value::kForward);
}

void Climber::ClimbPart2() {
  climbSolenoid->Set(frc::DoubleSolenoid::Value::kReverse);
}