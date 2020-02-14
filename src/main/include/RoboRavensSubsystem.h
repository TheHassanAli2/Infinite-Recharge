#include <frc/Solenoid.h>
#include <frc/SpeedController.h>
#include <frc2/command/Subsystem.h>
//#include <frc2/command/CommandBase.h>
//#include <frc2/command/CommandHelper.h> 

namespace frc4783 {

class RoboRavensSubsystem : public frc2::Subsystem {    

    enum MotorControllerTypes {
        VictorSPX,
        TalonSRX
    };

    enum SignalType {
        PWM,
        CAN
    };

    public:
        RoboRavensSubsystem();
        void InitDefaultCommand();
        void Reset();
        void SetMotorSpeed(int motorId, float speed);
        void SpinClockwise();
        void SpinCounterClockwise();
        void StopMotor();
        void Periodic() override;


    protected:
        std::shared_ptr<frc::SpeedController> m_motor1;
        std::shared_ptr<frc::SpeedController> m_motor2;
        std::shared_ptr<frc::SpeedController> m_motor3;

        std::shared_ptr<frc::Solenoid> m_solenoid1;
        std::shared_ptr<frc::Solenoid> m_solenoid2; 
        std::shared_ptr<frc::Solenoid> m_solenoid3; 

        int MotorType;         
};

}  //namespace 4783