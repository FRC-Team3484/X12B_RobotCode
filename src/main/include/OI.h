#ifndef OI_H
#define OI_H

#include "Constants.h"

#include <frc/XboxController.h>

class Driver_Interface {
    public:
        double GetThrottle();
        double GetSteer();
    private:
        frc::XboxController _driver_controller{Driver::DRIVER_CONTROLLER_PORT};
};

class Operator_Interface {
    public:
        double GetLauncherPitch();
        double GetLauncherPower();
    private:
        frc::XboxController _operator_controller{Operator::OPERATOR_CONTROLLER_PORT};
};

#endif