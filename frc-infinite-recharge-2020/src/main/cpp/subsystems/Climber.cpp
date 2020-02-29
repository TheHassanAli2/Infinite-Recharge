/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Climber.h"
#include <frc/DoubleSolenoid.h>
#include "commands/ClimbHook.h" 

namespace frc4783{

Climber::Climber() {
  
  /*pivotMotor1.reset(new frc::VictorSP(4));
  pivotMotor2.reset(new frc::VictorSP(5));*/
  climbSolenoid1.reset(new frc::DoubleSolenoid(0,1));
  climbSolenoid2.reset(new frc::DoubleSolenoid(4,5)); //Actually 2 & 3

  isExtended = false;
  //pivotMotor2->SetInverted(true);
}

void Climber::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void Climber::ClimbReset(){
  climbSolenoid1->Set(frc::DoubleSolenoid::Value::kReverse);
  climbSolenoid2->Set(frc::DoubleSolenoid::Value::kReverse);
}


void Climber::ClimbSolenoid(bool extended) {
  if (extended == true){
    climbSolenoid2->Set(frc::DoubleSolenoid::Value::kForward);
  }
  else {
    climbSolenoid2->Set(frc::DoubleSolenoid::Value::kReverse);
  }
}

void Climber::ClimbExtendStage(int extendStage) {
  switch (extendStage){
    case 1:
      if (climbSolenoid1 != nullptr && climbSolenoid2 != nullptr){
        climbSolenoid1->Set(frc::DoubleSolenoid::Value::kForward);
        climbSolenoid2->Set(frc::DoubleSolenoid::Value::kForward); 
        isExtended = true; 
      }
      break;
    case 2:
      if (climbSolenoid1 != nullptr && climbSolenoid2 != nullptr){
        climbSolenoid1->Set(frc::DoubleSolenoid::Value::kReverse);
        climbSolenoid2->Set(frc::DoubleSolenoid::Value::kReverse);
        isExtended = false;
      }
      break;
  }
  
}
  
}



 //namespace frc4783
