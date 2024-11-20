// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef TELEOPLAUNCHERCOMMAND_H
#define TELEOPLAUNCHERCOMMAND_H

#include "OI.h"
#include "Constants.h"
#include "subsystems/LauncherSubsystem.h"

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class TeleopLauncherCommand
        : public frc2::CommandHelper<frc2::Command, TeleopLauncherCommand> {
    public:
        TeleopLauncherCommand(LauncherSubsystem* launcher_subsystem, Operator_Interface* oi);

        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override;
    
    private:
        void Stop();
        LauncherSubsystem* _launcher_subsystem;
        Operator_Interface* _oi;
};

#endif