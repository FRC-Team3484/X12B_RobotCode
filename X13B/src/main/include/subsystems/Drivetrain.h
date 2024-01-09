#ifndef X13B_drivetrain_h
#define X13B_drivetrain_h


#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/drive/DifferentialDrive.h>
#include <units/length.h>
#include <ctre/phoenix/motorcontrol/NeutralMode.h>
#include <FRC3484_Lib/utils/SC_Functions.h>

class X13B_Drivetrain {

    public:
        X13B_Drivetrain();
        X13B_Drivetrain(int CANID_Left, int CANID_Right, units::length::inch_t trackWidth);

        ~X13B_Drivetrain();
        
        void SetCoastMode();
        void SetBrakeMode();


        void Drive(bool EBrake);
        void DriveArcade(double speed, double rotation, bool EBrake);
        void _InitMotor(ctre::phoenix::motorcontrol::can::WPI_TalonSRX *Motor, bool Invert);


    private:
        ctre::phoenix::motorcontrol::can::WPI_TalonSRX *_Motor_Left_Control, *_Motor_Right_Control;
        // frc::DifferentialDriveKinematics  *_ddriveKinematics;
        //frc::DifferentialDrive *_drive;
        frc::DifferentialDrive::WheelSpeeds wsInput;



        // double _convertedRight, _convertedLeft;





};

 #endif
