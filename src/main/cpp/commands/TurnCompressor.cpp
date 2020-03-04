#include "commands/TurnCompressor.h"
//#include "Robot.h"
namespace frc4783{

TurnCompressor::TurnCompressor(frc4783::CompressorSubsystem* compressorsubsystem) : m_compressorSubsystem(compressorsubsystem){
  AddRequirements(compressorsubsystem);
    
}
           
void frc4783::TurnCompressor::Initialize(){
  printf("Gearshift init completed\n");
	m_compressorSubsystem->Start();   						 

}

void TurnCompressor::Execute(){
   
}


bool TurnCompressor::IsFinished(){
        
    printf("TurnCompressor::isFinished\n");
    return true;

}

void TurnCompressor::Interrupted(){
printf("TurnCompressor::interrupted\n");
}

void TurnCompressor::End() {
    printf("TurnCompressor::end\n");

} 

} //namespace frc4783