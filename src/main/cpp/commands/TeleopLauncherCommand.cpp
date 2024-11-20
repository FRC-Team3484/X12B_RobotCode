// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TeleopLauncherCommand.h"

TeleopLauncherCommand::TeleopLauncherCommand(LauncherSubsystem* launcher_subsystem, Operator_Interface* oi) 
    : _launcher_subsystem{launcher_subsystem}, _oi{oi} {
  AddRequirements(_launcher_subsystem);
}

// Called when the command is initially scheduled.
void TeleopLauncherCommand::Initialize() {Stop();}

// Called repeatedly when this Command is scheduled to run
void TeleopLauncherCommand::Execute() {
    _launcher_subsystem->Spool(_oi->GetLauncherPower());

    _launcher_subsystem->Pitch(-_oi->GetLauncherPitch());
}

// Called once the command ends or is interrupted.
void TeleopLauncherCommand::End(bool interrupted) {Stop();}

// Returns true when the command should end.
bool TeleopLauncherCommand::IsFinished() {
  return false;
}

void TeleopLauncherCommand::Stop() {
    _launcher_subsystem->Pitch(0);
    _launcher_subsystem->Spool(0);
}