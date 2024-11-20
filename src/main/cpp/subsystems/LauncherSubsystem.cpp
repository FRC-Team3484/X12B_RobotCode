// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LauncherSubsystem.h"

#include <frc/smartdashboard/SmartDashboard.h>

LauncherSubsystem::LauncherSubsystem() {
    _launch_motor_1.ConfigFactoryDefault();

    TalonSRXConfiguration config;
    _launch_motor_1.GetAllConfigs(config);
    _launch_motor_2.ConfigAllSettings(config);

    _launch_motor_2.Follow(_launch_motor_1, FollowerType::FollowerType_PercentOutput);

    _pitch_motor.ConfigFactoryDefault();
    _pitch_motor.SetNeutralMode(motorcontrol::Brake);
}


void LauncherSubsystem::Periodic() {
    frc::SmartDashboard::PutBoolean("Min Sensor", AtMinPitch());
    frc::SmartDashboard::PutBoolean("Max Sensor", AtMaxPitch());
}

void LauncherSubsystem::Pitch(double power) {
    if (power < 0 && AtMinPitch()) power = 0;
    if (power > 0 && AtMaxPitch()) power = 0;
    _pitch_motor.Set(ControlMode::PercentOutput, power);
}

bool LauncherSubsystem::AtMinPitch() {return !_pitch_limit_switch_low.Get();}
bool LauncherSubsystem::AtMaxPitch() {return !_pitch_limit_switch_high.Get();}

void LauncherSubsystem::Spool(double power) {
    _launch_motor_1.Set(ControlMode::PercentOutput, power);
}