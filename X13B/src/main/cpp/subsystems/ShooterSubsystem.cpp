#include <subsystems/ShooterSubsystem.h>

ShooterSubsystem::ShooterSubsystem() {
    _shoot_motor_1.ConfigFactoryDefault();

    TalonSRXConfiguration config; // Config Object
    //CTRE Specific Thing; get all settings on a CTRE Object

    _shoot_motor_1.GetAllConfigs(config);
    _shoot_motor_2.ConfigAllSettings(config);

    _shoot_motor_2.Follow(_shoot_motor_1, FollowerType::FollowerType_PercentOutput);
    
    _pitch_motor.ConfigFactoryDefault();
    _pitch_motor.SetNeutralMode(motorcontrol::Brake);
}


void ShooterSubsystem::Periodic() {}

void ShooterSubsystem::Pitch(double power) {
    if (power < 0 && AtMinPitch()) power=0;
    if (power > 0 && AtMaxPitch()) power=0;
    _pitch_motor.Set(ControlMode::PercentOutput, power);
}

void ShooterSubsystem::ExtendFeedPiston() {
    _feed_piston.Set(true);
}

bool ShooterSubsystem::AtMinPitch() {return _pitch_limit_switch_low.Get();}
bool ShooterSubsystem::AtMaxPitch() {return _pitch_limit_switch_high.Get();}

void ShooterSubsystem::RetractFeedPiston() {
    _feed_piston.Set(false);
}

void ShooterSubsystem::Spool(double power) {
    _shoot_motor_1.Set(ControlMode::PercentOutput, power);
}

