#ifndef OI_H
#define OI_H

#include "Constants.h"
#include <frc/XboxController.h>
#include <frc/MathUtil.h>

class OI {
    public:
        double GetLeftY();
        double GetLeftX();
        double GetRightX();
        double GetRightY();
        double GetLeftTrigger();
        double GetRightTrigger();
        bool GettAPressed();
    private:
        frc::XboxController _drive_controller{OperatorConstants::DRIVER_CONTROLLER_PORT};

};


#endif