/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Auto.h"

Auto::Auto(int path) {
  // Use addRequirements() here to declare subsystem dependencies.
  this->path = path;
}

// Called when the command is initially scheduled.
void Auto::Initialize() {
  /*wpi::sys::path::append(deployDirectory, "paths");
  wpi::sys::path::append(deployDirectory, "YourPath.wpilib.json");
  frc::filesystem::GetDeployDirectory(deployDirectory);

  trajectory = frc::TrajectoryUtil::FromPathweaverJson(deployDirectory);*/
  if (path == 1){
    robotcontainer->GetAutonomousCommand("Circle.paths.json");
    //robotcontainer.GetAutonomousCommand("Circle.paths.json");
  }
  else if (path == 2){
    robotcontainer->GetAutonomousCommand("Square.paths.json");
  }
  
}

// Called repeatedly when this Command is scheduled to run
void Auto::Execute() {}

// Called once the command ends or is interrupted.
void Auto::End(bool interrupted) {}

// Returns true when the command should end.
bool Auto::IsFinished() { return false; }
