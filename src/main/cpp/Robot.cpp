#include <Robot.h>
#include <unistd.h>

#include <frc2/command/PrintCommand.h>
#include <frc2/command/CommandScheduler.h>

//ya feel?

void Robot::RobotInit() {

    printf("%s  %d\n", __FUNCTION__, __LINE__);


    //drivetrain.reset(newrrTwoSpeed());
    //robotcontainer.reset(new RobotContainer());

    frc2::PrintCommand("yo wussup  22").Schedule();
    
}

void Robot::RobotPeriodic() {
    frc2::CommandScheduler::GetInstance().Run();
}

void Robot::AutonomousInit() {

}

void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {

}

void Robot::AutonomousPeriodic() {

}

void Robot::TeleopInit() {
    if (m_autonomousCommand != nullptr){
        m_autonomousCommand->Cancel();
        m_autonomousCommand = nullptr;
    }
}

void Robot::TeleopPeriodic(){
}

void Robot::TestPeriodic() {
}


#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif