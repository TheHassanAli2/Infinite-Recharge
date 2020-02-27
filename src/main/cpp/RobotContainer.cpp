/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "ctre/Phoenix.h"
#include "commands/DriveWithJoystick.h"


namespace frc4783{

frc4783::RobotContainer::RobotContainer()
    : kDriveKinematics{DriveConstants::kTrackwidth}
{
    drivetrain.SetDefaultCommand(std::move(frc4783::DriveWithJoystick(&drivetrain, this)));
    ConfigureButtonBindings();
}
void frc4783::RobotContainer::ConfigureButtonBindings()
{
    // Drive Stick Buttons
    aButtonP = new frc::JoystickButton(&xbox,1);
    bButtonP = new frc::JoystickButton(&xbox, 2);
    xButtonP = new frc::JoystickButton(&xbox, 3);
    yButtonP = new frc::JoystickButton(&xbox, 4);
    leftBumperButtonP = new frc::JoystickButton(&xbox, 5);
    rightBumperButtonP = new frc::JoystickButton(&xbox, 6);
    selectButtonP = new frc::JoystickButton(&xbox, 7);
    startButtonP = new frc::JoystickButton(&xbox, 8);
    leftStickButtonP = new frc::JoystickButton(&xbox, 9);
    rightStickButtonP = new frc::JoystickButton(&xbox, 10);

    // Drive Stick Buttons
    xButtonS = new frc::JoystickButton(&ps4, 1);			 //'[]' on PS
    aButtonS = new frc::JoystickButton(&ps4, 2);			 //'X' on PS
    bButtonS = new frc::JoystickButton(&ps4, 3);			 //'O' on PS
    yButtonS = new frc::JoystickButton(&ps4, 4);			 //'/\' on PS
    leftBumperButtonS = new frc::JoystickButton(&ps4, 5);   //'L1' on PS
    rightBumperButtonS = new frc::JoystickButton(&ps4, 6);  //'R1' on PS
    leftTriggerButtonS = new frc::JoystickButton(&ps4, 7);  //'L2' on PS
    rightTriggerButtonS = new frc::JoystickButton(&ps4, 8); //'R2' on PS
    selectButtonS = new frc::JoystickButton(&ps4, 9);		 //'Share/Back' on PS
    startButtonS = new frc::JoystickButton(&ps4, 10);		 //'Start' on PS
    leftStickButtonS = new frc::JoystickButton(&ps4, 11);   //'L3' on PS
    rightStickButtonS = new frc::JoystickButton(&ps4, 12);  //'R3' on PS
    homeButtonS = new frc::JoystickButton(&ps4, 13);		 //'PS' on PS
}

frc2::Command* frc4783::RobotContainer::GetAutonomousCommand() {
    // Create a voltage constraint to ensure we don't accelerate too fast
    frc::DifferentialDriveVoltageConstraint autoVoltageConstraint(
        frc::SimpleMotorFeedforward<units::meters>(DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
        kDriveKinematics, 10_V);


    // Set up config for trajectory
    frc::TrajectoryConfig config(DriveConstants::kMaxSpeed,
                               DriveConstants::kMaxAcceleration);
    // Add kinematics to ensure max speed is actually obeyed
    config.SetKinematics(kDriveKinematics);
    // Apply the voltage constraint
    config.AddConstraint(autoVoltageConstraint);

    frc::filesystem::GetDeployDirectory(deployDirectory);
    wpi::sys::path::append(deployDirectory, "paths");
    wpi::sys::path::append(deployDirectory, "Circle.wpilib.json");
    frc::filesystem::GetDeployDirectory(deployDirectory);

    frc::Trajectory exampleTrajectory = frc::TrajectoryUtil::FromPathweaverJson(deployDirectory);

    frc2::RamseteCommand ramseteCommand(
        exampleTrajectory, 
        [this]() { return drivetrain.GetPose(); },
        frc::RamseteController(DriveConstants::kRamseteB, DriveConstants::kRamseteZeta),
        frc::SimpleMotorFeedforward<units::meters>(DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
        kDriveKinematics,
        [this] { return drivetrain.GetWheelSpeeds(); },
        frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
        frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
        [this](auto left, auto right) { drivetrain.TankDriveVolts(left, right); },
        {&drivetrain});

    // no auto
    return new frc2::SequentialCommandGroup(
        std::move(ramseteCommand),
        frc2::InstantCommand([this] { drivetrain.TankDriveVolts(0_V, 0_V); }, {}));

}

} // frc4783