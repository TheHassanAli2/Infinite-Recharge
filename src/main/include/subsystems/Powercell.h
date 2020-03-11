#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/SpeedController.h>
#include <frc/SpeedControllerGroup.h>
#include "ctre/Phoenix.h"
#include <math.h>
#include "frc/DigitalInput.h"
#include "frc/Servo.h"

namespace frc4783 {

class Powercell : public frc2::SubsystemBase {
        
    public:
        Powercell();
        void Turn();
        void Stop();
        void Reverse();
        bool cellCheck();
        int ballCheck;
        int ballNumber;
        void Periodic() override;
        void IntakeLogic();
        bool intakeCheck;
        bool tempStop = true;
        void ballReset();
        void OpenHatch();
        //void Turn45();
        //void Turn90Reverse();
        void Loading();
        void Close();
        void State();
        float speed;

   private:
        std::shared_ptr<frc::SpeedController> m_motor;
        std::shared_ptr<frc::DigitalInput> forwardLimitSwitch;
        std::shared_ptr<frc::DigitalInput> reverseLimitSwitch;
        std::shared_ptr<frc::Servo> OuttakeMotor;

    enum States{
        closed = 0,
        open = 1,
        loading = 2
    };

    enum States m_state;

    static const int OpenAngle;
    static const int LoadAngle;
    static const int ClosedAngle;

    //state m_state;

};
} // namespace 4783