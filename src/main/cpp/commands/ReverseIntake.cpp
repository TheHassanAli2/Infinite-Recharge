/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
 
#include "commands/ReverseIntake.h"
#include "subsystems/Powercell.h"

namespace frc4783 {

ReverseIntake::ReverseIntake(Powercell* subsystem) : powercell(subsystem){
        AddRequirements(subsystem);
            intakeCheck = false;
    }
void ReverseIntake::Initialize() {
    if (intakeCheck ){
        powercell->Stop();
        intakeCheck = false;
    }
    else {
        powercell->Reverse();
        intakeCheck = true;
    }

}

void ReverseIntake::Execute(){

} 

bool ReverseIntake::IsFinished(){
    return true;
}

void ReverseIntake::End(){
    powercell->Stop();
}

void ReverseIntake::Interrupted(){
    //End();
}

} /* namespace frc4783 */