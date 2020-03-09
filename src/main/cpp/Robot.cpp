#include <Robot.h>
#include <unistd.h>

#include <frc2/command/PrintCommand.h>
#include <frc2/command/CommandScheduler.h>

//ya feel?

void Robot::RobotInit() {

    printf("%s  %d\n", __FUNCTION__, __LINE__);


    //drivetrain.reset(newrrTwoSpeed());
    //robotcontainer.reset(new RobotContainer());

    frc2::PrintCommand("yo wussup 22").Schedule();

    auto_Chooser.SetDefaultOption("Auto 1", new Auto(1));
    auto_Chooser.AddOption("Auto 2", new Auto(2));
    //auto_Chooser.AddOption("Auto 3", new auto_3());
    //auto_Chooser.AddOption("Auto 4", new auto_4());
    frc::SmartDashboard::PutData("Autonomous Mode:", &auto_Chooser);
    
}

void Robot::RobotPeriodic() { frc2::CommandScheduler::GetInstance().Run();}

void Robot::AutonomousInit(){
    m_autonomousCommand = auto_Chooser.GetSelected();

    if (m_autonomousCommand != nullptr) {
        m_autonomousCommand->Schedule();
    }
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

void Robot::TeleopPeriodic(){}


void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
