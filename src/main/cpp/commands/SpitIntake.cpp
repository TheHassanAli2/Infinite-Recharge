/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
 
#include "commands/SpitIntake.h"
#include "subsystems/Intake.h"

namespace frc4783 {

SpitIntake::SpitIntake(Intake* subsystem) : intake(subsystem){
        AddRequirements(subsystem);
            intakeCheck = false;
    }
void SpitIntake::Initialize() {
    if (intakeCheck ){
        intake->Stop();
        intakeCheck = false;
    }
    else {
        intake->Reverse();
        intakeCheck = true;
    }

}

void SpitIntake::Execute(){

} 

bool SpitIntake::IsFinished(){
    return true;
}

void SpitIntake::End(){
    intake->Stop();
}

void SpitIntake::Interrupted(){
    //End();
}

} /* namespace frc4783 */