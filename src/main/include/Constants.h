#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "FRC3484_Lib/utils/SC_ControllerMaps.h"

namespace Operator {
    constexpr int OPERATOR_CONTROLLER_PORT = 1;
    constexpr int LAUNCHER_ANGLE = XBOX_RS_Y;
    constexpr int LAUNCHER_SPEED = XBOX_RT;
    constexpr double TRIGGER_DEADBAND = 0.00;
    constexpr double JOYSTICK_DEADBAND = 0.02;
}

namespace Driver {
    constexpr int DRIVER_CONTROLLER_PORT = 0;
    constexpr int THROTTLE = XBOX_LS_Y;
    constexpr int STEER = XBOX_LS_X;
    constexpr double JOYSTICK_DEADBAND = 0.02;
}

namespace Drivetrain {
    constexpr bool RIGHT_INVERTED = true;
    constexpr int MOTOR_LEFT_PORT = 3;
    constexpr int MOTOR_RIGHT_PORT = 2;
}

namespace Launcher {
    constexpr int PITCH_MOTOR_PORT = 10;
    constexpr bool PITCH_MOTOR_INVERTED = false;
    constexpr int PITCH_LIMIT_SWITCH_LOW = 2;
    constexpr int PITCH_LIMIT_SWITCH_HIGH = 1;

    constexpr int LAUNCH_MOTOR_PORT_1 = 7;
    constexpr int LAUNCH_MOTOR_PORT_2 = 11;
}
#endif