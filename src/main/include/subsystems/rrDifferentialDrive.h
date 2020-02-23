/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#ifndef RRDIFFERENTIALDRIVE_H
#define RRDIFFERENTIALDRIVE_H

#include <subsystems/rrDriveTrain.h>

//ya feel?

namespace frc4783{

/*This is the second level of the DriveTrain classes and is the child of the base 
rrDriveTrain class. It can use differential drive to use the DriveWithJoystick 
command.*/

class rrDifferentialDrive : public frc4783::rrDriveTrain{
public:

    rrDifferentialDrive();
    //DriveWithJoystick Methods
    void setSpeed(int port, double speed);
    void TankDrive(double leftspeed, double rightspeed);
    void ArcadeDrive(double speed, double turn);
    void Stop();
    void ReverseGear();
	void ForwardGear();
    void Periodic();
};
}
#endif // RRDIFFERENTIALDRIVE_H