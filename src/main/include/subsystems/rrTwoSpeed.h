/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#ifndef RRTWOSPEED_H
#define RRTWOSPEED_H

#include <subsystems/rrDifferentialDrive.h>

//ya feel?

namespace frc4783{

/*This is the third level of the DriveTrain classes and is the child of the 
rrDifferentialDrive class. It has the ability to use the GearShift command to
change between two speeds in the robot, hence the name.*/

class rrTwoSpeed : public frc4783::rrDifferentialDrive{
public:

    rrTwoSpeed();
    void setSpeed(int port, double speed);
    void TankDrive(double leftspeed, double rightspeed);
    void ArcadeDrive(double speed, double turn);
    void Stop();
    void ReverseGear();
	void ForwardGear();
    void Periodic();
};
}
#endif // RRTWOSPEED_H