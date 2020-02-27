#ifndef INCLUDE_ROBOTS_POWERUP_H
#define INCLUDE_ROBOTS_POWERUP_H

#include "RobotBase.h"
#include "subsystems/rrDriveTrain.h"
#include "subsystems/rrDifferentialDrive.h"

#include "commands/GearShift.h"
#include "commands/DriveWithJoystick.h"

namespace frc4783 {

class PowerUp : public RobotBase {
public:
    PowerUp();
    //virtual ~PowerUp();

protected:
    rrDriveTrain *m_drivetrain;
};


} //namespace frc4783

#endif // INCLUDE_ROBOTS_POWERUP_H