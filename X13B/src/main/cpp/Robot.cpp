// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <frc/smartdashboard/SmartDashboard.h>

using namespace AutonNames;

using namespace frc;

void Robot::RobotInit() {
  //Chooser; Give Value and Display
  _auton_chooser.SetDefaultOption(AUTON_NONE, AUTON_NONE);
  _auton_chooser.AddOption(AUTON_1, AUTON_1);
  _auton_chooser.AddOption(AUTON_2, AUTON_2);
  frc::SmartDashboard::PutData("Autons", &_auton_chooser);
}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  frc2::CommandScheduler::GetInstance().Run();
  frc::SmartDashboard::PutBoolean("Limit Switch Max", _shooter_subsystem.AtMaxPitch());
  frc::SmartDashboard::PutBoolean("Limit Switch Min", _shooter_subsystem.AtMinPitch());

}
/**
 This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
    _auton_selected = _auton_chooser.GetSelected();

  if (_auton_selected == AUTON_NONE) {
    fmt::print("No Auton Selected");
    //_auton_command = _do_nothing_command.ToPtr();
  } if (_auton_selected == AUTON_1) {
    fmt::print("Auton 1 Selected");
    //_auton_command = _auton1_command.ToPtr();
  } else if (_auton_selected == AUTON_2) {
    fmt::print("Auton 2 Selected");
    //_auton_command = _auton2_command.ToPtr();
  }

  if (_auton_command) {
    _auton_command->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}



void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by anothN/Aer command, remove
  // this line or comment it out.

  if (_auton_command) {
    _auton_command->Cancel();
  }
  _drive_command.Schedule();
  _shooter_command.Schedule();
}

/**
 * This function is called periodically during operator control.
 */


void Robot::TeleopPeriodic() {}
// /**
//  * This function is called periodically during test mode.
//  */
void Robot::TestPeriodic() {}

/**
 * This function is called once when the robot is first started up.
 */
void Robot::SimulationInit() {}

/**
 * This function is called periodically whilst in simulation.
 */
void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
