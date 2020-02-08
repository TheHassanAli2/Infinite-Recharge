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
#include "subsystems/DriveTrain.h"

class GearShift : public frc2::CommandHelper<frc2::CommandBase, GearShift>  {
 public:
    GearShift(DriveTrain* subsystem);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
  
private:
    bool FirstGear;

    DriveTrain* drivetrain;

};