/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef CLIMBRETRACT_H
#define CLIMBRETARCT_H

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/Climber.h"

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */

namespace frc4783 {

class ClimbRetract
    : public frc2::CommandHelper<frc2::CommandBase, ClimbRetract> {
 public:
  /**
   * Creates a new ExampleCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  ClimbRetract(Climber* subsystem);
  //explicit ExampleCommand(ExampleSubsystem* subsystem);
  void Initialize() override;

  void Execute() override;

  bool IsFinished() override; 

  void End();
  
  void Interrupted();

 private:
  Climber* climber;
};

} //namespace frc4783
#endif // CLIMBRETRACT_H
