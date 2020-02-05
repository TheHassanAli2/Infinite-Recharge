/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Climb.h"


namespace frc4783 {

Climb::Climb(Climber* subsystem, RobotContainer* contained) : climber(subsystem), container(contained){
        AddRequirements(subsystem);
        bool mode = true;
        }
void Climb::Initialize() {
    if (mode == true){
        climber->ClimbPart1();
    }
    else {
        climber->ClimbPart2();
    }
}

void Climb::Execute(){
        
} 

bool Climb::IsFinished(){
    
}

void Climb::End(){
    
}

void Climb::Interrupted(){
   
} 

} //namespace frc4783
