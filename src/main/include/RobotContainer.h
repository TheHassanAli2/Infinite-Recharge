/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#ifndef ROBOTCONTAINER_H
#define ROBOTCONTAINER_H

#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/Command.h>
#include <frc/buttons/JoystickButton.h>
#include <frc/Joystick.h>
#include <subsystems/rrTwoSpeed.h>
#include <frc2/command/ParallelRaceGroup.h>

#include "Controller/MainController.h"

#include <subsystems/ControlPanel.h>
#include <commands/RotatePanel.h>
#include <commands/Solenoid.h>
#include "subsystems/Climber.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */

//ya feel?

namespace frc4783{
class RobotContainer {
public:
    RobotContainer();

    frc2::Command* GetAutonomousCommand();

private:

    frc4783::MainController * m_controller;

    frc4783::ControlPanel m_ctrlPanel;
    frc4783::Climber m_climber;
    
    //Pointer Object of rrDriveTrain and object of rrTwoSpeed
    frc4783::rrDriveTrain *m_drivetrain;
    
    void ConfigureButtonBindings();
}; 

} // namespace frc4783

#endif // ROBOTMAP_H
