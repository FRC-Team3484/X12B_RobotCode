#include "subsystems/Drivetrain.h"

#include "units/math.h"

using namespace SC;
using namespace frc;
using namespace nt;
using namespace units::length;
using namespace units::velocity;
using namespace units::angular_velocity;
using namespace ctre::phoenix::motorcontrol::can;
using namespace ctre::phoenix::motorcontrol;


X13B_Drivetrain::X13B_Drivetrain(inch_t trackwidth, std::tuple<int, int> LeftIDs, std::tuple<int, int> RightIDs)
{
	int sCh = -1;

	// Initialize front right wheel and slave controller
	if(LeftIDs != C_BLANK_IDS) 
	{ 
		Motor_Left_Master = new WPI_TalonSRX(std::get<0>(LeftIDs));
		_InitMotor(Motor_Left_Master, true);

		sCh = std::get<1>(LeftIDs);

		if(sCh != C_DISABLED_CHANNEL) { Motor_Left_Slave = new WPI_TalonSRX(sCh); _InitMotor(Motor_Left_Slave, true, Motor_Left_Master); }
		else { Motor_Left_Slave = NULL; }
	} 
	else { Motor_Left_Master = NULL; Motor_Left_Slave = NULL; }
	

	// Initialize front left wheel and slave controller
	 if(RightIDs != C_BLANK_IDS) 
	{ 
		Motor_Right_Master = new WPI_TalonSRX(std::get<0>(RightIDs));
		_InitMotor(Motor_Right_Master, false);

		sCh = std::get<1>(RightIDs);

		if(sCh != C_DISABLED_CHANNEL) { Motor_Right_Slave = new WPI_TalonSRX(sCh); _InitMotor(Motor_Right_Slave, false, Motor_Right_Master); }
		else { Motor_Right_Slave = NULL; }
	} 
	else { Motor_Right_Master = NULL; Motor_Right_Slave = NULL; }
	
	drive = new DifferentialDrive(*Motor_Left_Master, *Motor_Right_Master);
	ddKinematics = new DifferentialDriveKinematics(trackwidth);
}

X13B_Drivetrain::~X13B_Drivetrain()
{
	if(drive != NULL) { delete drive; }
	if(ddKinematics != NULL) { delete ddKinematics; }
	if(Motor_Left_Master != NULL) { delete Motor_Left_Master; }
	if(Motor_Left_Slave != NULL) { delete Motor_Left_Slave; }
	if(Motor_Right_Master != NULL) { delete Motor_Right_Master; }
	if(Motor_Right_Slave != NULL) { delete Motor_Right_Slave; }

	// if(ntLeftOut != NULL) { delete ntLeftOut; }
	// if(ntRightOut != NULL) { delete ntRightOut; }
	// if(ntThrottleIn != NULL) { delete ntThrottleIn; }
	// if(ntRotationIn != NULL) { delete ntRotationIn; }
	// if(ntInLowGear != NULL) { delete ntInLowGear; }
	// if(ntInHighGear != NULL) { delete ntInHighGear; }
	//if(ntRampTime != NULL) { delete ntRampTime; }
	// if(ntLeftVel != NULL) { delete ntLeftVel; }
	// if(ntRightVel != NULL) { delete ntRightVel; }
	// if(ntChassisVx != NULL) { delete ntChassisVx; }
	// if(ntChassisVy != NULL) { delete ntChassisVy; }
	// if(ntChassisOmega != NULL) { delete ntChassisOmega; }
}

void X13B_Drivetrain::Drive(double Throttle, double Rotation, bool ShiftOverride, bool EBrake)
{
	this->throttleDemand = std::copysign(std::min((Throttle*Throttle)*this->throttleCoeff, std::abs(Throttle)), Throttle);
	this->rotationDemand = Rotation;
	
	if(Motor_Left_Master != NULL) 	{ Motor_Left_Master->ConfigOpenloopRamp(0.5); }//this->_nt_table->GetNumber("DT Ramp Time", 2.0)); }
	if(Motor_Right_Master != NULL) 	{ Motor_Right_Master->ConfigOpenloopRamp(0.5); }//this->_nt_table->GetNumber("DT Ramp Time", 2.0)); }
	if(Motor_Left_Slave != NULL) 	{ Motor_Left_Slave->ConfigOpenloopRamp(0.5); }//this->_nt_table->GetNumber("DT Ramp Time", 2.0)); }
	if(Motor_Right_Slave != NULL) 	{ Motor_Right_Slave->ConfigOpenloopRamp(0.5); }//this->_nt_table->GetNumber("DT Ramp Time", 2.0)); }

	if((drive != NULL) && (Motor_Left_Master != NULL) && (Motor_Right_Master != NULL))
	{
	   	// Convert driver inputs to drivetrain outputs
		wsInput = drive->ArcadeDriveIK(this->throttleDemand , -Rotation, false);
		// Set motor outputs (direct control)

		if(EBrake)
		{
			SetBrakeMode();
			Motor_Left_Master->Set(ControlMode::PercentOutput, 0.0);
			Motor_Right_Master->Set(ControlMode::PercentOutput, 0.0);
		}
		else
		{
			SetCoastMode();
			Motor_Left_Master->Set(ControlMode::PercentOutput, wsInput.left);
			Motor_Right_Master->Set(ControlMode::PercentOutput, wsInput.right);
		}

		// Handle motor safety
		drive->Feed();
		drive->FeedWatchdog();
		drive->Check();
		drive->CheckMotors();	
	}
}


void X13B_Drivetrain::_InitMotor(WPI_TalonSRX* Motor, bool Invert, WPI_TalonSRX* Master)
{
	if(Motor != NULL)
	{
		Motor->SetInverted(Invert);
		Motor->SetNeutralMode(NeutralMode::Brake);
		Motor->ConfigOpenloopRamp(2);
		Motor->ConfigClosedloopRamp(0);
		Motor->ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 10);
		Motor->SetSelectedSensorPosition(0);

		if(Master != NULL) { Motor->Follow(*Master); }
	}
}

void X13B_Drivetrain::SetBrakeMode()
{
	if(this->Motor_Left_Master != NULL) { this->Motor_Left_Master->SetNeutralMode(NeutralMode::Brake); }
	if(this->Motor_Left_Slave != NULL) { this->Motor_Left_Slave->SetNeutralMode(NeutralMode::Brake); }
	if(this->Motor_Right_Master != NULL) { this->Motor_Right_Master->SetNeutralMode(NeutralMode::Brake); }
	if(this->Motor_Right_Slave != NULL) { this->Motor_Right_Slave->SetNeutralMode(NeutralMode::Brake); }
}

void X13B_Drivetrain::SetCoastMode()
{
	if(this->Motor_Left_Master != NULL) { this->Motor_Left_Master->SetNeutralMode(NeutralMode::Coast); }
	if(this->Motor_Left_Slave != NULL) { this->Motor_Left_Slave->SetNeutralMode(NeutralMode::Coast); }
	if(this->Motor_Right_Master != NULL) { this->Motor_Right_Master->SetNeutralMode(NeutralMode::Coast); }
	if(this->Motor_Right_Slave != NULL) { this->Motor_Right_Slave->SetNeutralMode(NeutralMode::Coast); }
}