/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ClimbHook.h"
#include "subsystems/Climber.h"



namespace frc4783 {

ClimbHook::ClimbHook(Climber* subsystem) : climber(subsystem){
        AddRequirements(subsystem);
}
void ClimbHook::Initialize() {
    climber->ClimbReset();
    climber->ClimbStartTimer();
    climber->ClimbPivotStage(1);
} 

void ClimbHook::Execute(){
    
} 

bool ClimbHook::IsFinished(){
    std::cout << "Timer: " << climber->ClimbGetTimer() << "\n";
    std::cout << "Current: " << climber->ClimbCurrentDraw2() << "\n";
    if (abs(climber->ClimbCurrentDraw2()) >= 10){
        End();
        return true;
    }else if(climber->ClimbGetTimer() >= 3){
        End();
        return true;
    }else if (climber->ClimbLimitSwitch()){
        End();
        return true; 
    }
    return false;

} 

void ClimbHook::End(){
    printf("ClimbHook End \n");
    climber->ClimbStopTimer();
    climber->ClimbPivotStage(2);
    climber->ClimbExtendStage(1); 
    //container->isExtended = true;      
}

void ClimbHook::Interrupted(){
   
} 

} 
