/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ClimbExtend.h"
#include "subsystems/Climber.h"



namespace frc4783 {

ClimbExtend::ClimbExtend(Climber* subsystem) : climber(subsystem){
        AddRequirements(subsystem);
        }
void ClimbExtend::Initialize() {   				
   	  	climber->ClimbExtendStage(1); 							
} 

void ClimbExtend::Execute(){
    
} 

bool ClimbExtend::IsFinished(){
    climber->climbSolenoid1->Set(frc::DoubleSolenoid::Value::kOff);
    climber->climbSolenoid2->Set(frc::DoubleSolenoid::Value::kOff);
    return true;
} 

void ClimbExtend::End(){

}

void ClimbExtend::Interrupted(){
   
} 

} 
