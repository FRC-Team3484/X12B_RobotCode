// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef LAUNCHERSUBSYSTEM_H
#define LAUNCHERSUBSYSTEM_H

#include "Constants.h"

#include <ctre/Phoenix.h>
#include <frc/DigitalInput.h>
#include <frc2/command/SubsystemBase.h>

class LauncherSubsystem : public frc2::SubsystemBase {
    public:
        LauncherSubsystem();

        void Periodic() override;
        void Pitch(double power);
        bool AtMinPitch();
        bool AtMaxPitch();
        void Spool(double power);

    private:
        WPI_TalonSRX _launch_motor_1{Launcher::LAUNCH_MOTOR_PORT_1};
        WPI_TalonSRX _launch_motor_2{Launcher::LAUNCH_MOTOR_PORT_2};

        WPI_VictorSPX _pitch_motor{Launcher::PITCH_MOTOR_PORT};
        frc::DigitalInput _pitch_limit_switch_low{Launcher::PITCH_LIMIT_SWITCH_LOW};
        frc::DigitalInput _pitch_limit_switch_high{Launcher::PITCH_LIMIT_SWITCH_HIGH};
};

#endif