#include "Robots/Steamworks.h"

namespace frc4783 {
Steamworks::Steamworks(){
    motorControllerType motors;
    signalType signal;

    motors = VictorSPX;
    signal = CAN;

    m_drivetrain = new rrDifferentialDrive();
    m_drivetrain->InitializeMotors(motors, signal);

     printf ("Steamworks complete\n");
} 
}//namespace frc4783