/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef CLIMBHOOK_H
#define CLIMBHOOK_H

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "RobotContainer.h"
#include "subsystems/Climber.h"

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */

namespace frc4783 {

class ClimbHook
    : public frc2::CommandHelper<frc2::CommandBase, ClimbHook> {
 public:
  /**
   * Creates a new ExampleCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  ClimbHook(Climber* subsystem);
  //explicit ExampleCommand(ExampleSubsystem* subsystem);
  void Initialize() override;

  void Execute() override;

  bool IsFinished() override; 

  void End();
  
  void Interrupted();

 private:
  frc4783::Climber* climber;
  frc4783::RobotContainer* container;
  //bool pivot = true;
};

} //namespace frc4783
#endif // CLIMBHOOK_H
