// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <frc/TimedRobot.h>
#include "RobotContainer.h"
#include "Constants.h"
#include <FRC3484_Lib/utils/SC_Datatypes.h>
#include <FRC3484_Lib/utils/SC_Functions.h>

// Controller Inputs
#include <frc/XboxController.h>
#include <frc/PS4Controller.h>
#include <frc/Joystick.h>


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
  std::optional<frc2::CommandPtr> m_autonomousCommand;

  SC::SC_Range<double> Throttle_Range_Normal = {-C_DRIVE_MAX_DEMAND_MID, C_DRIVE_MAX_DEMAND_MID};
  SC::SC_Range<double> Throttle_Range_Fine = {-C_DRIVE_MAX_DEMAND_FINE, C_DRIVE_MAX_DEMAND_FINE};
  SC::SC_Range<double> Throttle_Range_High = {-C_DRIVE_MAX_DEMAND_HIGH, C_DRIVE_MAX_DEMAND_HIGH};

  double X_Demand, Z_Demand;

  RobotContainer X13B;

  frc::XboxController *GP1_Driver;
  RobotContainer m_container;

  

};
