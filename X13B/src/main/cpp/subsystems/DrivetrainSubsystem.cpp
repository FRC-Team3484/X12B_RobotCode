#include "subsystems/DrivetrainSubsystem.h"

using namespace DrivetrainConstants;

DrivetrainSubsystem::DrivetrainSubsystem() {
    _motor_left.ConfigFactoryDefault(); //Resets the Motor
    _motor_right.ConfigFactoryDefault(); //Resets the Motor
    _motor_left.SetInverted(!RIGHT_INVERTED);
    _motor_right.SetInverted(RIGHT_INVERTED);
    _motor_left.SetNeutralMode(ctre::phoenix::motorcontrol::Brake);
    _motor_right.SetNeutralMode(ctre::phoenix::motorcontrol::Brake);
}

void DrivetrainSubsystem::Periodic() {}

void DrivetrainSubsystem::ArcadeDrive(double speed, double rotation){
    _drivetrain.ArcadeDrive(speed, rotation);
}
