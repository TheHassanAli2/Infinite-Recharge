/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <frc2/command/SubsystemBase.h>
#include <frc/WPILib.h>
#include <frc/DoubleSolenoid.h>
//#include <Robot.h>
//#include <commands/DriveWithJoystick.h>
#include "ctre/Phoenix.h"

class DriveTrain : public frc2::SubsystemBase {
public:

    DriveTrain();
    //DriveWithJoystick Methods
    void TankDrive(double leftspeed, double rightspeed);
    void ArcadeDrive(double speed, double turn);
    void Stop();

    /**
     * Will be called periodically whenever the CommandScheduler runs.
     */
    void Periodic() override;

    //GearShift Methods
    void ReverseGear();
	void ForwardGear();


    // Gearshift Solenoids and variables
     
    bool highGear;
    // remember to put something here later ya feel?
    std::shared_ptr<frc::DoubleSolenoid> gearSolenoid;

private:
    // DriveWithJoystick Motors
    std::shared_ptr<frc::SpeedController> frontLeftMotor;
    std::shared_ptr<frc::SpeedController> backLeftMotor;
    std::shared_ptr<frc::SpeedController> frontRightMotor;
    std::shared_ptr<frc::SpeedController> backRightMotor;
    std::shared_ptr<frc::DifferentialDrive> differentialDrive;
    std::shared_ptr<frc::SpeedControllerGroup> leftDrive;
    std::shared_ptr<frc::SpeedControllerGroup> rightDrive;
  
};

#endif // DRIVETRAIN_H