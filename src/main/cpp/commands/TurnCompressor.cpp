#include "subsystems/CompressorSubsystem.h"
#include "commands/TurnCompressor.h"
//#include "Robot.h"


TurnCompressor::TurnCompressor(frc4783::CompressorSubsystem* compressorsubsystem)
    : m_compressorSubsystem(compressorsubsystem),
      on(false) 
    {
      printf("Turn Compressor ctor\n");
    
    }
           
void TurnCompressor::Start() {
        if (on) {
        m_compressorSubsystem->TurnonCompressor(0);
        on = false;
    }  
    else {
        m_compressorSubsystem->TurnonCompressor(0);
        on = true;
    }

    printf("RotatePanel::initialize: %d\n", on);

}s 

void TurnCompressor::Stop() {
    printf("RotatePanel::end\n");
    m_compressorSubsystem-> Stop();
}
