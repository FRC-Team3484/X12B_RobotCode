#include "commands/TeleopDriveCommand.h"

TeleopDriveCommand::TeleopDriveCommand(DrivetrainSubsystem* drivetrain, OI* oi)
    : _drivetrain_subsystem{drivetrain}, _oi{oi} { //Weird case where drivetraina nd oi are constructed outside of {}
    //Reasoning: Initializer List; Based with order
        AddRequirements(_drivetrain_subsystem);
    }
void TeleopDriveCommand::Initialize(){}

void TeleopDriveCommand::Execute() {
    _drivetrain_subsystem->ArcadeDrive(_oi->GetLeftY(), _oi->GetLeftX());
}

void TeleopDriveCommand::End(bool interrupted){
    _drivetrain_subsystem->ArcadeDrive(0,0);
}


bool TeleopDriveCommand::IsFinished(){
    return false;
}