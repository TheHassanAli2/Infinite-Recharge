/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ControlPanel.h"
#include <frc/VictorSP.h>
#include <frc/util/color.h>
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"
#include <frc/smartdashboard/smartdashboard.h>

static constexpr auto i2cPort = frc::I2C::Port::kOnboard;

rev::ColorSensorV3 m_colorSensor{i2cPort};

rev::ColorMatch m_colorMatcher;

static constexpr frc::Color kBlueTarget = frc::Color(0.23, 0.48,0.26);
static constexpr frc::Color kGreenTarget = frc::Color(0.27, 0.55, 0.15);
static constexpr frc::Color kRedTarget = frc::Color(0.61, 0.33, 0.06);
static constexpr frc::Color kYellowTarget = frc::Color(0.43, 0.49,0.06);



namespace frc4783 {

ControlPanel::ControlPanel() {
  controlpanelMotor.reset(new frc::VictorSP(0));
  printf("Control Panel ctor\n");
  // Implementation of subsystem constructor goes here.
}

void ControlPanel::Periodic() {
  frc::Color detectedColor = m_colorSensor.GetColor();

  double IR = m_colorSensor.GetIR();

  frc::SmartDashboard::PutNumber("Red", detectedColor.red);
  frc::SmartDashboard::PutNumber("Green", detectedColor.green);
  frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
  frc::SmartDashboard::PutNumber("IR", IR);

  printf("r: %f  g: %f  b: %f\n", detectedColor.red, detectedColor.green, detectedColor.blue);

  uint32_t proximity = m_colorSensor.GetProximity();

  frc::SmartDashboard::PutNumber("Proximity", proximity);

  std::string colorString;
  double confidence = 0.0;
  frc::Color matchedColor = m_colorMatcher.MatchClosestColor(detectedColor, confidence);

  if (matchedColor == kBlueTarget) {
      printf ("Blue ");
    } else if (matchedColor == kRedTarget) {
      printf ("Red ");
    } else if (matchedColor == kGreenTarget) {
      printf ("Green ");
    } else if (matchedColor == kYellowTarget) {
      printf ("Yellow ");
    } else {
      printf ("Unknown ");
    }

}

void ControlPanel::InitDefaultCommand (){
  m_colorMatcher.AddColorMatch(kBlueTarget);
  m_colorMatcher.AddColorMatch(kGreenTarget);
  m_colorMatcher.AddColorMatch(kRedTarget);
  m_colorMatcher.AddColorMatch(kYellowTarget);
}

void ControlPanel::SetMotorSpeed(float speed){  
  controlpanelMotor->Set(speed);
}

void ControlPanel::SpinClockwise(){
  controlpanelMotor->Set(1);
}

void ControlPanel::SpinCounterClockwise(){
  controlpanelMotor->Set(-1);
}

void ControlPanel::StopMotor(){
  controlpanelMotor->Set(0);
}

} // namespace frc4783