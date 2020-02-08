/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Subsystem.h>
#include "Constants.h"
#include <frc/SpeedController.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/VictorSP.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h> 
#include <frc/smartdashboard/smartdashboard.h>

class ControlPanel : public frc2::Subsystem {
  private:
    std::shared_ptr<frc::SpeedController> controlpanelMotor;

 public:
 
  ControlPanel();
   void GetColor();
        void ControlPanelInit();
        void GetIR();
        void PutNumber();
        void GetProximity();

        void InitDefaultCommand();
        void Reset();
        void SetMotorSpeed(float speed);
        void SpinClockwise();
        void SpinCounterClockwise();
        void StopMotor();
      

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;


};

  
 //}  // namespace frc