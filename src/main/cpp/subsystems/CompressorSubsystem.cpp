#include "frc/Compressor.h"
#include "subsystems/CompressorSubsystem.h"
#include "Constants.h"
 
namespace frc4783 {

CompressorSubsystem::CompressorSubsystem(){ 
 
   compressor = new frc::Compressor();
}
 
 
void CompressorSubsystem::Start(){
  compressor->Start();
}
 
void CompressorSubsystem::Stop(){
   compressor-> Stop();

}

} // namespace frc4783