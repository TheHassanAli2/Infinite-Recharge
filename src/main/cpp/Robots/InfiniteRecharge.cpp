#include "Robots/InfiniteRecharge.h"
#include "subsystems/rrDriveTrain.h"
#include "subsystems/rrTwoSpeed.h"
#include "Frc4783Defs.h"

namespace frc4783 {
InfiniteRecharge::InfiniteRecharge(){
    motorControllerType motors;
    signalType signal;

    motors = VictorSPX;
    signal = CAN;

    m_drivetrain = new rrDriveTrain();
    m_drivetrain->InitializeMotors(VictorSPX, CAN);

    m_controlPanel = new ControlPanel();
} 

} // namespace frc4783