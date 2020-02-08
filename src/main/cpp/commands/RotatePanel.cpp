/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include "subsystems/ControlPanel.h"
#include "commands/RotatePanel.h"
#include "Robot.h"

RotatePanel::RotatePanel(frc4783::ControlPanel* ctrlPanel)
    : controlpanelSubsystem{ctrlPanel} {
printf("Rotate Panel ctor\n");
}

void RotatePanel::Initialize(){
    //SetTimeout(3);
        controlpanelSubsystem->SetMotorSpeed(0.5);
}
    
void RotatePanel::Execute(){
     //frc::SmartDashboard::PutNumber("PiVoTeNcODeR",controlpanelSubsystem->SpinClockwise());
}

bool RotatePanel::IsFinished(){
    //if (IsTimedOut()) {
    //printf("%s  %d TIMEOUT \n", __FUNCTION__, __LINE__);
    return false;
 
}

void RotatePanel::End(){

}

void RotatePanel::Interrupted(){

}