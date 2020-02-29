/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef DRIVEWITHJOYSTICK_H
#define DRIVEWITHJOYSTICK_H

//ya feel?

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <RobotContainer.h>
#include <subsystems/rrDriveTrain.h>
#include <subsystems/rrDifferentialDrive.h>
#include "subsystems/rrTwoSpeed.h"
#include "Robot.h"

namespace frc4783{

class DriveWithJoystick : public frc2::CommandHelper<frc2::CommandBase, DriveWithJoystick> {
 public:

    DriveWithJoystick(frc4783::rrDriveTrain* subsystem, frc4783::MainController* controller);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override; 
    void End();
    void Interrupted();

 private:
    frc4783::rrDriveTrain* drivetrain;
    //frc4783::RobotContainer* container;
    frc4783::MainController *m_controller; 
};
}
#endif // DRIVEWITHJOYSTICK_H