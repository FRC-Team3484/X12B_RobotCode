// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef TELEOPDRIVECOMMAND_H
#define TELEOPDRIVECOMMAND_H

#include "OI.h"
#include "subsystems/DrivetrainSubsystem.h"

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

class TeleopDriveCommand
        : public frc2::CommandHelper<frc2::Command, TeleopDriveCommand> {
    public:
        TeleopDriveCommand(DrivetrainSubsystem* drivetrain, Driver_Interface* oi);

        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override;
    
    private:
        DrivetrainSubsystem* _drivetrain_subsystem;
        Driver_Interface* _oi;
};

#endif