#include "RobotBase.h"

namespace frc4783 {
std::shared_ptr<frc::SpeedController> RobotBase::frontLeftDrive;
std::shared_ptr<frc::SpeedController> RobotBase::backLeftDrive;
std::shared_ptr<frc::SpeedController> RobotBase::frontRightDrive;
std::shared_ptr<frc::SpeedController> RobotBase::backRightDrive;
std::shared_ptr<frc::DifferentialDrive> RobotBase::differentialDrive;
std::shared_ptr<frc::SpeedControllerGroup> RobotBase::leftDrive;
std::shared_ptr<frc::SpeedControllerGroup> RobotBase::rightDrive;
std::shared_ptr<frc::Compressor> RobotBase::compressorMain;

std::shared_ptr<frc::DifferentialDrive> RobotBase::getDiffDrive(){
    return differentialDrive;
}

std::shared_ptr<frc::SpeedControllerGroup> RobotBase::getDriveGroup(RobotBase::DriveGroup_e driveSide){
    	switch (driveSide) {
		case LeftDrive : return leftDrive;
		case RightDrive : return rightDrive;
		default : break;
	}
    return nullptr;
}

std::shared_ptr<frc::SpeedController> RobotBase::getDriveMotor(RobotBase::DriveTrain_e driveControl){
	switch (driveControl){
		case BackLeftDrive : return backLeftDrive;
		case BackRightDrive : return backRightDrive;
		case FrontLeftDrive : return frontLeftDrive;
		case FrontRightDrive : return frontRightDrive;
		default : break;
	}
    return nullptr;
}

std::shared_ptr<frc::Compressor> RobotBase::getCompressor(RobotBase::Compressor_e comp) {
	return nullptr;
}

} // namespace frc4783