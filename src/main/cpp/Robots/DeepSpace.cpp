#include "Robots/DeepSpace.h"
#include "subsystems/rrDriveTrain.h"
#include "subsystems/rrTwoSpeed.h"
#include "Frc4783Defs.h"

namespace frc4783 {
DeepSpace::DeepSpace(){
    motorControllerType motors;
    signalType signal;

    motors = VictorSPX;
    signal = CAN;

    m_drivetrain = new rrDriveTrain();
    m_drivetrain->InitializeMotors(VictorSPX, PWM);
} 
}//namespace frc4783