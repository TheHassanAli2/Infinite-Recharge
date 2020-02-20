#include "RoboravensSubsystem.h"
#include "commands/Solenoid.h"
#include "subsystems/ControlPanel.h"


Solenoid::Solenoid(frc4783::ControlPanel* Solenoid)
    : SolenoidSubsystem(Solenoid),
      extended(false) 
    {
      printf("Solenoid ctor\n");
    }

void Solenoid::Initialize(){
    printf("Solenoid cmd: initialize\n");
    if (extended ){
        SolenoidSubsystem->SetSolenoidDirection(frc::DoubleSolenoid::Value::kForward);
        extended = false;
    }
    else {
        SolenoidSubsystem->SetSolenoidDirection(frc::DoubleSolenoid::Value::kReverse);
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