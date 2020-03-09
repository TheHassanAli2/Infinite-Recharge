
#ifndef ROBOT_H
#define ROBOT_H
#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>
//#include <frc/SendableChooser.h>
#include "frc/smartdashboard/SendableChooser.h"
#include <frc/smartdashboard/SmartDashboard.h>
// Vision includes
//#include <cameraserver/CameraServer.h>
//#include <thread>

// Subsystem includes
#include <RobotContainer.h>
#include "commands/Auto.h"

class Robot : public frc::TimedRobot {
    public:
    frc2::Command* m_autonomousCommand = nullptr;
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
    frc::SendableChooser<frc2::Command*> auto_Chooser;
    //frc::smartdashboard::SendableChooser auto_Chooser;
    frc4783::RobotContainer robotcontainer;
};
#endif //ROBOT_H