#ifndef COMPRESSORSUBSYTEM_H
#define COMPRESSORSUBSYTEM_H
#pragma once
 
 
 #include "frc/Compressor.h"
 #include <frc2/command/Subsystem.h>

namespace frc4783  {

class CompressorSubsystem : public frc2::Subsystem {

public:
    CompressorSubsystem(int pcmID );
    virtual ~CompressorSubsystem();
    

   void Start();

   void Stop();
 
protected:
   void TurnonCompressor(int pcmID);

   frc::Compressor *compressor;


};

} // namespace4783

#endif // COMPRESSORSUBSYTEM_H;