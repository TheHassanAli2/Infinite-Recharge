/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Climber.h"
#include <frc/Talon.h>
#include <frc/DoubleSolenoid.h>
#include "commands/ClimbHook.h" 

namespace frc4783{

Climber::Climber() {
  
  /*pivotMotor1.reset(new frc::VictorSP(4));
  pivotMotor2.reset(new frc::VictorSP(5));*/
  pivotMotor1.reset(new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(4));
  pivotMotor2.reset(new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(5));
  climbSolenoid1.reset(new frc::DoubleSolenoid(2,3));
  climbSolenoid2.reset(new frc::DoubleSolenoid(4,5)); //Actually 2 & 3
  limitSwitch.reset(new frc::DigitalInput(1));
  counter.reset(new frc::Counter(limitSwitch));
  timer.reset(new frc::Timer());
  ClimbReset();
  //pivotMotor2->SetInverted(true);
}

void Climber::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void Climber::ClimbReset(){
  climbSolenoid1->Set(frc::DoubleSolenoid::Value::kReverse);
  climbSolenoid2->Set(frc::DoubleSolenoid::Value::kReverse);
  pivotMotor1->Set(0);
  pivotMotor2->Set(0);
  timer->Reset();
}

void Climber::ClimbMotor(bool clockwise) {
  if (clockwise == true){
    pivotMotor1->Set(1);
  }
  else {
    pivotMotor1->Set(-1);
  }
}

void Climber::ClimbSolenoid(bool extended) {
  if (extended == true){
    climbSolenoid2->Set(frc::DoubleSolenoid::Value::kForward);
  }
  else {
    climbSolenoid2->Set(frc::DoubleSolenoid::Value::kReverse);
  }
}

void Climber::ClimbPivotStage(int pivotStage) {
  switch (pivotStage){
    case 1: 
      pivotMotor1->Set(1);
      pivotMotor2->Set(-1);
      break;
    case 2:
      pivotMotor1->Set(0);
      pivotMotor2->Set(0);
      break;
  }
  
}

void Climber::ClimbExtendStage(int extendStage) {
  switch (extendStage){
    case 1:
      climbSolenoid1->Set(frc::DoubleSolenoid::Value::kForward);
      climbSolenoid2->Set(frc::DoubleSolenoid::Value::kForward); 
      break;
    case 2:
      climbSolenoid1->Set(frc::DoubleSolenoid::Value::kReverse);
      climbSolenoid2->Set(frc::DoubleSolenoid::Value::kReverse);
      break;
  }
  
}

bool Climber::ClimbLimitSwitch() {
  printf(counter->Get() >0 ? "true\n" : "false\n");
  return counter->Get() >0;
  
}

double Climber::ClimbCurrentDraw1(){
  return pivotMotor1->GetOutputCurrent();
}

double Climber::ClimbCurrentDraw2(){
  return pivotMotor2->GetOutputCurrent();
}

void Climber::ClimbStartTimer(){
  timer->Start();
}

int Climber::ClimbGetTimer(){
  return (int)timer->Get();
}

void Climber::ClimbStopTimer(){
  timer->Stop();
}
  
} //namespace frc4783