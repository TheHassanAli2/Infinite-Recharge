/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/Filesystem.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <wpi/Path.h>
#include <RobotContainer.h>
#include <Robot.h>
//#include <wpi/SmallVectorImpl.h>
#include <wpi/SmallString.h>



namespace frc4783{

class Auto
    : public frc2::CommandHelper<frc2::CommandBase, Auto> {
 public:
  Auto(RobotContainer* contained);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

private:
  wpi::SmallString<64> deployDirectory;
  frc::Trajectory trajectory;
  frc4783::RobotContainer* container;
};
}
