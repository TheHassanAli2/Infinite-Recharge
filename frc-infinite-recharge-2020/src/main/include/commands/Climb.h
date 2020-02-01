/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef CLIMB_H
#define CLIMB_H

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <RobotContainer.h>
#include "subsystems/Climber.h"
#include "Robot.h"

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class Climb
    : public frc2::CommandHelper<frc2::CommandBase, Climb> {
 public:
  /**
   * Creates a new ExampleCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  Climb(Climber* subsystem, RobotContainer* contained);
  //explicit ExampleCommand(ExampleSubsystem* subsystem);
  void Initialize() override;

  void Execute() override;

  bool IsFinished() override; 

  void End();
  
  void Interrupted();

 private:
  Climber* climber;
  RobotContainer* container;
};
#endif // CLIMB_H
