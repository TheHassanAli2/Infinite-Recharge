#include "subsystems/CompressorSubsystem.h"
#include "Constants.h"
 
namespace frc4783 {


CompressorSubsystem::CompressorSubsystem() {
  compressorOn = true;
  Stop();
}

void CompressorSubsystem::Start() {
  printf("START CALLED!!");
  if  (compressorOn){
    printf("ON CALL \n");
    if (compressor != nullptr) {
      printf("Turning OFF!");
      compressorOn = false;
      compressor->SetClosedLoopControl(compressorOn);
    }
  }else{
    if (compressor != nullptr) {
      printf("Truning ON!!");
      compressorOn = true;
      compressor->SetClosedLoopControl(compressorOn);
    }
  }
}

void CompressorSubsystem::Stop(){
  compressor.reset(new frc::Compressor());
  
   
}



}// namespace frc4783