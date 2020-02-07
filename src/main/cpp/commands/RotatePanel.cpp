/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include 

#include "subsystems/ControlPanel.h"
#include "commands/RotatePanel.h"

RotatePanel::RotatePanel(ControlPanel* subsystem)
    : m_subsystem{subsystem} {}

void RotatePanel::InitDefaultCommand (){
    Robot::motor->TurnControlPanelClockwise();
    SetTimeout(2.5);
}

void RotatePanel::Execute(){
    SmartDashboard::PutString ("Spinning ", "Panel");
}

