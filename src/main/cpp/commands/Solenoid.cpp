#include "commands/Solenoid.h"
#include "subsystems/ControlPanel.h"

namespace frc4783 {

Solenoid::Solenoid(frc4783::ControlPanel* Solenoid)
    : SolenoidSubsystem(Solenoid),
      extended(false) 
{
    printf("Solenoid ctor\n");
}

void Solenoid::Initialize(){
    printf("Solenoid cmd: initialize\n");
    if (extended){
        /**
         *  if the pnuematic cylinder is extended, retract it
         */
        SolenoidSubsystem->SetSolenoidDirection(frc::DoubleSolenoid::Value::kReverse);
        extended = false;
    }
    else {
        /**
         *  if the pnuematic cylinder is retracted, extend it
         */
        SolenoidSubsystem->SetSolenoidDirection(frc::DoubleSolenoid::Value::kForward);
        extended = true;
    }

    printf("RotatePanel::initialize: %d\n", extended);
}

void Solenoid::Execute(){

}

bool Solenoid::IsFinished(){
    printf("Solenoid::isFinished\n");
    return true;
}

void Solenoid::Interrupted(){
    printf("Solenoid::interrupted\n");
}

void Solenoid::End() {
    printf("Solenoid::end\n");
}

} // namespace frc4783