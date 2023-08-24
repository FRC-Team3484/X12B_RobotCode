// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "units/velocity.h"
#include "units/length.h"
#include "units/constants.h"

#include "FRC3484_Lib/utils/SC_ControllerMaps.h"

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

#define C_DISABLED_CHANNEL			-1	// Device or channel is not used.

/*==========*/
/* CAN ID's */
/*==========*/
#define C_FX_LEFT_MASTER			1
#define C_FX_LEFT_SLAVE				2
#define C_FX_RIGHT_MASTER			3
#define C_FX_RIGHT_SLAVE			4
#define C_SPX_INTAKE                5
#define C_SPX_FEED_MASTER           6
#define C_SPX_FEED_SLAVE            7
#define C_FX_LAUNCH_1               8
#define C_FX_LAUNCH_2               9
#define C_SPX_TURRET                10
#define C_SRX_CLIMB                 12



/*===================*/
/* Solenoid Channels */
/*===================*/
#define C_KICK_SOL

/*==============*/
/* DIO Channels */
/*==============*/

/*==========*/
/* Settings */
/*==========*/
#define C_DRIVE_DEADBAND			0.05    // 5% Joystick input
#define C_DRIVE_MAX_DEMAND			0.95    // Joystick input scale range (+/-) for normal movements

/*=======================*/
/* Drivetrain Parameters */
/*=======================*/
#define C_X22_TRACK_WIDTH			30.0_in
#define C_X22_DT_WHEEL_DIAM			6.0 // in

#define C_DT_RPM_TO_FPS				(units::constants::pi * C_X22_DT_WHEEL_DIAM) / (60.0 * 12.0)

const double C_GEAR_RATIO_LO		= 1.0 / 18.0;
const double C_GEAR_RATIO_HI		= 1.0 / 9.56;

const double C_DT_MOTOR_MAX_RPM		= 6380.0;
const double C_DT_MOTOR_MAX_RPM_ACT = 6000.0; // TODO: Get max achievable RPM of drivetrain motors.
const double C_DT_ENC_CPR			= 2048.0;

const double C_MAX_GEAR_ENC_LO      = (C_DT_MOTOR_MAX_RPM / 600.0) * (C_DT_ENC_CPR / C_GEAR_RATIO_LO);
const double C_MAX_GEAR_ENC_HI      = (C_DT_MOTOR_MAX_RPM / 600.0) * (C_DT_ENC_CPR / C_GEAR_RATIO_HI);

/*======================*/
/* CONTROLLER CONSTANTS */
/*======================*/
#define C_DRIVER_USB                 0
#define C_GAMEDEV_USB                1

// Game Device control input scheme 
// #define GD_SCHEME_JOYSTICK	/* Logitech Extreme-3D Pro Joystick Scheme */
#define GD_SCHEME_XBOX			/* Xbox Controller Scheme */
//#define GD_SCHEME_DS4 		/* DualShock 4 Controller Scheme */

/**
 * Set The Driver mode
 */
//#define DRIVE_MODE_TANK
#define DRIVE_MODE_ARCADE
//#define DRIVE_MODE_CURVE

#if defined(DRIVE_MODE_TANK)
	#define C_DRIVER_LEFT_AXIS			XBOX_LS_Y
	#define C_DRIVER_RIGHT_AXIS			XBOX_RS_Y
#elif defined(DRIVE_MODE_ARCADE)
	#define C_DRIVER_THROTTLE_AXIS		XBOX_LS_Y 
	#define C_DRIVER_STEER_AXIS			XBOX_RS_X //XBOX_LS_X (arcade)
#elif defined(DRIVE_MODE_CURVE)
	#define C_DRIVER_THROTTLE_AXIS		XBOX_LS_Y
	#define C_DRIVER_STEER_AXIS			XBOX_LS_X
#endif

#define C_DRIVER_SHIFT_LOW_BTN        	XBOX_A
#define C_DRIVER_EBRAKE					XBOX_LB

#define DRIVER_FINE_ADJ_MODE
#ifdef DRIVER_FINE_ADJ_MODE
#define C_DRIVE_ADJ_BTN               	XBOX_RB
#endif

/*===================*/
/* Game Device Input */
/*===================*/
#ifdef GD_SCHEME_XBOX
	#define C_GD_INTAKE					XBOX_A
	#define C_GD_LAUNCH_AUTO			XBOX_B
	#define C_GD_FORCE_FEED				XBOX_X
	#define C_GD_FEED_EJECT				XBOX_Y
	#define C_GD_LAUNCH_LONG			XBOX_LB
	#define C_GD_LAUNCH_EJECT			XBOX_BACK
	#define C_GD_LAUCH_SHORT			XBOX_RB

	//Turret override axis
	#define C_GD_TURRET_OR_AXIS			XBOX_LS_X
#elif defined(GD_SCHEME_JOYSTICK)
	#define C_GD_INTAKE					LE3D_BTN_5
	#define C_GD_LAUNCH_AUTO			LE3D_TRIGGER
	#define C_GD_FORCE_FEED				LE3D_BTN_8
	#define C_GD_FEED_EJECT				LE3D_HAT_DOWN
	#define C_GD_LAUNCH_LONG			LE3D_BTN_2
	#define C_GD_LAUNCH_EJECT			LE3D_HAT_UP

	//Turret override axis
	#define C_GD_TURRET_OR_AXIS			LE3D_X
#elif defined(GD_SCHEME_DS4)
	#define C_GD_INTAKE					DS4_CROSS
	#define C_GD_LAUNCH_AUTO			DS4_CIRCLE
	#define C_GD_FORCE_FEED				DS4_SQUARE
	#define C_GD_FEED_EJECT				DS4_TRIANGLE
	#define C_GD_LAUNCH_LONG			DS4_L1
	#define C_GD_LAUNCH_EJECT			DS4_R1

	//Turret override axis
	#define C_GD_TURRET_OR_AXIS			DS4_LS_X
#endif

/*===================*/
/* General Constants */
/*===================*/
#define C_SCAN_TIME					0.020_s
#define C_SCAN_TIME_SEC				C_SCAN_TIME.value() // Seconds

const std::tuple<int, int> C_BLANK_IDS = std::make_tuple<int, int>(C_DISABLED_CHANNEL, C_DISABLED_CHANNEL);
