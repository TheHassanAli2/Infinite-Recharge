#include "commands/OpenCloseHatch.h"
#include "subsystems/PowerCell.h"

namespace frc4783 {

OpenCloseHatch::OpenCloseHatch(frc4783::PowerCell* subsystem)
    : m_powerCell(subsystem),
      m_state(HatchState::Closed) 
{
    printf("OpenCloseHatch ctor  angle= %f  value= %f\n",
            m_powerCell->getHatchAngle(), 
            m_powerCell->getHatchValue());
}

void OpenCloseHatch::Initialize(){
    switch(m_state) {
        case HatchState::Closed: {
            printf("hatch set for loading\n");
            m_powerCell->loading();
            m_state = HatchState::Loading;
            break;
        }
        case HatchState::Loading: {
            printf("opening hatch\n");
            m_powerCell->openHatch();
            m_state = HatchState::Open;
            break;
        }
        case HatchState::Open: {
            printf("closing hatch\n");
            m_powerCell->closeHatch();
            m_state = HatchState::Closed;
            break;
        }
        default:
        break;
    }
}

void OpenCloseHatch::Execute(){

}

bool OpenCloseHatch::IsFinished(){
    printf("OpenCloseHatch isFinished  state= %d  angle= %f  value= %f\n",
            (int)m_state,
            m_powerCell->getHatchAngle(), 
            m_powerCell->getHatchValue());
    return true;
}

void OpenCloseHatch::Interrupted(){
    printf("OpenCloseHatch::interrupted\n");
}

void OpenCloseHatch::End() {
    printf("OpenCloseHatch::end\n");
}

} // namespace frc4783