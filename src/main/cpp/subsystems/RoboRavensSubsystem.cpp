#include "subsystems/RoboRavensSubsystem.h"
#include <frc/DoubleSolenoid.h>
#include <frc/VictorSP.h>
#include <frc/Talon.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>

namespace frc4783 {

RoboRavensSubsystem::RoboRavensSubsystem(){
 printf ("RoboRavensSubsystem complete\n");
}
 
void frc4783::RoboRavensSubsystem::InitializeMotor(int motorId, MotorControllerType motorType, SignalType signal, int portId) 
{
    /**
     * Instantiate an appropriate frc::SpeedController object, and store in m_motors, indexed by motorId
     */

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

}

void frc4783::RoboRavensSubsystem::InitializeSolenoid(int solenoidId, int forwardport, int reverseport){
    
    /**
     * Instantiate an frc::DoubleSolenoid object, and store in m_solenoids, indexed by solenoidId
     */
    frc:: DoubleSolenoid * solenoid = new frc::DoubleSolenoid(forwardport, reverseport);

    std::shared_ptr<frc::DoubleSolenoid> dsptr;
    dsptr.reset(solenoid);

    m_solenoids[solenoidId] = dsptr;
}

void frc4783::RoboRavensSubsystem::InitDefaultCommand(){
    
}

void frc4783::RoboRavensSubsystem::Reset(){

}

void frc4783::RoboRavensSubsystem::SetMotorSpeed(int motorId, float speed)
{
    /**
     * find the motor based on motorId, then set the speed
     */
    std::map<int, std::shared_ptr<frc::SpeedController>>::iterator iter = m_motors.find(motorId);
    if (iter != m_motors.end()) {
        std::shared_ptr<frc::SpeedController> sptr = iter->second;
        sptr->Set(speed);
    }

} 

void frc4783::RoboRavensSubsystem::SpinClockwise(){
}

void frc4783::RoboRavensSubsystem::SpinCounterClockwise(){
}
        
void frc4783::RoboRavensSubsystem::StopMotor(){
}

void frc4783::RoboRavensSubsystem::Periodic(){

}  

void frc4783:: RoboRavensSubsystem:: SetSolenoidDirection(int solenoidId, frc::DoubleSolenoid::Value solenoidValue){

    /**
     * find the solenoid by solendoiId, the set the solendoid direction
     */
    std::map<int, std::shared_ptr<frc::DoubleSolenoid>>::iterator iter = m_solenoids.find(solenoidId);
    if (iter != m_solenoids.end()) {
        std::shared_ptr<frc::DoubleSolenoid> dsptr = iter->second;
        dsptr->Set(solenoidValue);
        }
} 

}// namespace frc4783


