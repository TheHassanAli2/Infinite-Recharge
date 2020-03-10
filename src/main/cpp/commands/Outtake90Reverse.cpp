#include "commands/Outtake90Reverse.h"
#include "subsystems/Powercell.h"

namespace frc4783 {

Outtake90Reverse::Outtake90Reverse(Powercell* subsystem) : powercell(subsystem){
    AddRequirements(subsystem);
        powercellCheck = false;
}

void Outtake90Reverse::Initialize() {
    
    if (powercellCheck){
        powercell->Stop();
        powercellCheck = false;
    }
    else {
        powercell->Turn90Reverse();
        powercellCheck = true;
    }
}

void Outtake90Reverse::Execute(){} 

bool Outtake90Reverse::IsFinished(){
    powercell->ballReset();
    return true;
}

void Outtake90Reverse::End(){
    powercell->Stop();
}

void Outtake90Reverse::Interrupted(){

}

} /* namespace frc4783 */