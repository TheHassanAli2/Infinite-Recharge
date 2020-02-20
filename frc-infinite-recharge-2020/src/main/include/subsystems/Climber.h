/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef CLIMBER_H
#define CLIMBER_H

#include <frc2/command/SubsystemBase.h>
#include <frc/SpeedController.h>
#include <frc/DoubleSolenoid.h>
#include <frc/DigitalInput.h>
#include <frc/Counter.h>
#include <ctre/Phoenix.h>
#include <frc/Compressor.h>

#include <Constants.h>

namespace frc4783 {

class Climber : public frc2::SubsystemBase {
 public:
  Climber();
  void ClimbReset();
  void ClimbMotor(bool clockwise);
  void ClimbSolenoid(bool extended);
  void ClimbPivotStage(int pivotStage);
  void ClimbExtendStage();
  void ClimbRetractStage();
  bool ClimbLimitSwitch();
  
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  std::shared_ptr<frc::SpeedController> pivotMotor1;
  std::shared_ptr<frc::SpeedController> pivotMotor2;
  std::shared_ptr<frc::DoubleSolenoid> climbSolenoid1;
  std::shared_ptr<frc::DoubleSolenoid> climbSolenoid2;
  std::shared_ptr<frc::Compressor> compressorOn;
  std::shared_ptr<frc::DigitalInput> limitSwitch;
  std::shared_ptr<frc::Counter> counter;
  Climber* climber; 
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};

} //namespace frc4783
#endif // CLIMBER_H
