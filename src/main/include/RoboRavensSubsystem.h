#ifndef ROBORAVENSSUBSYSTEM_H
#define ROBORAVENSSUBSYSTEM_H
#include <frc/Solenoid.h>
#include <frc/DoubleSolenoid.h>
#include <frc/SpeedController.h>
#include <frc2/command/Subsystem.h>
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <map>

namespace frc4783 {

class RoboRavensSubsystem : public frc2::Subsystem {    

public:
    enum MotorControllerType {
        VictorSPX,
        TalonSRX
    };

    enum SignalType {
        PWM,
        CAN
    };

    RoboRavensSubsystem();
    void InitializeMotor(int motorId, MotorControllerType motorType, SignalType signal, int portId);
    void InitDefaultCommand();
    void Reset();
    void SetMotorSpeed(int motorId, float speed);
    void SpinClockwise();
    void SpinCounterClockwise();
    void StopMotor();
    void Periodic() override;

    void InitializeSolenoid(int solenoidId, int forwardport, int reverseport);
    void SolenoidReset();
    void SolenoidMotor();
    void SetSolenoidDirection(int solenoidId, frc::DoubleSolenoid::Value solenoidValue);


protected:
#if 0
      std::shared_ptr<frc::SpeedController> m_motor1;
      std::shared_ptr<frc::SpeedController> m_motor2;
      std::shared_ptr<frc::SpeedController> m_motor3;
#endif

    std::map<int, std::shared_ptr<frc::SpeedController>> m_motors;

    std::map<int, std::shared_ptr<frc::DoubleSolenoid>> m_solenoids;

        
};

}  //namespace 4783

#endif // ROBORAVENSSUBSYSTEM_H