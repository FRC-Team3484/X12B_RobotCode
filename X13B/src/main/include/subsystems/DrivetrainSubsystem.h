#ifndef DRIVETRAINSUBSYSTEM_H
#define DRIVETRAINSUBSYSTEM_H


#include "Constants.h"
#include "ctre/Phoenix.h"
#include "frc/drive/DifferentialDrive.h"
#include "frc2/command/SubsystemBase.h"


class DrivetrainSubsystem:public frc2::SubsystemBase {
    public:
        DrivetrainSubsystem(); //Default Constructor
        void Periodic() override;
        void ArcadeDrive(double speed, double rotation);

    private:
        WPI_TalonSRX _motor_left{DrivetrainConstants::MOTOR_LEFT_PORT};
        WPI_TalonSRX _motor_right{DrivetrainConstants::MOTOR_RIGHT_PORT};
        frc::DifferentialDrive _drivetrain{_motor_left, _motor_right};

};

#endif