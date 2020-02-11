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
    }

void SpitIntake::Execute(){
    intake->Reverse();
} 

bool SpitIntake::IsFinished(){
    return false;
}

void SpitIntake::End(){
    intake->Stop();
}

void SpitIntake::Interrupted(){
    End();
}

void SpitIntake::Initialize() {
    
}

} /* namespace frc4783 */