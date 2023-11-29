#include "subsystems/Drivetrain.h"
#include "Constants.h"

using namespace ctre::phoenix::motorcontrol::can;
using namespace ctre::phoenix::motorcontrol;
using namespace frc;
using namespace SC;


X13B_Drivetrain::X13B_Drivetrain(int CANID_Left, int CANID_Right, units::length::inch_t trackWidth){
    
    if (CANID_Left != C_DISABLED_CHANNEL){
        _Motor_Left_Control = new WPI_TalonSRX(CANID_Left);
        _InitMotor(_Motor_Left_Control, false); // check which one should be positive



    }
    else {_Motor_Left_Control = NULL;}

    if (CANID_Right != C_DISABLED_CHANNEL){
        _Motor_Right_Control = new WPI_TalonSRX(CANID_Right);
        _InitMotor(_Motor_Right_Control, true);

    }
    else {_Motor_Right_Control = NULL;}

    //_drive = new DifferentialDrive(*_Motor_Left_Control, *_Motor_Right_Control);
    _ddriveKinematics = new DifferentialDriveKinematics(trackWidth);

    // The following are already set in the _InitMotor
    
    // if(_Motor_Left_Control != NULL) {_Motor_Left_Control->ConfigOpenloopRamp(0.5);}
    // // From Zero to Full Speed Time
    // if(_Motor_Right_Control != NULL) {_Motor_Right_Control->ConfigOpenloopRamp(0.5);}
};

X13B_Drivetrain::~X13B_Drivetrain() {
    //if(_drive != NULL) {delete _drive;}
    if(_Motor_Left_Control != NULL) {delete _Motor_Left_Control;}
    if(_Motor_Right_Control != NULL) {delete _Motor_Right_Control;}
    if(_ddriveKinematics != NULL) {delete _ddriveKinematics;}
};

// gets called in the DriveArcade

void X13B_Drivetrain::Drive(bool EBrake) { // Percentage of Motor Output

    // F_Scale does a linear transformation of the form
    // \frac{d-c}{b-a}\times (x-a)+c
    // _convertedRight = F_Scale(-1.0, 0.0, 1.0, 1.0, this -> wsInput.right); 
    // _convertedLeft = F_Scale(-1.0, 0.0, 1.0, 1.0, this -> wsInput.left);
    // Conversions are not normalized for negative values; must use median

    if (EBrake) {
       SetBrakeMode();
        _Motor_Right_Control-> Set(ControlMode::PercentOutput, 0.0);
        _Motor_Left_Control-> Set(ControlMode::PercentOutput, 0.0);
    }
    else {
       
        SetCoastMode();
        _Motor_Right_Control-> Set(ControlMode::PercentOutput,this->wsInput.right);
        _Motor_Left_Control-> Set(ControlMode::PercentOutput, this->wsInput.left);

    }
    //_drive->Feed();
    //_drive->FeedWatchdog();
    //_drive->Check();
    //_drive->CheckMotors();
};

void X13B_Drivetrain::DriveArcade(double speed, double rotation, bool EBrake) {



    if ((_Motor_Left_Control != NULL) && (_Motor_Right_Control != NULL)) {
        
        wsInput = DifferentialDrive::TankDriveIK(speed, rotation, false);

    }
    Drive(EBrake);

};

void X13B_Drivetrain::_InitMotor(WPI_TalonSRX *Motor, bool Invert) {
    if(Motor != NULL) {
        Motor->SetInverted(Invert); 
        // 100% to -100% for a drivetrain
        //invert on one of them
        // Handle Limit Switches
        Motor->ConfigForwardSoftLimitEnable(false);
        Motor->ConfigForwardLimitSwitchSource(LimitSwitchSource_Deactivated,LimitSwitchNormal_Disabled);
        Motor->ConfigReverseSoftLimitEnable(false);
        Motor->ConfigReverseLimitSwitchSource(LimitSwitchSource_Deactivated,LimitSwitchNormal_Disabled);

        Motor->ConfigClosedloopRamp(0); //have code looping to hold a position (follow a path; hold a position)
        Motor->SetNeutralMode(NeutralMode::Brake);
        Motor->ConfigOpenloopRamp(0.5);
        // during tele-opp
        // Motor->ConfigSelectedFeedbackSensor();
        // Motor->SetSelectedSensorPosition();
    }
}

void X13B_Drivetrain::SetBrakeMode()
{
	if(this->_Motor_Left_Control != NULL) { this->_Motor_Left_Control->SetNeutralMode(NeutralMode::Brake); }
	if(this->_Motor_Right_Control != NULL) { this->_Motor_Right_Control->SetNeutralMode(NeutralMode::Brake); }
}

void X13B_Drivetrain::SetCoastMode()
{
	if(this->_Motor_Left_Control != NULL) { this->_Motor_Left_Control->SetNeutralMode(NeutralMode::Coast); }
	if(this->_Motor_Right_Control != NULL) { this->_Motor_Right_Control->SetNeutralMode(NeutralMode::Coast); }
}