#ifndef ROBORAVENSSUBSYSTEM_H
#define ROBORAVENSSUBSYSTEM_H
#include <frc/Solenoid.h>
#include <frc/DoubleSolenoid.h>
#include <frc/SpeedController.h>
#include <frc2/command/Subsystem.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <map>
#include "Frc4783Defs.h"

namespace frc4783 {

class RoboRavensSubsystem : public frc2::Subsystem {

public:

    RoboRavensSubsystem();

    /**
     * Initialize an frc::SpeedController object
     * 
     * @param motorId  indicates the motorId
     * @param motorType  indicates the type of motor controller to instantiate
     * @param signalType  indicates the signalling type (PWM or CAN)
     * @param portId  indicate the PWM port ID or the CAN device ID
     */
    void InitializeMotor(int motorId, motorControllerType motorType, signalType signal, int portId);
    void InitDefaultCommand();
    void Reset();

    /**
     * Set the motor speed
     * 
     * @param motorId  indicates the motor to modify
     * @param speed  indicates the speed of the motor (negative or positive for direction of rotation)
     */
    void SetMotorSpeed(int motorId, float speed);

    void SpinClockwise();
    void SpinCounterClockwise();
    void StopMotor();
    void Periodic() override;

    /**
     * Initialize an frc::DoubleSolenoid object
     * 
     * @todo support frc::Solenoid (single solenoid) object
     * 
     * @param solenoidId  indicates the solenoidId
     * @param forwardPort  indicates the forward port on the double solenoid
     * @param reversePort  indicates the reverse port on the double solenoid
     */
    void InitializeSolenoid(int solenoidId, int forwardport, int reverseport);
    void SolenoidReset();
    void SolenoidMotor();

    /**
     * Set the solenoid direction
     * 
     * @param solenoidId  indicates the solenoid to modify
     * @param solenoidValue  indicate the direction (kOff, kForward, kReverse)
     */
    void SetSolenoidDirection(int solenoidId, frc::DoubleSolenoid::Value solenoidValue);


protected:
    /**
     * Map of frc::SpeedContorller objects, indexed by motorId
     */
    std::map<int, std::shared_ptr<frc::SpeedController>> m_motors;

    /**
     * Map of frc::DoubleSolenoid objects, indexed by solenoidId
     * @todo: change to frc::Solenoid objects, since solenoids could also be
     *        frc::Solenoid (single solenoid) object
     */
    std::map<int, std::shared_ptr<frc::DoubleSolenoid>> m_solenoids;

};

}  //namespace 4783

#endif // ROBORAVENSSUBSYSTEM_H