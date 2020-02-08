/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/GearShift.h"

GearShift::GearShift(DriveTrain* subsystem) : drivetrain(subsystem){
    bool FirstGear = true;
	AddRequirements(subsystem);
	//SetTimeout(0.5);
}

void GearShift::Initialize() {
    printf("Gearshift init completed\n");
	if (drivetrain->highGear == true) {    						 
   		drivetrain->ReverseGear();
		//frc::SmartDashboard::PutBoolean("IsItOnFirstGear?", FirstGear);
   	}
	// If the robot is on first gear:
	else	{    				
   	  	drivetrain->ForwardGear(); 							
		//frc::SmartDashboard::PutBoolean("IsItOnFirstGear?", FirstGear);
	} 
}

// Called repeatedly when this Command is scheduled to run
void GearShift::Execute() {
   	  
}
bool GearShift::IsFinished() { 
	// changes the variable state for the next time we need to shift gears
	// Defaults to a timeout
    FirstGear = !FirstGear;
	//return IsTimedOut(); 
    return true;
}

void GearShift::End() {
    drivetrain->gearSolenoid->Set(frc::DoubleSolenoid::kOff);
	
}

void GearShift::Interrupted() {}