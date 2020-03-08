/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoCmd.h"

namespace frc4783{
frc4783::AutoCmd::AutoCmd(frc4783::rrDriveTrain* subsystem) : drivetrain(subsystem){
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subsystem);
}

// Called when the command is initially scheduled.
void frc4783::AutoCmd::Initialize() 
{
  printf("command initialize");
  printf("Auto periodic");
  m_timer.Reset(); //reset timer
  m_timer.Start();
    
}

// Called repeatedly when this Command is scheduled to run
void frc4783::AutoCmd::Execute() 
{
  printf("command execute");
  if (m_timer.Get() < 2.0) { //change timer values to your desire
      // Drive forwards half speed
      drivetrain->ArcadeDrive(-0.5, 0.0); //move.
    } else {
      // Stop robot
      End();
    }
}

// Called once the command ends or is interrupted.
void frc4783::AutoCmd::End() 
{
  printf("command end");
  drivetrain->ArcadeDrive(0.0,0.0);
}
}