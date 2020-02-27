#include "frc/Compressor.h"
#include "subsystems/CompressorSubsystem.h"
#include "Constants.h"
#include "RobotContainer.h"
 
namespace frc4783 {

CompressorSubsystem::CompressorSubsystem(int pcmID ){ 
 
   compressor = new frc::Compressor(pcmID);
}
 
 
void CompressorSubsystem::Start(){
  compressor->Start();
}
 
void CompressorSubsystem::Stop(){
   compressor->Stop();
}

void CompressorSubsystem::TurnonCompressor(int pcmID) {
    //printf("CompressorSubsystem:::TurnonCompressor/", pcmID);
}

} // namespace frc4783