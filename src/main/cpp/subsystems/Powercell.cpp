#include "subsystems/Powercell.h"
#include "frc/VictorSP.h"
#include "frc/Servo.h"

namespace frc4783 {

Powercell::Powercell(){
    //Let's show everything on the LiveWindow
    m_motor.reset(new frc::VictorSP(6));
    m_motor->Set(0);
    forwardLimitSwitch.reset(new frc::DigitalInput(0));
    reverseLimitSwitch.reset(new frc::DigitalInput(2));
    OuttakeMotor.reset(new frc::Servo(5));
    OuttakeMotor->SetAngle(0);   
    m_state = closed; 

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
    #if 0
     this->cellCheck();
  //  printf ("Periodic:  %d\n", this->ballNumber);
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
    #endif
}

void Powercell::Turn90(){
    OuttakeMotor->SetAngle(120);
}

void Powercell::Turn45(){
    OuttakeMotor->SetAngle(60);
}

void Powercell::Turn90Reverse(){
    OuttakeMotor->SetAngle(-120);
}

void Powercell::Turn45Reverse(){
    OuttakeMotor->SetAngle(-60);
}

void Powercell::State(){
    switch (m_state){
        case closed:
            OuttakeMotor->SetAngle(120);
            m_state = open;
            break;
        case open:
            OuttakeMotor->SetAngle(-60);
            m_state = loading;
            break;
        case loading:
            OuttakeMotor->SetAngle(-60);
            m_state = closed;
            break;
        default:
            break;
    }
}

} // namespace frc4783