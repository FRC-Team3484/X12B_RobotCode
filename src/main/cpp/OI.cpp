#include "OI.h"

#include <frc/MathUtil.h>

using namespace Driver;
using namespace Operator;

double Driver_Interface::GetThrottle() {return frc::ApplyDeadband(_driver_controller.GetRawAxis(THROTTLE), Driver::JOYSTICK_DEADBAND);}
double Driver_Interface::GetSteer() {return frc::ApplyDeadband(_driver_controller.GetRawAxis(STEER), Driver::JOYSTICK_DEADBAND);}

double Operator_Interface::GetLauncherPower() {return frc::ApplyDeadband(_operator_controller.GetRawAxis(LAUNCHER_SPEED), Operator::TRIGGER_DEADBAND);}
double Operator_Interface::GetLauncherPitch() {return frc::ApplyDeadband(_operator_controller.GetRawAxis(LAUNCHER_ANGLE), Operator::JOYSTICK_DEADBAND);}