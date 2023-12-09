// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc2/command/CommandScheduler.h>

using namespace SC;
using namespace frc;

void Robot::RobotInit() {
  GP1_Driver = new XboxController(/*USB Port*/ C_DRIVER_USB);
  // Craetes the controller; sets port
	Throttle_Range_High(-C_DRIVE_MAX_DEMAND_HIGH, C_DRIVE_MAX_DEMAND_HIGH);
	Throttle_Range_Normal(-C_DRIVE_MAX_DEMAND_MID, C_DRIVE_MAX_DEMAND_MID);
	Throttle_Range_Fine(-C_DRIVE_MAX_DEMAND_FINE, C_DRIVE_MAX_DEMAND_FINE);
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
}

/**
 * This function is called once each time the robot enters Disabled mode. You
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
}

void Robot::AutonomousPeriodic() {}



void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by anothN/Aer command, remove
  // this line or comment it out.
}

/**
 * This function is called periodically during operator control.
 */


void Robot::TeleopPeriodic() 
{
    // Y_Demand = F_Scale(-1.0, 1.0, Throttle_Range_Normal, GP1_Driver->GetRawAxis(C_DRIVER_FWD_REV_AXIS)); //->GetLeftY());
    Y_Demand = F_Scale(-1.0, 1.0, Throttle_Range_Normal, GP1_Driver->GetRawAxis(C_DRIVER_THROTTLE_AXIS)); //->GetLeftX());
    Z_Demand = F_Scale(-1.0, 1.0, Throttle_Range_Normal, GP1_Driver->GetRawAxis(C_DRIVER_STEER_AXIS)); //->GetRightX());

    X13B._drivetrain.DriveArcade(F_Deadband(Y_Demand, C_DRIVE_DEADBAND),
                                F_Deadband(Z_Demand, C_DRIVE_DEADBAND),
                                GP1_Driver->GetRawButton(C_DRIVER_OCTO_SHIFT_BTN));
}
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
