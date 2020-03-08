/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
 
#include "commands/DriveWithJoystick.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"
#include <frc/smartdashboard/SmartDashboard.h>

namespace frc4783 {

frc4783::DriveWithJoystick::DriveWithJoystick(frc4783::rrDriveTrain* subsystem, frc4783::MainController *controller) : 
        drivetrain(subsystem), m_controller(controller){
        AddRequirements(subsystem);
        printf("DriveWithJoystick init completed");
    }

void frc4783::DriveWithJoystick::Execute(){
    float m_speed = (0.95 * m_controller->getRawAxis(Left_Y_Axis));
    float m_turn = (1.0 * m_controller->getRawAxis(Right_X_Axis));

    if (m_controller->getRawButton(Top_Button)) { // (Y) button on Xbox; Triangle button on PS4
        // Power cell alignment

        // Declares variables for network tables
        nt::NetworkTableEntry angleEntry;
        nt::NetworkTableEntry distanceEntry;
        nt::NetworkTableEntry H_errorEntry;
        
        // Specifies which table data is being collected from
        auto inst = nt::NetworkTableInstance::GetDefault();
        auto table = inst.GetTable("Vision");

        // Gets variable values from network tables
        H_errorEntry = table->GetEntry("H_error");
        angleEntry = table->GetEntry("angle");
        distanceEntry = table->GetEntry("H_dist");

        // Casts variables to doubles
        double H_error = H_errorEntry.GetDouble(0); // Horizontal error from power cell (angle)
        double distance = distanceEntry.GetDouble(0); // Distance from bumper to power cell
        double controllerSpeed = m_controller->getRawAxis(Left_Y_Axis);

        // Adjusts speed proportional to distance of power cell from bumper
        double adjustedSpeed = (distance * -0.015 - 0.28);

        // If no power cells are detected, distance will be equal to -9999
        if (distance == -9999) {
            // If no power cells are detected the robot will not move
            m_speed = 0;
        } else if (controllerSpeed < -0.05) {
            // Adjusts speed using controller input
            m_speed = adjustedSpeed + (controllerSpeed * 0.7);
        } else {
            m_speed = adjustedSpeed;
        }

        // Aligns robot to power cell with angle error
        if (H_error > 0 && H_error < 165 && distance != -9999) {
            m_turn = (H_error * 0.0020) + 0.45;
        } else if (H_error < 0 && H_error > -165 && distance != -9999) {
            m_turn = (H_error * 0.0020) - 0.45;
        } else {
            m_turn = 0;
        }
    }
    drivetrain->ArcadeDrive(m_speed,m_turn);
} 

bool frc4783::DriveWithJoystick::IsFinished(){
    return false;
}

void frc4783::DriveWithJoystick::End(){
    drivetrain->Stop();
}

void frc4783::DriveWithJoystick::Interrupted(){
    End();
}

void frc4783::DriveWithJoystick::Initialize() {
    
}

} /* namespace frc4783 */
