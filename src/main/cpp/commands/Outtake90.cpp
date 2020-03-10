#include "commands/Outtake90.h"
#include "subsystems/Powercell.h"

namespace frc4783 {

Outtake90::Outtake90(Powercell* subsystem) : powercell(subsystem){
    AddRequirements(subsystem);
        powercellCheck = false;
}

void Outtake90::Initialize() {
    
    if (powercellCheck){
        powercell->Stop();
        powercellCheck = false;
    }
    else {
        powercell->Turn90();
        powercellCheck = true;
    }
}

void Outtake90::Execute(){} 

bool Outtake90::IsFinished(){
    return true;
}
void Outtake90::End(){
    powercell->Stop();
}

void Outtake90::Interrupted(){

}

} /* namespace frc4783 */