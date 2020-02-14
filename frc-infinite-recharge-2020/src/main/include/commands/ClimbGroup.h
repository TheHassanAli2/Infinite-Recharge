/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef CLIMBGROUP_H
#define CLIMBGROUP_H


#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "RobotContainer.h"
#include "subsystems/Climber.h"
#include "Robot.h"
#include "commands/ClimbExtend.h"
#include "commands/ClimbPivot.h"

class ClimbGroup: public frc2::CommandHelper<frc2::SequentialCommandGroup, ClimbGroup> {
  public:
    //ClimbGroup(Climber* climber);
    ClimbGroup();
  private:

   

};

#endif //