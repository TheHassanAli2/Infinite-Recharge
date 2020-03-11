#include "commands/Outtake45.h"
#include "subsystems/Powercell.h"
#include "frc/Servo.h"

namespace frc4783 {

Outtake45::Outtake45(Powercell* subsystem) : powercell(subsystem){
    std::shared_ptr<frc::Servo> OuttakeMotor;
    AddRequirements(subsystem);
        powercellCheck = false;
}

void Outtake45::Initialize() {
    /*if (powercellCheck){
        powercell->Stop();
        powercellCheck = false;
        }*/
    //else {
        movement++;
        if (movement==1){
            // open
          powercell->OpenHatch();
          powercellCheck = true;
          printf ("90 turn complete\n");
        }
        else if (movement==2){
            //load
          powercell->Loading();
          powercellCheck = true;
          printf ("half-open\n");
        }
        else if (movement==3){
            // close
          powercell->Close();
          powercellCheck = true;
          movement=0;
          printf ("full close\n ");
        } 
        /*else if (movement==4) {
            powercell->Turn90();
            powercellCheck = true;
            movement=0;
        }*/
        /*else {
            powercell->Stop();
            powercellCheck = false;
        }*/
    //}
    End();
    //OuttakeMotor->SetAngle(0);
}

void Outtake45::Execute(){
    //powercell->State();
} 

bool Outtake45::IsFinished(){
    return true;
}

void Outtake45::End(){
    powercell->Stop();
}

void Outtake45::Interrupted(){

}

} /* namespace frc4783 */