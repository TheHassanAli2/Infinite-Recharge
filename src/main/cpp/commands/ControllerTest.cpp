#include "subsystems/ControlPanel.h"
#include "commands/ControllerTest.h"
#include "Robot.h"

namespace frc4783 {

ControllerTest::ControllerTest(std::string buttonStr, int buttonId)
    : m_buttonStr(buttonStr),
      m_id(buttonId) 
{
    printf("Rotate Panel ctor\n");
}

void ControllerTest::Initialize(){
    printf("ControllerTest::initialize: %s  %d\n", m_buttonStr.c_str(), m_id);
}

void ControllerTest::Execute(){
}

bool ControllerTest::IsFinished(){
    printf("ControllerTest::isFinished %s  %d\n", m_buttonStr.c_str(), m_id);
    return true;
}

void ControllerTest::Interrupted(){
    printf("ControllerTest::interrupted\n");
}

void ControllerTest::End() {
    printf("ControllerTest::end\n");
}

} // namespace frc4783