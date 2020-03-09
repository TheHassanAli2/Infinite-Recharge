/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Subsystem.h>
#include "Constants.h"
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h> 

#include "subsystems/RoboRavensSubsystem.h"

namespace frc4783 {

class ControlPanel : public RoboRavensSubsystem {
  private:
    /**
     * Constants for control panel motor
     */
    static const int ControlPanelMotorId = 0;
    static const int ControlPanelMotorPort = 9;

    /**
     * Constants for control panel solenoid
     * 
     * Note: solenoid is used for testing solendoid code
     */
    static const int SolenoidId = 0;
    static const int SolenoidForwardPort = 4;
    static const int SolenoidReversePort = 5;

     


  public:
   ControlPanel();
    void GetColor();
    void ControlPanelInit();
    void GetIR();
    void PutNumber();
    void GetProximity();
    bool Blue;
    bool something;
    int ColourDetected;
    int RotationNumber;

    //void Stage1Stop();
    void DetectRotation();

    /**
     * Control the control panel motor
     * 
     * @param speed  set the speed for the motor (0 to stop, negative or positive for direction)
     */
    void RotateControlPanel(float speed);

    /**
     * Control the solenoid
     * 
     * @param direction  set the solenoid direction (kOff, kForward, kReverse)
     */
    void SetSolenoidDirection(frc::DoubleSolenoid::Value direction);


  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;


};

  
}  // namespace frc4783