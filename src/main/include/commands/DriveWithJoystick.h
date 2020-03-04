/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef DRIVEWITHJOYSTICK_H
#define DRIVEWITHJOYSTICK_H

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <RobotContainer.h>
#include "subsystems/DriveTrain.h"
#include "Robot.h"

/**
 * An example command that uses an example subsystem.
 * pianist
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */

namespace frc4783 {

class DriveWithJoystick
    : public frc2::CommandHelper<frc2::CommandBase, DriveWithJoystick> {
public:
    /**
     * Creates a new ExampleCommand.
     *
     * @param subsystem The subsystem used by this command.
     */
    DriveWithJoystick(DriveTrain* subsystem, RobotContainer* contained);

    void Initialize() override;

    void Execute() override;

    bool IsFinished() override; 

    void End();

    void Interrupted();

private:
    DriveTrain* drivetrain;
    frc4783::RobotContainer* container; 
};

} /* namespace frc4783 */

#endif // DRIVEWITHJOYSTICK_H