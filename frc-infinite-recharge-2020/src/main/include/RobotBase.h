#ifndef ROBOTBASE_H
#define ROBOTBASE_H

#include <memory>
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"

namespace frc4783 {

class RobotBase {
    public:
        typedef enum encoders {
            MANIPULATOR1,
            MANIPULATOR2
        } Encoder_e;
        
        typedef enum driveTrain {
            BackLeftDrive,
            FrontLeftDrive,
            BackRightDrive,
            FrontRightDrive
        } DriveTrain_e;

        typedef enum driveGroup{
            LeftDrive,
            RightDrive
        } DriveGroup_e;

        typedef enum speedControl {
            ClawMotor,
            ArmMotor,
            ElevatorMotor1,
            ElevatorMotor2
        } SpeedControl_e;

        typedef enum sensors {
            ElevatorLvl1,
            ElevatorLvl2
        } Sensors_e;

        typedef enum solenoid {
            GearShift,
            Solenoid1,
            Solenoid2,
            Solenoid3
        } Solenoid_e;

        typedef struct {
            int FL;
            int BL;
            int FR;
            int BR;
        } DriveMap;

        typedef enum compressor {
            Comp1
        } Compressor_e;

        virtual std::shared_ptr<frc::DifferentialDrive> getDiffDrive();
        virtual std::shared_ptr<frc::SpeedControllerGroup> getDriveGroup(RobotBase::DriveGroup_e driveSide);
        virtual std::shared_ptr<frc::SpeedController> getDriveMotor(RobotBase::DriveTrain_e driveControl) ;
        virtual std::shared_ptr<frc::Compressor> getCompressor(RobotBase::Compressor_e comp);

        virtual std::shared_ptr<frc::Encoder> getEncoder(RobotBase::DriveGroup_e encoder) = 0;
        virtual std::shared_ptr<frc::SpeedController> getMotor(RobotBase::SpeedControl_e motor) = 0;
        virtual std::shared_ptr<frc::ADXRS450_Gyro> getGyro() = 0;
        virtual std::shared_ptr<frc::DoubleSolenoid> getSolenoid(RobotBase::Solenoid_e solenoid) = 0;

    protected:
	    static std::shared_ptr<frc::SpeedController> frontLeftDrive;
	    static std::shared_ptr<frc::SpeedController> backLeftDrive;
	    static std::shared_ptr<frc::SpeedController> frontRightDrive;
	    static std::shared_ptr<frc::SpeedController> backRightDrive;
	    static std::shared_ptr<frc::DifferentialDrive> differentialDrive;
	    static std::shared_ptr<frc::SpeedControllerGroup> leftDrive;
	    static std::shared_ptr<frc::SpeedControllerGroup> rightDrive;
        static std::shared_ptr<frc::Compressor> compressorMain;
};

} // namespace frc4783

#endif // ROBOTBASE_H