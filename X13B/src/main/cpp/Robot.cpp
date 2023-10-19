// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include "Constants.h"

#include "FRC3484_Lib/utils/SC_Functions.h"

#include "frc/PneumaticsModuleType.h"
#include <frc/smartdashboard/SmartDashboard.h>

#include <frc2/command/CommandScheduler.h>
#include "ctre/phoenix/motorcontrol/Faults.h"

#include "networktables/NetworkTableInstance.h"

using namespace frc;
using namespace SC;

void Robot::RobotInit() {
// Clear out the network table
	this->_nt_table = nt::NetworkTableInstance::GetDefault().GetTable("X13B");
	// std::vector<std::string> entries = _nt_table->GetKeys();
	// for(unsigned int i = 0; i < entries.size(); i++)
	// {
	// 	_nt_table->(entries.at(i));
	// }

	// Initialize Controllers
  GP1_Driver = new frc::XboxController(C_DRIVER_USB);
  
	_drivetrain = new X13B_Drivetrain(C_X22_TRACK_WIDTH,
						std::make_tuple<int, int>(C_FX_LEFT_MASTER, C_FX_LEFT_SLAVE),
						std::make_tuple<int, int>(C_FX_RIGHT_MASTER, C_FX_RIGHT_SLAVE));

}

void Robot::RobotPeriodic() {
  frc2::CommandScheduler::GetInstance().Run();
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::DisabledExit() {}

void Robot::AutonomousInit() {
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::AutonomousExit() {}

void Robot::TeleopInit() {
  if (m_autonomousCommand) {
    m_autonomousCommand->Cancel();
  }
}

void Robot::TeleopPeriodic() {}

void Robot::TeleopExit() {}

void Robot::TestInit() {
  frc2::CommandScheduler::GetInstance().CancelAll();
}

void Robot::TestPeriodic() {}

void Robot::TestExit() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
