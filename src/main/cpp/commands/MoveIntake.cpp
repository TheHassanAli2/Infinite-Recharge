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
            intakeCheck = false;
    }
void MoveIntake::Initialize() {
     if (intake->ballNumber<6){
        if (intakeCheck){
            intake->Stop();
            intakeCheck = false;
        }
        else {
            intake->Turn();
            intakeCheck = true;
        }   
    }else{
        intake->Stop();
    }   
}

void MoveIntake::Execute(){
   
} 

bool MoveIntake::IsFinished(){
    return true;
}

void MoveIntake::End(){
    intake->Stop();

}

void MoveIntake::Interrupted(){
    //End();
}



} /* namespace frc4783 */