#include "subsystems/Intake.h"
#include "frc/VictorSP.h"

namespace frc4783 {

Intake::Intake(){
    //Let's show everything on the LiveWindow
    m_motor.reset(new frc::VictorSP(6));
    m_motor->Set(0);
    forwardLimitSwitch.reset(new frc::DigitalInput(0));
    reverseLimitSwitch.reset(new frc::DigitalInput(2));
}


void Intake::Turn() {
     m_motor->Set(0.3); 
}

void Intake::Stop() { 
    m_motor->Set(0); 
}

void Intake::Reverse() { 
    m_motor->Set(-0.3); 
}

bool Intake::cellCheck() {
    return forwardLimitSwitch->Get();
}

void Intake::Periodic() {
     this->cellCheck();
    printf ("Periodic:  %d\n", this->ballNumber);
    if (this->cellCheck() == true) {
        this->ballCheck = 1;
    }else if (this->cellCheck() == false && this->ballCheck == 1){
        this->ballNumber ++;
        this->ballCheck = 0;
    }
}
} // namespace frc4783