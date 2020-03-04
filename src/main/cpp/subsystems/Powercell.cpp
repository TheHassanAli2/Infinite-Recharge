#include "subsystems/Powercell.h"
#include "frc/VictorSP.h"

namespace frc4783 {

Powercell::Powercell(){
    //Let's show everything on the LiveWindow
    m_motor.reset(new frc::VictorSP(6));
    m_motor->Set(0);
    forwardLimitSwitch.reset(new frc::DigitalInput(0));
    reverseLimitSwitch.reset(new frc::DigitalInput(2));
}

void Powercell::IntakeLogic() {
    if (this->ballNumber<6){
        if (this->intakeCheck){
            this->Stop();
            this->intakeCheck = false;
        }
        else {
            this->Turn();
            this->intakeCheck = true;
        }   
    }else{
        this->Stop();
    }   
}

void Powercell::Turn() {
     m_motor->Set(0.3); 
}

void Powercell::Stop() { 
    m_motor->Set(0); 
}

void Powercell::Reverse() { 
    m_motor->Set(-0.3); 
}

void Powercell::ballReset() {
    ballNumber = 0;
    tempStop = true;
}

bool Powercell::cellCheck() {
    return forwardLimitSwitch->Get();
}

void Powercell::Periodic() {
     this->cellCheck();
    printf ("Periodic:  %d\n", this->ballNumber);
    if (this->cellCheck() == true) {
        this->ballCheck = 1;
    }else if (this->cellCheck() == false && this->ballCheck == 1){
        this->ballNumber ++;
        this->ballCheck = 0;
    }
    
    if (this->ballNumber == 6 && tempStop == true) {
        this->IntakeLogic();
        tempStop = false;
    }
}
} // namespace frc4783