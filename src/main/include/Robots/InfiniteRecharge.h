#ifndef INCLUDE_ROBOTS_INFINITERECHARGE_H
#define INCLUDE_ROBOTS_INFINITERECHARGE_H

#include "RobotBase.h"
#include "subsystems/rrDriveTrain.h"
#include "subsystems/rrTwoSpeed.h"
#include "subsystems/ControlPanel.h"


namespace frc4783 {

class InfiniteRecharge : public RobotBase {
public:
   InfiniteRecharge();
    //virtual ~InfiniteRecharge();

protected:
    
    frc4783::ControlPanel *m_controlPanel;
};


} //namespace frc4783

#endif // INCLUDE_ROBOTS_INFINITERECHARGE_H