#include <Robot.h>
#include <unistd.h>

#include <frc2/command/PrintCommand.h>
#include <frc2/command/CommandScheduler.h>

#include <array>

#include <frc/AddressableLED.h>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
    m_led.SetLength(kLength);
    m_led.SetData(m_ledBuffer);
    m_led.Start();
}

void Robot::RobotPeriodic() { 
    frc2::CommandScheduler::GetInstance().Run();
    Red();
    // Set the LEDs
    m_led.SetData(m_ledBuffer);
}

void Robot::AutonomousInit(){
    if (m_autonomousCommand != nullptr){
            m_autonomousCommand->Cancel();
            m_autonomousCommand = nullptr;
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

void Robot::TeleopPeriodic(){
}    

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif