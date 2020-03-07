#pragma once

#include <subsystems/RoboRavensSubsystem.h>
#include <frc/Servo.h>

namespace frc4783 {

class PowerCell : public RoboRavensSubsystem {

public:
    PowerCell();
    ~PowerCell();

    void openHatch();
    void closeHatch();
    void loading();

    double getHatchAngle();
    double getHatchValue();

private:
    frc::Servo *m_servo;

    static const int ServoPwmPort;

    static const int OpenAngle;
    static const int LoadAngle;
    static const int ClosedAngle;

};

} // namespace frc4783