#ifndef INCLUDE_ROBOTS_ROBOTFACTORY_H
#define INCLUDE_ROBOTS_ROBOTFACTORY_H

#include "Robots/RobotBase.h"
#include "Frc4783Defs.h"

namespace frc4783 {
class RobotFactory {
public:
    RobotFactory();    
    ~RobotFactory();

    static frc4783::RobotBase *createRobot(robotType_e rType);

};
} //namespace frc4783

#endif //INCLUDE_ROBOTS_ROBOTFACTORY_H 