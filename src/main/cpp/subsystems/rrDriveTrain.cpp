/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/rrDriveTrain.h"

#include <frc/VictorSP.h>
#include "ctre/Phoenix.h"
#include "frc/PWMVictorSPX.h"
#include "frc/PWMTalonSRX.h"

namespace frc4783{

rrDriveTrain::rrDriveTrain()
{
    //Motor Controller and Signal type enumeration
    /**
     * @todo: motor type and signal type should be parameters to rrDriveTrain constructor
     */
    motors = VictorSPX; 
    signal = CAN;

    //Port numeration
    frontLeftPort = 0;
    backLeftPort = 1;

    frontRightPort = 2;
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

    frontLeftMotor->SetInverted(false);
    backLeftMotor->SetInverted(false);
    frontRightMotor->SetInverted(false);
    backRightMotor->SetInverted(false);
    
    printf("rrDriveTrain init completed\n");
}

void rrDriveTrain::Periodic(){}

void rrDriveTrain::setSpeed(int port, double speed)
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

void rrDriveTrain::ArcadeDrive(double speed, double turn){
}

void rrDriveTrain::Stop(){
    frontLeftMotor->Set(0);
    frontRightMotor->Set(0);
    backLeftMotor->Set(0);
    backRightMotor->Set(0);
}

void rrDriveTrain::TankDrive(double leftspeed, double rightspeed){
}

void rrDriveTrain::ReverseGear(){
    printf("Rev Gear - DriveTrain\n");
}

void rrDriveTrain::ForwardGear(){
    printf("Fwd Gear - DriveTrain\n");
}

void rrDriveTrain::GearOff() {

}

bool rrDriveTrain::isHighGear() {
    return true;
}

} // namespace frc4783