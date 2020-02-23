/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/rrDifferentialDrive.h"

//ya feel?

namespace frc4783{

rrDifferentialDrive::rrDifferentialDrive()
{
    leftDrive.reset(new frc::SpeedControllerGroup(*backLeftMotor, *frontLeftMotor));
    rightDrive.reset(new frc::SpeedControllerGroup(*backRightMotor, *frontRightMotor));
    rightDrive->SetInverted(true);

    differentialDrive.reset(new frc::DifferentialDrive(*leftDrive, *rightDrive));

    printf("rrDifferentialDrive init completed\n");
}

void rrDifferentialDrive::Periodic(){}

void rrDifferentialDrive::setSpeed(int port, double speed)
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

void rrDifferentialDrive::ArcadeDrive(double speed, double turn){
    differentialDrive->ArcadeDrive(speed, turn);
}

void rrDifferentialDrive::Stop(){
    ArcadeDrive(0, 0);
}

void rrDifferentialDrive::TankDrive(double leftspeed, double rightspeed){
    differentialDrive->TankDrive(leftspeed, rightspeed);
}

void rrDifferentialDrive::ReverseGear(){printf("Rev Gear - Diff Drive\n");}

void rrDifferentialDrive::ForwardGear(){printf("Fwd Gear - Diff Drive\n");} 

}