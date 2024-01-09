#ifndef SHOOTERCOMMAND_H
#define SHOOTERCOMMAND_H

#include "OI.h"
#include "Constants.h"
#include "subsystems/ShooterSubsystem.h"

#include <units/time.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class ShooterCommand //Import the command helper for setting up commands
    :public frc2::CommandHelper<frc2::CommandBase, ShooterCommand> {
    
    public:
        explicit ShooterCommand(ShooterSubsystem* shooter_subsystem, OI *oi);
        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
        bool IsFinished() override;
    
    private:
        void Stop();
        ShooterSubsystem* _shooter_subsystem;
        OI* _oi;
        frc::Timer _timer;

};
#endif
