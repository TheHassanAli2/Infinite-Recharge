/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <RobotContainer.h>
#include "Robot.h"
#include "frc/DoubleSolenoid.h"
#include <subsystems/rrDriveTrain.h>
#include <subsystems/rrDifferentialDrive.h>
#include "subsystems/rrTwoSpeed.h"

//ya feel?

namespace frc4783{

class GearShift : public frc2::CommandHelper<frc2::CommandBase, GearShift>  {
 public: 
    GearShift(frc4783::rrDriveTrain* subsystem);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
  
private:
    frc4783::rrDriveTrain* drivetrain;
};
}