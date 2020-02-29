/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#ifndef RRDIFFERENTIALDRIVE_H
#define RRDIFFERENTIALDRIVE_H

#include <subsystems/rrDriveTrain.h>

#include <frc/drive/DifferentialDrive.h>
#include <frc/SpeedControllerGroup.h>


//ya feel?

namespace frc4783{

/*This is the second level of the DriveTrain classes and is the child of the base 
rrDriveTrain class. It can use differential drive to use the DriveWithJoystick 
command.*/

class rrDifferentialDrive : public frc4783::rrDriveTrain{
public:

    rrDifferentialDrive();

    //Driving methods
    void TankDrive(double leftspeed, double rightspeed) override;
    void ArcadeDrive(double speed, double turn) override;
    void Stop() override;

    void Periodic();

protected:
    std::shared_ptr<frc::DifferentialDrive> differentialDrive;
    std::shared_ptr<frc::SpeedControllerGroup> leftDrive;
    std::shared_ptr<frc::SpeedControllerGroup> rightDrive;

};
} // namespace frc4783
#endif // RRDIFFERENTIALDRIVE_H