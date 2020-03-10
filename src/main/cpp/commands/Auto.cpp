/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Auto.h"

namespace frc4783{

frc4783::Auto::Auto(frc4783::RobotContainer* contained) : container(contained) {
}

// Called when the command is initially scheduled.
void frc4783::Auto::Initialize() {
  //container->GetAutonomousCommand("Circle.paths.json"); // drive forward
  /* DUMP BALLS */
  //container->GetAutonomousCommand("Line.paths.json"); // move to trench to collect power cells
}

// Called repeatedly when this Command is scheduled to run
void frc4783::Auto::Execute() {}

// Called once the command ends or is interrupted.
void frc4783::Auto::End(bool interrupted) {}

// Returns true when the command should end.
bool frc4783::Auto::IsFinished() { return false; }
}