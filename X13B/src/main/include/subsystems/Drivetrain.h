#ifndef SC_drivetrain_h
#define SC_drivetrain_h

// #include "FRC3484_Lib/subsystems/SC_DifferentialDrive.h"

#include "Constants.h"
#include "Globals.h"

#include "FRC3484_Lib/utils/SC_Datatypes.h"

#include "units/length.h"
#include "units/velocity.h"
#include "units/angular_velocity.h"

#include "ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h"

#include "frc/drive/DifferentialDrive.h"
#include "frc/kinematics/DifferentialDriveWheelSpeeds.h"
#include "frc/kinematics/DifferentialDriveKinematics.h"
class X13B_Drivetrain
{
public:
	X13B_Drivetrain(units::length::inch_t trackwidth, std::tuple<int, int> LeftIDs, std::tuple<int, int> RightIDs);


	~X13B_Drivetrain();

	void Drive(double Throttle, double Rotation, bool ShiftOverride, bool EBrake);

	
	void SetCoastMode();
	void SetBrakeMode();

private:
	void _InitMotor(ctre::phoenix::motorcontrol::can::WPI_TalonSRX* Motor, bool Invert, ctre::phoenix::motorcontrol::can::WPI_TalonSRX* Master = NULL);

	//SC::SC_DifferentialDrive *drive;
	frc::DifferentialDrive              *drive;
	frc::DifferentialDriveKinematics    *ddKinematics;
	frc::DifferentialDrive::WheelSpeeds wsInput;

	ctre::phoenix::motorcontrol::can::WPI_TalonSRX *Motor_Left_Master, *Motor_Left_Slave;
	ctre::phoenix::motorcontrol::can::WPI_TalonSRX *Motor_Right_Master, *Motor_Right_Slave;

	double throttleDemand, rotationDemand, throttleCoeff;
	bool inHighGear, inLowGear;
};


#endif // SC_drivetrain_H (for Completeness)
