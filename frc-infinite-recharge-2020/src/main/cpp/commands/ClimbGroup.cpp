/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ClimbGroup.h"
#include "subsystems/Climber.h"

namespace frc4783{
// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
ClimbGroup::ClimbGroup(frc4783::Climber* climber, frc4783::RobotContainer* container) {
  
  AddCommands(frc4783::ClimbPivot(climber, container), frc4783::ClimbExtend(climber));
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());

}

} 