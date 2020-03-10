#include "commands/Outtake40Reverse.h"
#include "subsystems/Powercell.h"

namespace frc4783 {

Outtake40Reverse::Outtake40Reverse(Powercell* subsystem) : powercell(subsystem){
    AddRequirements(subsystem);
        powercellCheck = false;
}

void Outtake40Reverse::Initialize() {
    
    if (powercellCheck){
        powercell->Stop();
        powercellCheck = false;
    }
    else {
        powercell->Turn45Reverse();
        powercellCheck = true;
    }
}

void Outtake40Reverse::Execute(){} 

bool Outtake40Reverse::IsFinished(){
    powercell->ballReset();
    return true;
}

void Outtake40Reverse::End(){
    powercell->Stop();
}

void Outtake40Reverse::Interrupted(){

}

} /* namespace frc4783 */