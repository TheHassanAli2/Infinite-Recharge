#ifndef INCLUDE_ROBOTS_PROTOCASE_H
#define INCLUDE_ROBOTS_PROTOCASE_H

#include "RobotBase.h"
#include "subsystems/rrDriveTrain.h"
#include "subsystems/ControlPanel.h"

#include "commands/GearShift.h"
#include "commands/DriveWithJoystick.h"

namespace frc4783 {
class Protocase : public RobotBase {
public:
    Protocase();

    //virtual ~Protocase();

protected:
    frc4783::rrDriveTrain *m_drivetrain;
    frc4783::ControlPanel *m_controlPanel;
};


} //namespace frc4783

#endif // INCLUDE_ROBOTS_PROTOCASE_H