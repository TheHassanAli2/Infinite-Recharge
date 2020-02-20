#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "RoboRavensSubsystem.h"
#include "subsystems/ControlPanel.h"

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
    bool extended;
};
