// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#ifndef ROBOT_H
#define ROBOT_H

#include "OI.h"
#include "Constants.h"
#include "commands/TeleopDriveCommand.h"
#include "commands/ShooterCommand.h"
#include "subsystems/DrivetrainSubsystem.h"
#include "subsystems/ShooterSubsystem.h"

#include <string>
#include <optional>

#include <fmt/core.h>
#include <frc/TimedRobot.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/CommandScheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/smartdashboard/SendableChooser.h>
class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;

 private:
  // Have it empty by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
    OI _oi{};

    DrivetrainSubsystem _drivetrain_subsystem{};
    ShooterSubsystem _shooter_subsystem{};

    TeleopDriveCommand _drive_command{&_drivetrain_subsystem, &_oi};
    ShooterCommand _shooter_command{&_shooter_subsystem, &_oi};


    //type of data to return
    frc::SendableChooser<std::string> _auton_chooser;
    std::string _auton_selected;
    std::optional<frc2::CommandPtr> _auton_command;


  

};

#endif