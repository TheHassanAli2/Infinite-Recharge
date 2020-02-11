#include "subsystems/Intake.h"
#include "frc/VictorSP.h"
Intake::Intake(){
    //Let's show everything on the LiveWindow
    m_motor.reset(new frc::VictorSP(0));
}

void Intake::Turn() {
     m_motor->Set(1); 
}

void Intake::Stop() { 
    m_motor->Set(0); 
}

void Intake::Reverse() { 
    m_motor->Set(-1); 
}
