#include "Robots/RobotFactory.h"
#include "Frc4783Defs.h"

#include "Robots/InfiniteRecharge.h"
#include "Robots/Protocase.h"
#include "Robots/DeepSpace.h"
#include "Robots/Steamworks.h"
#include "Robots/PowerUp.h"

namespace frc4783 {
RobotFactory::RobotFactory(){
 printf ("RobotFactory complete\n");
} 

frc4783::RobotBase *RobotFactory::createRobot(robotType_e rType){  

    frc4783::RobotBase *robot = nullptr;
    switch (rType){
        case INFINITERECHARGE:
        robot = new InfiniteRecharge();
        break;
        case PROTOCASE:
        robot = new Protocase();
        break;
        case DEEPSPACE:
        robot = new DeepSpace();
        break;
        case STEAMWORKS:
        robot = new Steamworks();
        break;
        case POWERUP:
        robot = new PowerUp();
        break;
    }
    //printf("Initialized Robot\n");

    return robot;
}
} //namespace frc4783