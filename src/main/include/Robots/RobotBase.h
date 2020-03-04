#ifndef INCLUDE_ROBOTS_ROBOTBASE_H
#define INCLUDE_ROBOTS_ROBOTBASE_H

#include "subsystems/rrDriveTrain.h"

namespace frc4783 {

// forward declaration
class RobotContainer;

class RobotBase  {
public:
    RobotBase();
    virtual ~RobotBase();

    void setDriveTrainDefaultCommand(RobotContainer *rc);

protected:
    frc4783::rrDriveTrain *m_drivetrain;
};


} // namespace frc4783

#endif // INCLUDE_ROBOTS_ROBOTBASE_H