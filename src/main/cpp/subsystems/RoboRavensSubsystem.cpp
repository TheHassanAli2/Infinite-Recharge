#include "RoboRavensSubsystem.h"
#include <frc/VictorSP.h>
#include <frc/Talon.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>

namespace frc4783 {

RoboRavensSubsystem::RoboRavensSubsystem(){

}
 
void RoboRavensSubsystem::InitializeMotor(int motorId, MotorControllerType motorType, SignalType signal, int portId) {
    frc:: SpeedController * controller = nullptr;

  if ( (motorType == VictorSPX) && (signal == CAN) )
   {
        controller = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(portId);

    }
    else if ( (motorType == TalonSRX) && (signal == CAN) ) {
        controller = new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(portId);     
    
     }
     else if ( (motorType == VictorSPX) && (signal == PWM) ) {
        controller = (new frc::VictorSP(portId));
    
    }
    else if ( (motorType == TalonSRX) && (signal == PWM) ) {
        controller = (new frc::Talon(portId));
  
    }



    switch(motorId) {
    case 1: {
        m_motor1.reset(controller);
        break;
        }

    case 2: {
        m_motor2.reset(controller);
        break;
        }
    case 3: {
        m_motor3.reset(controller);
        break;
        }
    default:
        break;
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

}// namespace frc4783

