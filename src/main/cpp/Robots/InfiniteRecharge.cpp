#include "Robots/InfiniteRecharge.h"
#include "Frc4783Defs.h"

namespace frc4783 {
InfiniteRecharge::InfiniteRecharge(){
    motorControllerType motors;
    signalType signal;

    motors = VictorSPX;
    signal = CAN;

    m_drivetrain = new rrTwoSpeed();
    m_drivetrain->InitializeMotors(motors, signal);

    m_controlPanel = new ControlPanel();

    frc2::CommandScheduler::GetInstance().RegisterSubsystem(m_controlPanel);

     printf ("InfiniteRecharge complete\n");
} 

} // namespace frc4783