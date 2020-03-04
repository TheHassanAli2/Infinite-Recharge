#include "Robots/RobotBase.h"
#include "commands/DriveWithJoystick.h"
#include "RobotContainer.h"


namespace frc4783{

frc4783::RobotBase::RobotBase()
{
 printf ("RobotBase complete\n");
}

RobotBase::~RobotBase(){
}

void RobotBase::setDriveTrainDefaultCommand(RobotContainer *rc){

    m_drivetrain->SetDefaultCommand(std::move(frc4783::DriveWithJoystick(m_drivetrain, rc)));
}
} // namespace frc4783