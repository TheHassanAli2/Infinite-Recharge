/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ControlPanel.h"
#include "RoboRavensSubsystem.h"
#include <frc/util/color.h>
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"
#include <frc/smartdashboard/smartdashboard.h>
#include <unistd.h>
#include "Robot.h"
#include <frc/commands/Scheduler.h>

static constexpr auto i2cPort = frc::I2C::Port::kOnboard;

rev::ColorSensorV3 m_colorSensor{i2cPort};

rev::ColorMatch m_colorMatcher;

#define COMPETITION_VALUES
#ifdef COMPETITION_VALUES

// Values from color sample from kit without light
static constexpr frc::Color kBlueTarget = frc::Color(0.23, 0.49, 0.27);
static constexpr frc::Color kGreenTarget = frc::Color(0.25, 0.58, 0.15);
static constexpr frc::Color kRedTarget = frc::Color(0.65, 0.29, 0.04);
static constexpr frc::Color kYellowTarget = frc::Color(0.43, 0.49, 0.06);

#else

// Values from Ctrl Panel Prototype without light
static constexpr frc::Color kBlueTarget = frc::Color(0.147, 0.42, 0.42);
static constexpr frc::Color kGreenTarget = frc::Color(0.196, 0.522, 0.280);
static constexpr frc::Color kRedTarget = frc::Color(0.397, 0.419, 0.177);
static constexpr frc::Color kYellowTarget = frc::Color(0.314, 0.539 ,0.146);

#endif


namespace frc4783 {

ControlPanel::ControlPanel() {
    printf("Control Panel ctor\n");
    m_colorMatcher.AddColorMatch(kBlueTarget);
    m_colorMatcher.AddColorMatch(kGreenTarget);
    m_colorMatcher.AddColorMatch(kRedTarget);
    m_colorMatcher.AddColorMatch(kYellowTarget);

    InitializeMotor(ControlPanelMotorId, VictorSPX, PWM, ControlPanelMotorPort);
}

void ControlPanel::Periodic() {
    frc::Color detectedColor = m_colorSensor.GetColor();

    double IR = m_colorSensor.GetIR();

    frc::SmartDashboard::PutNumber("Red", detectedColor.red);
    frc::SmartDashboard::PutNumber("Green", detectedColor.green);
    frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
    frc::SmartDashboard::PutNumber("IR", IR);

    uint32_t proximity = m_colorSensor.GetProximity();
    frc::SmartDashboard::PutNumber("Proximity", proximity);

    std::string colorString;
    double confidence = 0.0;
    frc::Color matchedColor = m_colorMatcher.MatchClosestColor(detectedColor, confidence);

    if (matchedColor == kBlueTarget) {
      colorString = "Blue";
    } else if (matchedColor == kRedTarget) {
      colorString = "Red";
    } else if (matchedColor == kGreenTarget) {
      colorString = "Green";
    } else if (matchedColor == kYellowTarget) {
      colorString = "Yellow";
    } else {
      colorString = "Unknown";
    }

    printf("r: %f  g: %f  b: %f  %s\n", detectedColor.red, detectedColor.green, detectedColor.blue, colorString.c_str());

}

void ControlPanel::RotateControlPanel(float speed) {
    SetMotorSpeed(ControlPanelMotorId, speed);
}

} // namespace frc4783