/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ClimbPivot.h"
#include "subsystems/Climber.h"


namespace frc4783 {

ClimbPivot::ClimbPivot(Climber* subsystem) : climber(subsystem){
        AddRequirements(subsystem);
        }
void ClimbPivot::Initialize() {
    climber->ClimbPivotStage(1);
    //climber->ClimbMotor(true);
} 

void ClimbPivot::Execute(){
    
} 

bool ClimbPivot::IsFinished(){
    return climber->ClimbLimitSwitch();
    //return false;
} 

void ClimbPivot::End(){
climber->ClimbPivotStage(2);       
}

void ClimbPivot::Interrupted(){
   
} 

} 
