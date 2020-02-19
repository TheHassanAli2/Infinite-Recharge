#include "RoboRavensSubsystem.h"
#include <frc/VictorSP.h>
#include <frc/Talon.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>

namespace frc4783 {

RoboRavensSubsystem::RoboRavensSubsystem(){

}
 
void frc4783::RoboRavensSubsystem::InitializeMotor(int motorId, MotorControllerType motorType, SignalType signal, int portId) 
{
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

    std::shared_ptr<frc::SpeedController> sptr;
    sptr.reset(controller);

    m_motors[motorId] = sptr;

#if 0
    switch(motorId) {
     case 0: {
        m_motor1.reset(controller);
        break;
        }

     case 1: {
        m_motor2.reset(controller);
        break;
        }
     case 2: {
        m_motor3.reset(controller);
        break;
        }
     default:
        break;
    }
#endif
}

void frc4783::RoboRavensSubsystem::InitDefaultCommand(){
    
}

void frc4783::RoboRavensSubsystem::Reset(){

}

void frc4783::RoboRavensSubsystem::SetMotorSpeed(int motorId, float speed)
{

    std::map<int, std::shared_ptr<frc::SpeedController>>::iterator iter = m_motors.find(motorId);
    if (iter != m_motors.end()) {
        std::shared_ptr<frc::SpeedController> sptr = iter->second;
        sptr->Set(speed);
    }

#if 0
    switch (motorId) {
     case 0: {
        m_motor1->Set(speed);
        break;
        }
        
     case 1: { 
        m_motor2->Set(speed);
        break;
        }
        
     case 2: {
        m_motor3-> Set(speed);
        break;
        }
        
     default: 
        break;
        }
#endif    
} 

void frc4783::RoboRavensSubsystem::SpinClockwise(){
}

void frc4783::RoboRavensSubsystem::SpinCounterClockwise(){
}
        
void frc4783::RoboRavensSubsystem::StopMotor(){
}

void frc4783::RoboRavensSubsystem::Periodic(){

}  

} // namespace frc4783

