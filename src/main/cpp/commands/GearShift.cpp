/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/GearShift.h"

//ya feel?

namespace frc4783{

frc4783::GearShift::GearShift(frc4783::rrDriveTrain* subsystem) : drivetrain(subsystem){
    AddRequirements(subsystem);
    //SetTimeout(0.5);
}

void frc4783::GearShift::Initialize() {
    printf("Gearshift init completed\n");
    if (drivetrain->isHighGear() == true) {
        drivetrain->ReverseGear();
        //frc::SmartDashboard::PutBoolean("IsItOnFirstGear?", FirstGear);
    }
    // If the robot is on first gear:
    else {
        drivetrain->ForwardGear();
        //frc::SmartDashboard::PutBoolean("IsItOnFirstGear?", FirstGear);
    }
}

// Called repeatedly when this Command is scheduled to run
void frc4783::GearShift::Execute() {

}
bool frc4783::GearShift::IsFinished() { 
    // changes the variable state for the next time we need to shift gears
    // Defaults to a timeout
    //return IsTimedOut(); 
    return true;
}

void frc4783::GearShift::End() {
    //drivetrain->gearSolenoid->Set(frc::DoubleSolenoid::kOff);
    drivetrain->GearOff();
}

void frc4783::GearShift::Interrupted() {}
}