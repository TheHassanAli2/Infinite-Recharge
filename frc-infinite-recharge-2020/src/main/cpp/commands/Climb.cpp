/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Climb.h"

Climb::Climb(Climber* subsystem, RobotContainer* contained) : climber(subsystem), container(contained){
        AddRequirements(subsystem);
    }
void Climb::Initialize() {
    
}

void Climb::Execute(){
        
} 

bool Climb::IsFinished(){
    
}

void Climb::End(){
    
}

void Climb::Interrupted(){
   
} 
