#ifndef INCLUDE_ROBOTS_STEAMWORKS_H
#define INCLUDE_ROBOTS_STEAMWORKS_H

#include "RobotBase.h"
#include "subsystems/rrDriveTrain.h"
#include "subsystems/rrDifferentialDrive.h"

#include "commands/GearShift.h"
#include "commands/DriveWithJoystick.h"

namespace frc4783 {

class Steamworks : public RobotBase {
public:
    Steamworks();
    //virtual ~Steamworks();

protected:
    rrDriveTrain *m_drivetrain;
};


} //namespace frc4783

#endif // INCLUDE_ROBOTS_STEAMWORKS_H