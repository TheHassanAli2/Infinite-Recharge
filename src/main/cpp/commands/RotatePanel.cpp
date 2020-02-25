#include "subsystems/ControlPanel.h"
#include "commands/RotatePanel.h"
#include "Robot.h"

namespace frc4783 {

RotatePanel::RotatePanel(frc4783::ControlPanel* ctrlPanel)
    : controlpanelSubsystem(ctrlPanel),
      on(false) 
{
    printf("Rotate Panel ctor\n");
}

void RotatePanel::Initialize(){
    if (on ){
        // if the motor is on, turn it off
        controlpanelSubsystem->RotateControlPanel(0);
        on = false;
    }
    else {
        // if the motor is off, turn it on

        /**
         * @todo: configure the speed of the motor
         *        potentially use the joystick to control the speed of the motor
         */
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
}

} // namespace frc4783