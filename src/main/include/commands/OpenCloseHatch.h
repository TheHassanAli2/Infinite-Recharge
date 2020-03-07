#pragma once
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/PowerCell.h"

namespace frc4783 {

/**
 * Example Command for controlling a double solenoid
 * 
 * This command will toggle between the forward/reverse directions
 */
class OpenCloseHatch
    : public frc2::CommandHelper<frc2::CommandBase, OpenCloseHatch> {
 
 public:
    explicit OpenCloseHatch(frc4783::PowerCell* subsystem);

    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();

private:
    enum class HatchState {
        Closed,
        Loading,
        Open
    };

    frc4783::PowerCell* m_powerCell;
    HatchState m_state;
};

} // namespace frc4783