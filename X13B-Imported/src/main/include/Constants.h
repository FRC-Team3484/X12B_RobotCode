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

// Uncomment to build code in PID tuning configuration.
//#define C_BUILD_OPT_ELEV_TUNING

/*==========*/
/* CAN ID's */
/*==========*/
#define C_FX_FL_MASTER				1
#define C_FX_FL_SLAVE			   	C_DISABLED_CHANNEL
#define C_FX_FR_MASTER				2
#define C_FX_FR_SLAVE			   	C_DISABLED_CHANNEL
#define C_FX_BL_MASTER				3
#define C_FX_BL_SLAVE			   	C_DISABLED_CHANNEL
#define C_FX_BR_MASTER				4
#define C_FX_BR_SLAVE			   	C_DISABLED_CHANNEL
#define C_SPX_INTAKE                11
#define C_FX_ELEVATEMOTOR          	12
#define C_FX_TILTMOTOR              13
#define C_PIGEON_IMU			   	20
#define C_PCM					   	30
#define C_PDP					   	40

/*===================*/
/* Solenoid Channels */
/*===================*/
#define C_DRIVE_SOL					9 // Octocanum Shifter
#define C_SOL_CLAW_GRIP				10
#define C_SOL_CLAW_TILT				11
#define C_SOL_ELEVATOR_BRAKE		8

/*==============*/
/* DIO Channels */
/*==============*/
#define C_DI_CH_ELEVATOR_TILT_HOME	1
#define C_DI_CH_ELEVATOR_HOME		2
#define C_DI_CH_ELEVATOR_TILT_MAX	0


 /*==========*/
/* Settings */
/*==========*/
#define C_DRIVE_DEADBAND			0.05    // 5% Joystick input
#define C_DRIVE_MAX_DEMAND_HIGH		0.95    // Joystick input scale range (+/-) for normal movements
#define C_DRIVE_MAX_DEMAND_MID		0.75    // Joystick input scale range (+/-) for normal movements
#define C_DRIVE_MAX_DEMAND_FINE		0.2     // Joystick input scale range (+/-) for fine movements
#define C_DT_WHEEL_TAU				20_ms   // Filter time for encoder feedback
#define C_THROTTLE_SCALE_COEFF		1.5     // Scaling Coefficient for throttle input


  /*=======================*/
 /* Drivetrain Parameters */
/*=======================*/
#define C_X23_TRACK_WIDTH			30.0_in
#define C_X23_DT_WHEEL_DIAM			6.0 // in

#define C_DT_RPM_TO_FPS				(units::constants::pi * C_X23_DT_WHEEL_DIAM) / (60.0 * 12.0)
#define C_DT_REV_TO_FT				(units::constants::pi * C_X23_DT_WHEEL_DIAM) / (12.0)

const double C_GEAR_RATIO			= 1.0/((62.0/12.0)*(34.0/18.0));

const double C_FALCON_MOTOR_MAX_RPM		= 6380.0;
const double C_FALCON_MOTOR_MAX_RPM_ACT = 6000.0; // TODO: Get max achievable RPM of drivetrain motors.
const double C_FALCON_ENC_CPR			= 2048.0;

const double C_MAX_GEAR_ENC      		= (C_FALCON_MOTOR_MAX_RPM / 600.0) * (C_FALCON_ENC_CPR / C_GEAR_RATIO);

const double C_DT_SCALE_FACTOR_VELO   	= ((600.0 * C_GEAR_RATIO) / C_FALCON_ENC_CPR) * C_DT_RPM_TO_FPS;	// Velocity scaling factor
const double C_DT_SCALE_FACTOR_POSN   	= (C_GEAR_RATIO / C_FALCON_ENC_CPR) * C_DT_REV_TO_FT;				// Position scaling factor

const units::feet_per_second_t C_GEAR_MAX_SPEED 	= 17.0_fps;
const units::feet_per_second_t C_SHIFT_UP_SPEED     = 5.0_fps;
const units::feet_per_second_t C_SHIFT_DOWN_SPEED 	= 3.5_fps;


  /*===================*/
 /* Intake Parameters */
/*===================*/
#define C_INTAKE_DRIVE_SPEED		1.0 // *100%
#define C_INTAKE_CW_SPEED			C_INTAKE_DRIVE_SPEED
#define C_INTAKE_CCW_SPEED			-1 * C_INTAKE_DRIVE_SPEED

  /*=====================*/
 /* Elevator Parameters */
/*=====================*/
#define Stage_1_ratio  		(58.0/12.0) // (Stage 1 driven)/( Stage 1 driver )
#define Stage_2_ratio  		(50.0/26.0) // (Stage 2 driven)/( Stage 2 driver )
#define Sprocket_ratio  	(12.0/15.0) // (Winch sprocket)/( Gear Out sprocket )
#define Winch_Diameter  	(1.5*units::constants::pi) // (Stage 1 driven)/( Stage 1 driver )

const double C_ELE_GEAR_RATIO			= Winch_Diameter / (Stage_1_ratio * Stage_2_ratio * Sprocket_ratio);

const double C_ELE_MAX_GEAR_ENC      	= (C_FALCON_MOTOR_MAX_RPM / 600.0) * (C_FALCON_ENC_CPR / C_ELE_GEAR_RATIO);

const double C_ELE_SCALE_FACTOR_VELO 	= ((600.0 * C_ELE_GEAR_RATIO) / C_FALCON_ENC_CPR);		// Velocity scaling factor
const double C_ELE_SCALE_FACTOR_POSN	= (C_ELE_GEAR_RATIO / C_FALCON_ENC_CPR) / 0.913;				// Position scaling factor

/*=================*/
/* Tilt Parameters */
/*=================*/
#define Actuator_ratio  		(30.0/12.0) // (Actuator driven)/(Actuator driver )
#define Lead_pitch  			(0.2) // (inches)/(revelutions )

const double C_TILT_GEAR_RATIO			=  0.08 ; //measured  // not measured 1.0  (Actuator_ratio * Lead_pitch);

const double C_TLIT_MAX_GEAR_ENC      	= (C_FALCON_MOTOR_MAX_RPM / 600.0) * (C_FALCON_ENC_CPR / C_TILT_GEAR_RATIO);

const double C_TILT_SCALE_FACTOR_VELO	= ((600.0 * C_TILT_GEAR_RATIO) / C_FALCON_ENC_CPR);		// Velocity scaling factor
const double C_TILT_SCALE_FACTOR_POSN  	= -1.0 * (C_TILT_GEAR_RATIO / C_FALCON_ENC_CPR);				// Position scaling factor

/*======================*/
/* CONTROLLER CONSTANTS */
/*======================*/
#define C_DRIVER_USB                 0
#define C_OPERATOR_USB               1

// Game Device control input scheme 
#define DRV_SCHEME_XBOX       /* Xbox Controller Scheme */
//#define DRV_SCHEME_DS4      /* DualShock 4 Controller Scheme */


// Game Device control input scheme
//#define GD_SCHEME_JOYSTICK    /* Logitech Extreme-3D Pro Joystick Scheme */
//#define GD_SCHEME_XBOX        /* Xbox Controller Scheme */
//#define GD_SCHEME_DS4         /* DualShock 4 Controller Scheme */
#define GD_SCHEME_BB            /* Custom Button Box Scheme*/




/**
 * Set The Driver mode
 */
//#define DRIVE_MODE_TANK
#define DRIVE_MODE_ARCADE
//#define DRIVE_MODE_CURVE
//#define DRIVE_MODE_MECANUM
//#define DRIVE_MODE_OCTOCANUM


#if defined(DRIVE_MODE_TANK)
    #ifdef DRV_SCHEME_XBOX
        #define C_DRIVER_LEFT_AXIS          XBOX_LS_Y
        #define C_DRIVER_RIGHT_AXIS         XBOX_RS_Y
    #elif defined(DRV_SCHEME_DS4)
        #define C_DRIVER_LEFT_AXIS          DS4_LS_Y
        #define C_DRIVER_RIGHT_AXIS         DS4_RS_Y
    #endif
#elif defined(DRIVE_MODE_ARCADE)
    #ifdef DRV_SCHEME_XBOX
        #define C_DRIVER_THROTTLE_AXIS      XBOX_LS_Y
        #define C_DRIVER_STEER_AXIS         XBOX_LS_X
        #define C_DRIVER_OCTO_SHIFT_BTN     XBOX_LB
    #elif defined(DRV_SCHEME_DS4)
        #define C_DRIVER_THROTTLE_AXIS      DS4_LS_Y
        #define C_DRIVER_STEER_AXIS         DS4_RS_X
    #endif
#elif defined(DRIVE_MODE_CURVE)
    #ifdef DRV_SCHEME_XBOX
        #define C_DRIVER_THROTTLE_AXIS      XBOX_LS_Y
        #define C_DRIVER_STEER_AXIS         XBOX_LS_X
    #elif defined(DRV_SCHEME_DS4)
        #define C_DRIVER_THROTTLE_AXIS      DS4_LS_Y
        #define C_DRIVER_STEER_AXIS         DS4_LS_X
    #endif
#elif defined(DRIVE_MODE_MECANUM)
    #ifdef DRV_SCHEME_XBOX
        #define C_DRIVER_FWD_REV_AXIS       XBOX_LS_Y
        #define C_DRIVER_LFT_RHT_AXIS       XBOX_LS_X
        #define C_DRIVER_ROTATE_AXIS        XBOX_RS_X
        #define C_DRIVER_GYRO_RESET         XBOX_BACK
    #elif defined(DRV_SCHEME_DS4)
        #define C_DRIVER_FWD_REV_AXIS       DS4_LS_Y
        #define C_DRIVER_LFT_RHT_AXIS       DS4_LS_X
        #define C_DRIVER_ROTATE_AXIS        DS4_RS_X
        #define C_DRIVER_GYRO_RESET         DS4_SHARE
    #endif
#elif defined(DRIVE_MODE_OCTOCANUM)
    #ifdef DRV_SCHEME_XBOX
        #define C_DRIVER_FWD_REV_AXIS       XBOX_LS_Y
        #define C_DRIVER_LFT_RHT_AXIS       XBOX_LS_X
        #define C_DRIVER_ROTATE_AXIS        XBOX_RS_X
        #define C_DRIVER_OCTO_SHIFT_BTN     XBOX_LB
        #define C_DRIVER_GYRO_RESET_BTN     XBOX_BACK
    #elif defined(DRV_SCHEME_DS4)
        #define C_DRIVER_FWD_REV_AXIS       DS4_LS_Y
        #define C_DRIVER_LFT_RHT_AXIS       DS4_LS_X
        #define C_DRIVER_ROTATE_AXIS        DS4_RS_X
        #define C_DRIVER_OCTO_SHIFT_BTN     DS4_L1
        #define C_DRIVER_GYRO_RESET_BTN     DS4_SHARE
    #endif
#endif


// Fine Adjustment mode
// --------------------
//      When pressed, driver input is scaled to a smaller motor output range.
#define DRIVER_FINE_ADJ_MODE
#ifdef DRIVER_FINE_ADJ_MODE
    #ifdef DRV_SCHEME_XBOX
        #define C_DRIVER_FINE_ADJ_BTN           XBOX_RB
        #define C_DRIVER_FAST_ADJ_BTN           XBOX_R3

    #elif defined(DRV_SCHEME_DS4)
        #define C_DRIVER_FINE_ADJ_BTN           DS4_L1
        #define C_DRIVER_FAST_ADJ_BTN           DS4_L3
    #endif
#endif

/*===================*/
/* Game Device Input */
/*===================*/
#ifdef GD_SCHEME_XBOX
	#define C_GD_COLLECT_CUBE		XBOX_A
	#define C_GD_COLLECT_CONE				XBOX_Y
	#define C_GD_CUBE_EJECT					XBOX_RB
	#define C_GD_CONE_EJECT			XBOX_X
	#define C_GD_FREE			XBOX_B
	#define C_GD_FREE2					XBOX_LB
	#define C_GD_ELE_CUBEMID				XBOX_Y
	#define C_GD_ELE_CONEMID				XBOX_X
	#define C_GD_ELE_UNIVERSAL				XBOX_RB
	#define C_GD_ELE_HOME					XBOX_LB
	#define C_GD_ELE_CUBEHI					XBOX_A
	#define C_GD_ELE_CONEHI					XBOX_B
	#define C_GD_ELE_FEEDER					XBOX_BACK
	// Joysticks!
	#define C_GD_J1_ELE_HIGHT				XBOX_LS_Y
	#define C_GD_J2_ELE_ANGLE				XBOX_RS_Y

#elif defined(GD_SCHEME_JOYSTICK)
	#define C_GD_INTAKE					LE3D_BTN_5
	
#elif defined(GD_SCHEME_DS4)
		#define C_GD_COLLECT_CUBE		DS4_CROSS
	#define C_GD_COLLECT_CONE				DS4_TRIANGLE
	#define C_GD_CUBE_EJECT					DS4_R1
	#define C_GD_CONE_EJECT			DS4_SQUARE
	#define C_GD_FREE			DS4_CIRCLE
	#define C_GD_FREE2					DS4_L1
	#define C_GD_ELE_CUBEMID				DS4_TRIANGLE
	#define C_GD_ELE_CONEMID				DS4_SQUARE
	#define C_GD_ELE_UNIVERSAL				DS4_R1
	#define C_GD_ELE_HOME					DS4_L1
	#define C_GD_ELE_CUBEHI					DS4_CROSS
	#define C_GD_ELE_CONEHI					DS4_CIRCLE
	#define C_GD_ELE_FEEDER					DS4_CIRCLE
	// Joysticks!
	#define C_GD_J1_ELE_HIGHT				DS4_LS_Y
	#define C_GD_J2_ELE_ANGLE				DS4_RS_Y
#elif defined(GD_SCHEME_BB)
	#define C_GD_COLLECT_CUBE				1
	#define C_GD_COLLECT_CONE				3
	#define C_GD_CUBE_EJECT					2
	#define C_GD_CONE_EJECT					4
	#define C_GD_ELE_FEEDER					13
	#define C_GD_ELE_CONEHI					12
	#define C_GD_ELE_CUBEMID				9
	#define C_GD_ELE_CONEMID				11
	#define C_GD_ELE_CubeHybrid				8
	#define C_GD_ELE_HOME					6
	#define C_GD_ELE_CUBEHI					7
	#define C_GD_PICKUP						5
	#define C_GD_ELE_ConeHybrid				10
	// Joysticks!
	#define C_GD_J1_ELE_HIGHT				0
	#define C_GD_J2_ELE_ANGLE				1
#endif

#define C_GD_DEADBAND					0.025    // 5% Joystick input
#define C_GD_L_MAX_DEMAND				0.95
#define C_GD_R_MAX_DEMAND				0.95
/*==================*/
/* Debouncer Config */
/*==================*/
// Driver inputs
#define C_MANUSHIFT_DBNC_TIME		0.100_s	// Force-low gear shift control input debounce time
#define C_FINEADJ_DBNC_TIME			0.100_s	// Fine-Adjustment controller input debounce time

// Game device inputs
#define C_INTAKE_BTN_DBNC_TIME		0.100_s	// Intake deploy controller input debounce time
#define C_Pincher_BTN_DBNC_TIME     0.050_s // Pincher Debounce Time

// Auto-functions
#define C_AUTOSHIFT_DBNC_TIME		0.250_s	// Auto-shift debounce time
#define C_AUTO_DISTANCE_F           13.0
#define C_AUTO_DISTANCE_B           3.25

/*=====================*/
/* Action Delay Config */
/*=====================*/
#define C_INTAKEMOTOR_DELAY_TIME	1.0_s	// Time after intake is deployed before the motor starts running
#define C_AUTOFEED_OFF_DELAY_TIME	1.0_s	// Time after `cargo stored` switch is released before stopping the feed motors.

#define C_AUTO_TAXI_TIME			1.0_s

/*===================*/
/* General Constants */
/*===================*/
#define C_SCAN_TIME					0.020_s
#define C_SCAN_TIME_SEC				C_SCAN_TIME.value() // Seconds'

const std::tuple<int, int> C_BLANK_IDS = std::make_tuple<int, int>(C_DISABLED_CHANNEL, C_DISABLED_CHANNEL);

/*===========================*/
/*Elevator PID Loop Variables*/
/*===========================*/
#define E_Kp 2.35
#define E_Ki 1.75
#define E_dt 0.01
#define E_Kd .25
#define E_Bias 9.0
/*================================*/
/*Elevator Tilt PID Loop Variables*/
/*================================*/
#define T_Kp 5.0
#define T_Ki 1.1
#define T_dt 0.01
#define T_Kd 0.00
#define T_Bias 2.55
#define E_SPgt 0.1
#define T_SPgt 0.1
/*================================*/
/*    Autonomous function maps    */
/*================================*/