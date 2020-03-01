/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#ifndef RRDRIVETRAIN_H
#define RRDRIVETRAIN_H

#include <frc2/command/SubsystemBase.h>

#include "frc/SpeedController.h"

#include <Constants.h>

#include <frc/ADXRS450_Gyro.h>
#include <frc/Encoder.h>
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <units/units.h>


namespace frc4783{

/* This is the Base class of the DriveTrain classes. This contains all of the variables 
functions of the DriveTrain classes and has all of the functions made virtually. 
This allows for the other classes to redefine the functions to whatever they want.
The reason for this is so that we can use the different types of drivetrains
while using the same object of this class. The enumeration of motor controller types,
signal types and ports allows for automated declaration of motor controllers and types.*/    

class rrDriveTrain : public frc2::SubsystemBase {
public:

    rrDriveTrain();
    
    //Driving methods
    virtual void setSpeed(int port, double speed);

    virtual void TankDrive(double leftspeed, double rightspeed);
    virtual void ArcadeDrive(double speed, double turn);
    virtual void Stop();

    // Gearshift methods
    virtual void ReverseGear();
    virtual void ForwardGear();
    virtual void GearOff();
    virtual bool isHighGear();

    void Periodic() override;

    // Autonomous methods
    void ResetEncoders();
    double GetAverageEncoderDistance();
    frc::Encoder GetLeftEncoder();
    frc::Encoder GetRightEncoder();

    virtual void SetMaxOutput(double maxOutput);
    double GetHeading();
    double GetTurnRate();
    frc::Pose2d GetPose();
    void ResetOdometry(frc::Pose2d pose);

    virtual void TankDriveVolts(units::volt_t left, units::volt_t right);
    virtual frc::DifferentialDriveWheelSpeeds GetWheelSpeeds();

protected:
    //Enumeration declarations

    // Enumeration of the types of motor controllers
    enum motortype {
        VictorSPX, 
        TalonSRX
    };

    // Enumeration of the types of signals
    enum signaltype {
        PWM,
        CAN
    };

    enum motortype motors; 
    enum signaltype signal;

    // speed controllers
    std::shared_ptr<frc::SpeedController> frontLeftMotor;
    std::shared_ptr<frc::SpeedController> backLeftMotor;
    std::shared_ptr<frc::SpeedController> frontRightMotor;
    std::shared_ptr<frc::SpeedController> backRightMotor; 

    frc::Encoder m_leftEncoder;
    frc::Encoder m_rightEncoder;
    frc::ADXRS450_Gyro m_gyro;
    frc::DifferentialDriveOdometry m_odometry;

    //Ports
    int frontLeftPort;
    int frontRightPort;
    int backLeftPort;
    int backRightPort;
};
}

#endif // RRDRIVETRAIN_H
