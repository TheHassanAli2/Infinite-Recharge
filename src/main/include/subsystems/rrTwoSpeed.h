/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#ifndef RRTWOSPEED_H
#define RRTWOSPEED_H

#include <subsystems/rrDifferentialDrive.h>
#include <frc/DoubleSolenoid.h>

//ya feel?

namespace frc4783{

/*This is the third level of the DriveTrain classes and is the child of the 
rrDifferentialDrive class. It has the ability to use the GearShift command to
change between two speeds in the robot, hence the name.*/

class rrTwoSpeed : public frc4783::rrDifferentialDrive{
public:

    rrTwoSpeed();

    // Gearshift methods
    void ReverseGear() override;
    void ForwardGear() override;
    void GearOff() override;

    bool isHighGear() override;

protected:
    bool highGear;
    std::shared_ptr<frc::DoubleSolenoid> gearSolenoid;

};

}
#endif // RRTWOSPEED_H