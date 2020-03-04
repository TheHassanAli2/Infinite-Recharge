#ifndef TURNCOMPRESSOR_H
#define TURNCOMPRESSOR_H
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/CompressorSubsystem.h"

//#define pcmID

namespace frc4783{

class TurnCompressor :
  public frc2::CommandHelper<frc2::CommandBase,TurnCompressor> {

public:
  
  TurnCompressor(frc4783::CompressorSubsystem* compressorsubsystem);
       
  void Initialize();
  void Execute();    
  bool IsFinished();
  void End();    
  void Interrupted();

  //explicit TurnCompressor(frc4783::CompressorSubsystem* CompressorSubsystem);

private:
  frc4783::CompressorSubsystem* m_compressorSubsystem;
};    

} //namespace frc4783
#endif //TURNCOMPRESSOR