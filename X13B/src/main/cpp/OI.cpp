#include "OI.h"

using namespace OperatorConstants;

double OI::GetLeftY() {return frc::ApplyDeadband(_drive_controller.GetLeftY(), JOYSTICK_DEADBAND);}
double OI::GetLeftX() {return frc::ApplyDeadband(_drive_controller.GetLeftX(), JOYSTICK_DEADBAND);}
double OI::GetRightY() {return frc::ApplyDeadband(_drive_controller.GetRightY(), JOYSTICK_DEADBAND);}
double OI::GetLeftTrigger() {return frc::ApplyDeadband(_drive_controller.GetLeftTriggerAxis(), JOYSTICK_DEADBAND);}
double OI::GetRightTrigger() {return frc::ApplyDeadband(_drive_controller.GetRightTriggerAxis(), JOYSTICK_DEADBAND);}

bool OI::GettAPressed() {return _drive_controller.GetAButtonPressed();}