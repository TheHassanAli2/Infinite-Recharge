#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/SpeedController.h>
#include <frc/SpeedControllerGroup.h>
#include "ctre/Phoenix.h"


class Intake : public frc2::SubsystemBase {
    private:
        std::shared_ptr<frc::SpeedController> m_motor;
    public:
        Intake();
        void Turn();
        void Stop();
        void Reverse();
};