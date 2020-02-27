
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/CompressorSubsystem.h"

#define pcmID

class TurnCompressor

    : public frc2::CommandHelper<frc2::CommandBase,TurnCompressor> {
   public:
     TurnCompressor();
       void Start(pcmID);
       void Stop(pcmID);

       // I'm not sure if I need this
       //void Initialize();
       //void Execute();    
       //bool IsFinished();
       //void End();    
       //void Interrupted();



 explicit TurnCompressor(frc4783::CompressorSubsystem* CompresorSubsystem);

private:
    frc4783::CompressorSubsystem *m_compressorSubsystem;
    bool on;
};    