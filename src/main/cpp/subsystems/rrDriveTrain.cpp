/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/rrDriveTrain.h"

//ya feel?

namespace frc4783{

frc4783::rrDriveTrain::rrDriveTrain()
{
    //Motor Controller and Signal type enumeration
    enum motortype motors = VictorSPX; 
    enum signaltype signal = CAN;

    //Port numeration
    frontLeftPort = 0;
    frontRightPort = 1;
    backLeftPort = 2;
    backRightPort = 3;

    //Automated decleration of motors
    if (motors == VictorSPX && signal == CAN){
        frontLeftMotor.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(frontLeftPort));
        frontRightMotor.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(frontRightPort));
        backLeftMotor.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(backLeftPort));
        backRightMotor.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(backRightPort));

    }
    else if (motors == VictorSPX && signal == PWM){
        frontLeftMotor.reset(new frc::VictorSP(frontLeftPort));
        backLeftMotor.reset(new frc::VictorSP(frontRightPort));
        frontRightMotor.reset(new frc::VictorSP(backLeftPort));
        backRightMotor.reset(new frc::VictorSP(backRightPort));

    }
    else if (motors == TalonSRX && signal == CAN){
        frontLeftMotor.reset(new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(frontLeftPort));
        frontRightMotor.reset(new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(frontRightPort));
        backLeftMotor.reset(new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(backLeftPort));
        backRightMotor.reset(new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(backRightPort));
    }
    else if (motors == TalonSRX && signal == PWM){
        frontLeftMotor.reset(new frc::PWMTalonSRX(frontLeftPort));
        backLeftMotor.reset(new frc::PWMTalonSRX(frontRightPort));
        frontRightMotor.reset(new frc::PWMTalonSRX(backLeftPort));
        backRightMotor.reset(new frc::PWMTalonSRX(backRightPort));
    }
    frontLeftMotor->SetInverted(true);
    backLeftMotor->SetInverted(true);
    frontRightMotor->SetInverted(true);
    backRightMotor->SetInverted(true);
    printf("rrDriveTrain init completed\n");
}

void frc4783::rrDriveTrain::Periodic(){}

void frc4783::rrDriveTrain::setSpeed(int port, double speed)
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

void frc4783::rrDriveTrain::ArcadeDrive(double speed, double turn){}

void frc4783::rrDriveTrain::Stop(){}

void frc4783::rrDriveTrain::TankDrive(double leftspeed, double rightspeed){}

void frc4783::rrDriveTrain::ReverseGear(){printf("Rev Gear - DriveTrain\n");}

void frc4783::rrDriveTrain::ForwardGear(){printf("Fwd Gear - DriveTrain\n");} 
}