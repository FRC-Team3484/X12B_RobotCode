#ifndef SHOOTERSUBSYSTEM_H
#define SHOOTERSUBSYSTEM_H

#include "Constants.h"
#include "ctre/Phoenix.h"
#include "frc/Solenoid.h"
#include "frc/DigitalInput.h"
#include "frc2/command/Subsystem.h"
#include "frc2/command/SubsystemBase.h"

class ShooterSubsystem:public frc2::SubsystemBase {
    public:
        ShooterSubsystem();
        void Periodic() override; // If anyhting for subsystem regularly
        void Pitch(double power); // Moves Up and Down
        bool AtMinPitch();
        bool AtMaxPitch();
        void Spool(double power); //RPMs; Power Level
        void ExtendFeedPiston();
        void RetractFeedPiston();
    private:
        WPI_TalonSRX _shoot_motor_1{ShooterConstants::SHOOT_MOTOR_PORT_1};
        WPI_TalonSRX _shoot_motor_2{ShooterConstants::SHOOT_MOTOR_PORT_2};

        WPI_TalonSRX _pitch_motor{ShooterConstants::PITCH_MOTOR_PORT};
        frc::DigitalInput _pitch_limit_switch_low{ShooterConstants::PITCH_LIMIT_SWITCH_LOW};
        frc::DigitalInput _pitch_limit_switch_high{ShooterConstants::PITCH_LIMIT_SWITCH_HIGH};

        frc::Solenoid _feed_piston{frc::PneumaticsModuleType::CTREPCM/*Type of Motor*/, ShooterConstants::FEED_PISTON_PORT};
        
};





#endif