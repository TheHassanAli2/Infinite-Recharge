/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <subsystems/Powercell.h>

namespace frc4783 {

class Intake
    : public frc2::CommandHelper<frc2::CommandBase, Intake> {
 public:
  Intake(Powercell* subsystem);
  void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();

 private:
  frc4783::Powercell* powercell;
} ;

} // namespace frc4783