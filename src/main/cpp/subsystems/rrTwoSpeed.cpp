/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/rrTwoSpeed.h"

//ya feel?

namespace frc4783{

rrTwoSpeed::rrTwoSpeed()
{
    gearSolenoid.reset(new frc::DoubleSolenoid(4,5));
    highGear = false;
    printf("rrTwoSpeed init completed\n");
}

void rrTwoSpeed::ReverseGear(){
    printf("Rev Gear - rrTwoSpeed\n");
    if (gearSolenoid != nullptr) {
        gearSolenoid->Set(frc::DoubleSolenoid::kReverse);
        highGear = false;
    }
}
void rrTwoSpeed::ForwardGear(){
    printf("Fwd Gear - rrTwoSpeed\n");
    if (gearSolenoid != nullptr) {
        gearSolenoid->Set(frc::DoubleSolenoid::kForward);
        highGear = true; 
    }
}

void rrTwoSpeed::GearOff() {
    if (gearSolenoid != nullptr) {
        gearSolenoid->Set(frc::DoubleSolenoid::kOff);
        highGear = false; 
    }
}

bool rrTwoSpeed::isHighGear() {
    return highGear;
}

} // namespace frc4783
