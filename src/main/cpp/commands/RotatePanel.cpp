#include "subsystems/ControlPanel.h"
#include "commands/RotatePanel.h"
#include "Robot.h"



RotatePanel::RotatePanel(frc4783::ControlPanel* ctrlPanel)
    : controlpanelSubsystem(ctrlPanel),
      on(false) 
    {
      printf("Rotate Panel ctor\n");
    }

void RotatePanel::Initialize(){
    if (on ){
        controlpanelSubsystem->RotateControlPanel(0);
        on = false;
    }
    else {
        controlpanelSubsystem->RotateControlPanel(0.5);
        on = true;
    }

    printf("RotatePanel::initidialize: %d\n", on);
}
    
void RotatePanel::Execute(){
     
}

bool RotatePanel::IsFinished(){
    printf("RotatePanel::isFinished\n");
    return true;

}

void RotatePanel::Interrupted(){
printf("RotatePanel::interrupted\n");
}

void RotatePanel::End() {
    printf("RotatePanel::end\n");
controlpanelSubsystem->StopMotor();
}
