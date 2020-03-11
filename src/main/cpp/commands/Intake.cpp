/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
 
#include "commands/Intake.h"
#include "subsystems/Powercell.h"

namespace frc4783 {

Intake::Intake(Powercell* subsystem) : powercell(subsystem){
        AddRequirements(subsystem);
        intake = false;
    }
void Intake::Initialize() {
     powercell->IntakeLogic();

} 

void Intake::Execute(){

} 

bool Intake::IsFinished(){
    return true;
}

void Intake::End(){
    powercell->Stop();

}

void Intake::Interrupted(){
    //End();
}



} /* namespace frc4783 */