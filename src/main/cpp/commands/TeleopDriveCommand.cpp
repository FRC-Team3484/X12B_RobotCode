// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TeleopDriveCommand.h"

TeleopDriveCommand::TeleopDriveCommand(DrivetrainSubsystem* drivetrain, Driver_Interface* oi)
    : _drivetrain_subsystem{drivetrain}, _oi{oi} {
    AddRequirements(_drivetrain_subsystem);
}

void TeleopDriveCommand::Initialize() {}

void TeleopDriveCommand::Execute() {
    _drivetrain_subsystem->ArcadeDrive(_oi->GetThrottle(), _oi->GetSteer());
}

void TeleopDriveCommand::End(bool interrupted) {
    _drivetrain_subsystem->TankDrive(0, 0);
}

bool TeleopDriveCommand::IsFinished() {
  return false;
}
