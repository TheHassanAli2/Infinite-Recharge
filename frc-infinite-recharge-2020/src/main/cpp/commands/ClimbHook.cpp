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
    climber->ClimbPivotStage(1);
    //climber->ClimbMotor(true);
} 

void ClimbHook::Execute(){
    
} 

bool ClimbHook::IsFinished(){
    return climber->ClimbLimitSwitch();
    //return false;
} 

void ClimbHook::End(){
climber->ClimbPivotStage(2); 
//container->isExtended = true;      
}

void ClimbHook::Interrupted(){
   
} 

} 
