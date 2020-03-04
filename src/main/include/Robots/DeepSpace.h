#ifndef INCLUDE_ROBOTS_DEEPSPACE_H
#define INCLUDE_ROBOTS_DEEPSPACE_H

#include "RobotBase.h"
#include "subsystems/rrDriveTrain.h"
#include "subsystems/rrTwoSpeed.h"
#include "Frc4783Defs.h"

namespace frc4783 {

class DeepSpace : public RobotBase {
public:
    DeepSpace();
    //virtual ~DeepSpace();

protected:
    rrDriveTrain *m_drivetrain;
};


} //namespace frc4783

#endif // INCLUDE_ROBOTS_DEEPSPACE_H