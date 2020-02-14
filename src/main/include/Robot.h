

#ifndef ROBOT_H
#define ROBOT_H

#include <Constants.h>
#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>

// Vision includes
#include <cameraserver/CameraServer.h>
#include <thread>

// Subsystem includes
#include <RobotContainer.h>
#include <subsystems/DriveTrain.h>

#include <array>
#include <frc/AddressableLED.h>

class Robot : public frc::TimedRobot {
    public:

static constexpr int kLength = 64;

// PWM port 9
  // Must be a PWM header, not MXP or DIO
  frc::AddressableLED m_led{9};
  std::array<frc::AddressableLED::LEDData, kLength>
      m_ledBuffer;  // Reuse the buffer
  // Store what the last hue of the first pixel is
  int firstPixelHue = 0;
  

    void Purple() {
    // For every pixel
    for (int i = 0; i < kLength; i++) {
      // Calculate the hue - hue is easier for rainbows because the color
      // shape is a circle so only one value needs to precess
      // Set the value
      m_ledBuffer[i].SetRGB(160, 0, 176);
    }
    }
    void Blue(){
    for (int i = 0; i < kLength; i++) {
      m_ledBuffer[i].SetRGB(0, 0, 255);
    }
    }
    void Red(){
    for (int i = 0; i < kLength; i++) {
      m_ledBuffer[i].SetRGB(255, 0, 0);
    }
    }
    void Rainbow() {
      // For every pixel
    for (int i = 0; i < kLength; i++) {
      // Calculate the hue - hue is easier for rainbows because the color
      // shape is a circle so only one value needs to precess
      const auto pixelHue = (firstPixelHue + (i * 180 / kLength)) % 180;
      // Set the value
      m_ledBuffer[i].SetRGB(pixelHue, 255, 128);
    }
    // Increase by to make the rainbow "move"
    firstPixelHue += 3;
    // Check bounds
    firstPixelHue %= 180;
    }

    //frc::Command* autonomousCommand;
    
    //static std::unique_ptr<RobotContainer> robotcontainer;
    
    //static std::shared_ptr<DriveTrain> drivetrain;

    void RobotInit() override;
    void RobotPeriodic() override;
    void DisabledInit() override;
    void DisabledPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;

private:
    // Have it null by default so that if testing teleop it
    // doesn't have undefined behavior and potentially crash.
    frc2::Command* m_autonomousCommand = nullptr;
    //frc::SendableChooser<frc::Command*> m_chooser;

    RobotContainer container;
};
#endif //ROBOT_H