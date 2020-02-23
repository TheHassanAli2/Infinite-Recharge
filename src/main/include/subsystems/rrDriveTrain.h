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

//ya feel?

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

    std::shared_ptr<frc::SpeedController> frontLeftMotor;
    std::shared_ptr<frc::SpeedController> backLeftMotor;
    std::shared_ptr<frc::SpeedController> frontRightMotor;
    std::shared_ptr<frc::SpeedController> backRightMotor; 

    //Ports
    int frontLeftPort;
    int frontRightPort;
    int backLeftPort;
    int backRightPort;
};
}

#endif // RRDRIVETRAIN_H
