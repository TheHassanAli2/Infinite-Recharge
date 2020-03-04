#include "Robots/DeepSpace.h"

namespace frc4783 {
DeepSpace::DeepSpace(){
    motorControllerType motors;
    signalType signal;

    motors = VictorSPX;
    signal = CAN;

    m_drivetrain = new rrTwoSpeed();
    m_drivetrain->InitializeMotors(motors, signal);

    printf ("DeepSpace complete\n");
} 
}//namespace frc4783