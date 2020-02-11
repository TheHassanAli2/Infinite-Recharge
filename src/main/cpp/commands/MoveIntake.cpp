/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
 
#include "commands/MoveIntake.h"
#include "subsystems/Intake.h"

namespace frc4783 {

MoveIntake::MoveIntake(Intake* subsystem) : intake(subsystem){
        AddRequirements(subsystem);
    }

void MoveIntake::Execute(){
    intake->Turn();
} 

bool MoveIntake::IsFinished(){
    return false;
}

void MoveIntake::End(){
    intake->Stop();
}

void MoveIntake::Interrupted(){
    End();
}

void MoveIntake::Initialize() {
    
}

} /* namespace frc4783 */