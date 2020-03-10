#pragma once
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <subsystems/Powercell.h>
#include "RobotContainer.h"

namespace frc4783 {

class Outtake90
    : public frc2::CommandHelper<frc2::CommandBase, Outtake90> {
      
 public:
  Outtake90(Powercell* subsystem);
  void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();

 private:
  Powercell* powercell;
  bool powercellCheck;
} ;

} // namespace frc4783