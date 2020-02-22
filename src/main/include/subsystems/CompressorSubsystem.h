#ifndef COMPRESSORSUBSYTEM_H
#define COMPRESSORSUBSYTEM_H
#pragma once
 
 
 #include "frc/Compressor.h"
 #include <frc2/command/Subsystem.h>

namespace frc4783  {

class CompressorSubsystem : public frc2::Subsystem {


public:
    CompressorSubsystem();
    virtual ~CompressorSubsystem();


   void Start();
   void Stop();
 
protected:
   frc::Compressor* compressor;
};

} // namespace 4783





#endif // COMPRESSORSUBSYTEM_H