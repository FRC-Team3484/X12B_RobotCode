#include "commands/ShooterCommand.h"

using namespace ShooterConstants;


ShooterCommand::ShooterCommand(ShooterSubsystem* shooter_subsystem, OI* oi)
    : _shooter_subsystem{shooter_subsystem}, _oi{oi} {
        AddRequirements(_shooter_subsystem);
}

void ShooterCommand::Initialize () {Stop();}

void ShooterCommand::Execute() {
    const double max_speed = 1/(2-_oi -> GetLeftTrigger());
    _shooter_subsystem->Spool(_oi->GetRightTrigger()*max_speed);
    _shooter_subsystem->Spool(-_oi->GetRightTrigger());

    if (_timer.Get() == 0_s && _oi-> GettAPressed()) {_timer.Start();}

    if(_timer.Get() > 0_s) {
        if (!_timer.HasElapsed(PISTON_EXTEND_TIME)) _shooter_subsystem->ExtendFeedPiston();
        else if (!_timer.HasElapsed(PISTON_EXTEND_TIME)) _shooter_subsystem->RetractFeedPiston();
        else{
            _timer.Stop();
            _timer.Reset();
        }
    }
}
void ShooterCommand::End(bool interrupted) {Stop();}
bool ShooterCommand::IsFinished() {return false;}
void ShooterCommand::Stop() {
    _shooter_subsystem->RetractFeedPiston();
    _shooter_subsystem->Pitch(0);
    _shooter_subsystem->Spool(0);

    _timer.Stop();
    _timer.Reset();
    
}
