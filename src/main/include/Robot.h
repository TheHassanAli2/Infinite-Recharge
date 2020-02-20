
#ifndef ROBOT_H
#define ROBOT_H

#include <Constants.h>
#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>

// Vision includes
#include <cameraserver/CameraServer.h>
#include <thread>

// Subsystem includes
#include <RobotContainer.h>
//#include <subsystems/DriveTrain.h>

//namespace frc4783{
class Robot : public frc::TimedRobot {
    public:
    //frc::Command* autonomousCommand;
    
    //static std::unique_ptr<RobotContainer> robotcontainer;
    
    //static std::shared_ptr<DriveTrain> drivetrain;

    void RobotInit() override;
    void RobotPeriodic() override;
    void DisabledInit() override;
    void DisabledPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;

private:
    // Have it null by default so that if testing teleop it
    // doesn't have undefined behavior and potentially crash.
    frc2::Command* m_autonomousCommand = nullptr;
    //frc::SendableChooser<frc::Command*> m_chooser;

    frc4783::RobotContainer container;
};

//} // frc4783
#endif //ROBOT_H