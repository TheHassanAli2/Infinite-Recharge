/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/rrTwoSpeed.h"

//ya feel?

namespace frc4783{

frc4783::rrTwoSpeed::rrTwoSpeed()
{
    gearSolenoid.reset(new frc::DoubleSolenoid(4,5));
    highGear = false;
    printf("rrTwoSpeed init completed\n");
}

void frc4783::rrTwoSpeed::Periodic(){}

void frc4783::rrTwoSpeed::setSpeed(int port, double speed)
{
    switch(port){
        case 0: 
        frontLeftMotor->Set(speed);
        break;
        case 1:
        frontRightMotor->Set(speed);
        break;
        case 2:
        backLeftMotor->Set(speed);
        break;
        case 3:
        backRightMotor->Set(speed);
        break;
    }
}
void frc4783::rrTwoSpeed::ReverseGear(){

  printf("Rev Gear - rrTwoSpeed\n");  
  if (gearSolenoid != nullptr) {
    gearSolenoid->Set(frc::DoubleSolenoid::kReverse);  
  }
  gearSolenoid->Set(frc::DoubleSolenoid::kReverse);
  highGear = false;
}
void frc4783::rrTwoSpeed::ForwardGear(){
  printf("Fwd Gear - rrTwoSpeed\n");  
  if (gearSolenoid != nullptr) {
    gearSolenoid->Set(frc::DoubleSolenoid::kForward);
  }
  gearSolenoid->Set(frc::DoubleSolenoid::kForward);
  highGear = true; 
} 
void frc4783::rrTwoSpeed::ArcadeDrive(double speed, double turn){
    differentialDrive->ArcadeDrive(speed, turn);
}

void frc4783::rrTwoSpeed::Stop(){
    ArcadeDrive(0, 0);
}

void frc4783::rrTwoSpeed::TankDrive(double leftspeed, double rightspeed){
    differentialDrive->TankDrive(leftspeed, rightspeed);
    }
}
