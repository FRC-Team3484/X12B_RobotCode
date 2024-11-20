// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef DRIVETRAINSUBSYSTEM_H
#define DRIVETRAINSUBSYSTEM_H

#include "Constants.h"

#include <ctre/Phoenix.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc2/command/SubsystemBase.h>

class DrivetrainSubsystem : public frc2::SubsystemBase {
    public:
        DrivetrainSubsystem();

        void Periodic() override;
        void TankDrive(double left_speed, double right_speed);
        void ArcadeDrive(double throttle, double rotation);

    private:
        WPI_TalonSRX _motor_left{Drivetrain::MOTOR_LEFT_PORT};
        WPI_TalonSRX _motor_right{Drivetrain::MOTOR_RIGHT_PORT};
        frc::DifferentialDrive _drivetrain{_motor_left, _motor_right};
};

#endif