#include "Robots/Protocase.h"
#include "subsystems/rrDriveTrain.h"
#include "subsystems/rrTwoSpeed.h"
#include "Frc4783Defs.h"

namespace frc4783 {
Protocase::Protocase(){
    motorControllerType motors;
    signalType signal;

    motors = VictorSPX;
    signal = CAN;

    m_drivetrain = new rrTwoSpeed();
    m_drivetrain->InitializeMotors(motors, signal);

     printf ("Protocase complete\n");
}  
}//namespace frc4783