// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <units/time.h>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace OperatorConstants {
    constexpr int DRIVER_CONTROLLER_PORT = 0;
    constexpr double TRIGGER_DEADBAND = 0.01;
    constexpr double JOYSTICK_DEADBAND = 0.02;
}

namespace DrivetrainConstants {
    constexpr bool RIGHT_INVERTED = true;
    constexpr int MOTOR_LEFT_PORT = 3;
    constexpr int MOTOR_RIGHT_PORT = 2;
}

namespace AutonNames {
    const std::string AUTON_NONE = "Nothing";
    const std::string AUTON_1 = "Auton 1";
    const std::string AUTON_2 = "Auton 2";
}

namespace ShooterConstants {
    constexpr int PITCH_MOTOR_PORT = 10;

    //Analog In
    constexpr int PITCH_LIMIT_SWITCH_LOW = 2;
    constexpr int PITCH_LIMIT_SWITCH_HIGH = 1;

    constexpr int SHOOT_MOTOR_PORT_1 = 0;
    constexpr int SHOOT_MOTOR_PORT_2 = 1;

    constexpr int FEED_PISTON_PORT = 7;

    constexpr units::second_t PISTON_EXTEND_TIME = 0.5_s;
    constexpr units::second_t PISTON_RETRACT_TIME = 1.0_s;
}

#endif