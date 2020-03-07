#include <subsystems/PowerCell.h>

namespace frc4783 {

const int PowerCell::ServoPwmPort = 6;
const int PowerCell::OpenAngle = 90;
const int PowerCell::LoadAngle = 45;
const int PowerCell::ClosedAngle = 0;

PowerCell::PowerCell() {
    m_servo = new frc::Servo(ServoPwmPort);
    printf("Servo; min= %f  max= %f", 
        m_servo->GetMinAngle(), m_servo->GetMaxAngle());
}

PowerCell::~PowerCell() {

}

void PowerCell::openHatch() {
    m_servo->SetAngle(OpenAngle);
}

void PowerCell::closeHatch() {
    m_servo->SetAngle(ClosedAngle);
}

void PowerCell::loading() {
    m_servo->SetAngle(LoadAngle);
}

double PowerCell::getHatchAngle() {
    return m_servo->GetAngle();
}

double PowerCell::getHatchValue() {
    return m_servo->Get();
}


} // namespace frc4783