#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/SpeedController.h>
#include <frc/SpeedControllerGroup.h>
#include "ctre/Phoenix.h"
#include <math.h>
#include "frc/DigitalInput.h"

namespace frc4783 {

class Intake : public frc2::SubsystemBase {
        
    public:
        Intake();
        void Turn();
        void Stop();
        void Reverse();
        bool cellCheck();
        int ballCheck;
        int ballNumber;
        void Periodic() override;

   private:
        std::shared_ptr<frc::SpeedController> m_motor;
        std::shared_ptr<frc::DigitalInput> forwardLimitSwitch;
        std::shared_ptr<frc::DigitalInput> reverseLimitSwitch;
 
};
} // namespace 4783