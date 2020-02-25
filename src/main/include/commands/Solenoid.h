#pragma once
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/ControlPanel.h"

namespace frc4783 {

/**
 * Example Command for controlling a double solenoid
 * 
 * This command will toggle between the forward/reverse directions
 */
class Solenoid
    : public frc2::CommandHelper<frc2::CommandBase, Solenoid> {
 
 public:
    explicit Solenoid(frc4783::ControlPanel* ControlPanel);

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

private:
    frc4783::ControlPanel* SolenoidSubsystem;

    /**
     *   indicatest the position of the pnuematic cylinder (extended (true) or retracted (false))
     */
    bool extended;
};

} // namespace frc4783