#include <Robot.h>
#include <unistd.h>

std::unique_ptr<RobotContainer> Robot::robotcontainer;
std::shared_ptr<DriveTrain> Robot::drivetrain;

void Robot::RobotInit() {

    printf("%s  %d\n", __FUNCTION__, __LINE__);


    drivetrain.reset(new DriveTrain());
    robotcontainer.reset(new RobotContainer());

    printf("Robot init completed\n");
 

}

void Robot::AutonomousInit(){
if (m_autonomousCommand != nullptr)
        m_autonomousCommand->Cancel();
        m_autonomousCommand = nullptr;
}

void Robot::DisabledInit() {
    
}

void Robot::DisabledPeriodic() {
    frc2::CommandScheduler::GetInstance();
}

void Robot::AutonomousPeriodic() {
    frc2::CommandScheduler::Run();

}

void Robot::TeleopInit() {
    if (m_autonomousCommand != nullptr)
        m_autonomousCommand->Cancel();
        m_autonomousCommand = nullptr;


}

void Robot::TeleopPeriodic() {
    frc2::CommandScheduler::Run();
    DriveTrain.SetDefaultCommand(std::move(DriveWithJoystick));
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif