#include "subsystems/ControlPanel.h"
#include "commands/RotatePanel.h"
#include "Robot.h"

namespace frc4783 {

RotatePanel::RotatePanel(frc4783::ControlPanel* ctrlPanel)
    : CPSubsystem(ctrlPanel),
      on(false) 
{
    printf("Rotate Panel ctor\n");
}

void RotatePanel::Initialize(){
    if (on ){
        // if the motor is on, turn it off
        CPSubsystem->RotateControlPanel(0);
        on = false;
    }
    else {
        // if the motor is off, turn it on

        /**
         * @todo: configure the speed of the motor
         *        potentially use the joystick to control the speed of the motor
         */
        CPSubsystem->RotateControlPanel(0.5);
        on = true;
    }

    printf("RotatePanel::initialize: %d\n", on);
}

void RotatePanel::Execute(){
    CPSubsystem->DetectRotation();
    //CPSubsystem->something = false;
    if (CPSubsystem->something){
        CPSubsystem->RotateControlPanel(0);
    } else {
        CPSubsystem->RotateControlPanel(0.5);
    }
    if(CPSubsystem->something){
        End();
    }
    
}

void RotatePanel::Interrupted(){
    printf("RotatePanel::interrupted\n");
}

void RotatePanel::End() {
    printf("RotatePanel::end\n");
    

}
} // namespace frc4783