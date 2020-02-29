/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ClimbHook.h"
#include "subsystems/Climber.h"



namespace frc4783 {

ClimbHook::ClimbHook(Climber* subsystem, RobotContainer* contained) : climber(subsystem), container(contained){
        AddRequirements(subsystem);
        }
void ClimbHook::Initialize() {
    if (climber->isExtended == true) {    						 
   		climber->ClimbExtendStage(2);
   	}
	else	{    				
   	  	climber->ClimbExtendStage(1); 							
	} 
} 

void ClimbHook::Execute(){
    
} 

bool ClimbHook::IsFinished(){
    return false;
} 

void ClimbHook::End(){
    climber->climbSolenoid1->Set(frc::DoubleSolenoid::Value::kOff);
    climber->climbSolenoid2->Set(frc::DoubleSolenoid::Value::kOff);
}

void ClimbHook::Interrupted(){
   
} 

} 
