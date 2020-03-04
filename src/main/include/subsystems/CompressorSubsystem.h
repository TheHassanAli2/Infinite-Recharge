#pragma once
#ifndef COMPRESSORSUBSYTEM_H
#define COMPRESSORSUBSYTEM_H
 
 
 #include "frc/Compressor.h"
 #include <frc2/command/Subsystem.h>
 


namespace frc4783  {

class CompressorSubsystem : public frc2::Subsystem {

public:
public:
  CompressorSubsystem();
  void Start() ;
  void Stop() ;

private: 
   std::shared_ptr<frc::Compressor> compressor;
   bool compressorOn;

};

} // namespace4783 

#endif // COMPRESSORSUBSYTEM_H;