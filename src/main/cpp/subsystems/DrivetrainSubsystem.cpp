// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DrivetrainSubsystem.h"

using namespace Drivetrain;

DrivetrainSubsystem::DrivetrainSubsystem() {
    _motor_left.ConfigFactoryDefault();
    _motor_right.ConfigFactoryDefault();
    _motor_left.SetInverted(!RIGHT_INVERTED);
    _motor_right.SetInverted(RIGHT_INVERTED);
}

void DrivetrainSubsystem::Periodic() {}

void DrivetrainSubsystem::TankDrive(double left_speed, double right_speed) {
    _drivetrain.TankDrive(left_speed, right_speed);
}

void DrivetrainSubsystem::ArcadeDrive(double speed, double rotation) {
    _drivetrain.ArcadeDrive(speed, rotation);
}