/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <string>

namespace frc4783 {

/**
 * Command use to rotate the Control Panel
 *
 * This command will toggle the motor to rotate the Control panel ON or OFF
 * 
 */
class ControllerTest
    : public frc2::CommandHelper<frc2::CommandBase, ControllerTest> {
   public:
      explicit ControllerTest(std::string buttonStr, int buttonId);
       void Initialize();
       void Execute();    
       bool IsFinished();
       void End();    
       void Interrupted();
    
private:
  std::string m_buttonStr;
    int m_id;
};


} // namespace frc4783