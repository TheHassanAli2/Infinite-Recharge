/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ClimbRetract.h"
#include "subsystems/Climber.h"


namespace frc4783 {

ClimbRetract::ClimbRetract(Climber* subsystem) : climber(subsystem){
        AddRequirements(subsystem);
        }
void ClimbRetract::Initialize() {
    climber->ClimbExtendStage(2);  
    //climber->ClimbSolenoid(true);     
} 

void ClimbRetract::Execute(){
        
} 

bool ClimbRetract::IsFinished(){
    return false;
} 

void ClimbRetract::End(){
           
}

void ClimbRetract::Interrupted(){
   
} 

} 
