#include "Robots/PowerUp.h"
#include "Frc4783Defs.h"

namespace frc4783 {
PowerUp::PowerUp(){
    motorControllerType motors;
    signalType signal;

    motors = VictorSPX;
    signal = CAN;

    m_drivetrain = new rrDriveTrain();
    m_drivetrain->InitializeMotors(motors, signal);
} 
}//namespace frc4783