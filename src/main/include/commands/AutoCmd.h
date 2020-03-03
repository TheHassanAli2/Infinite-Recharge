/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <subsystems/rrDriveTrain.h>
#include <frc2/command/Command.h>
#include <frc2/command/PrintCommand.h>
#include <frc2/command/CommandScheduler.h>
#include <frc/Timer.h>
namespace frc4783{
/**
 * An example command.
 *P
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class AutoCmd
    : public frc2::CommandHelper<frc2::CommandBase, AutoCmd> {
 public:
  AutoCmd(frc4783::rrDriveTrain* subsystem);

  void Initialize() override;

  void Execute() override;

  void End();

  private:
  frc4783::rrDriveTrain* drivetrain;
  frc::Timer m_timer;
};
}