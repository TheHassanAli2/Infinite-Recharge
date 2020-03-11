#pragma once
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <subsystems/Powercell.h>
#include "RobotContainer.h"

namespace frc4783 {

class Outtake45
    : public frc2::CommandHelper<frc2::CommandBase, Outtake45> {
      
 public:
  Outtake45(Powercell* subsystem);
  void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();
  int movement=0;

 private:
  Powercell* powercell;
  bool powercellCheck;
} ;

} // namespace frc4783