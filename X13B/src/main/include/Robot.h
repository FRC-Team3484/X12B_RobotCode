// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <optional>

#include <frc/TimedRobot.h>
#include <frc2/command/CommandPtr.h>

#include "RobotContainer.h"

#include "subsystems/Drivetrain.h"

#include <frc/XboxController.h>
#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/filter/Debouncer.h>
#include <frc/PneumaticHub.h>
#include <frc/PowerDistribution.h>

#include <frc/Timer.h>

#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableValue.h>


class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void DisabledExit() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void AutonomousExit() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TeleopExit() override;
  void TestInit() override;
  void TestPeriodic() override;
  void TestExit() override;

 private:
  std::optional<frc2::CommandPtr> m_autonomousCommand;

  RobotContainer m_container;

	std::shared_ptr<nt::NetworkTable> _nt_table;

	frc::PneumaticHub *pch;
	frc::PowerDistribution *pdp;

	X13B_Drivetrain *_drivetrain;

	SC::SC_Range<double> Throttle_Range_Normal;
	SC::SC_Range<double> Throttle_Range_Fine;

#if defined(DRIVE_MODE_ARCADE) || defined(DRIVE_MODE_ARCADE)
	double throttleDemand, turnDemand;
#elif defined(DRIVE_MODE_TANK)
	double rightDemand, leftDemand;
#endif
	bool forceLowGear;

	frc::XboxController *GP1_Driver; // GP = Gamepad
	frc::XboxController *BB_GameDevice;
#ifndef CLIMB_CONTROL_SPERATE
	frc::Joystick       *JS_Climb; 
#endif
};
