#include "RoboRavensSubsystem.h"
#include <frc/VictorSP.h>
#include <frc/Talon.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>

namespace frc4783 {

RoboRavensSubsystem::RoboRavensSubsystem(){
    if (MotorType == frc::VictorSP){
        m_motor1.reset(new frc::VictorSP(0));
        m_motor2.reset(new frc::VictorSP(1));
        m_motor3.reset(new frc::VictorSP(2));
    } else if (MotorType == frc::Talon){
        m_motor1.reset(new frc::Talon(0));
        m_motor2.reset(new frc::Talon(1));
        m_motor3.reset(new frc::Talon(2));
    } else if (MotorType == ctre::phoenix::motorcontrol::can::VictorSPX){
        m_motor1.reset(new WPI_VictorSPX(0));
    }
}

void RoboRavensSubsystem::InitDefaultCommand(){
    
}
    
void RoboRavensSubsystem::Reset(){

}

void RoboRavensSubsystem::SetMotorSpeed(int motorId, float speed){
    
    switch (motorId) {
        case 1: {
            m_motor1->Set(speed);
            break;
        }
        case 2: { 
            m_motor2->Set(speed);
            break;
        }
        case 3: {
            m_motor3-> Set(speed);
            break;
        }
         default: 
            break;
    }
    
}

void RoboRavensSubsystem::SpinClockwise(){
}

void RoboRavensSubsystem::SpinCounterClockwise(){
}
        
void RoboRavensSubsystem::StopMotor(){
}

void RoboRavensSubsystem::Periodic(){

}  

} // namespace frc4783