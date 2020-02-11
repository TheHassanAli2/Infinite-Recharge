/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <subsystems/Intake.h>

namespace frc4783 {

class MoveIntake
    : public frc2::CommandHelper<frc2::CommandBase, MoveIntake> {
 public:
  MoveIntake(Intake* subsystem);
  void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();
 private:
  Intake* intake;
};

} // namespace frc4783