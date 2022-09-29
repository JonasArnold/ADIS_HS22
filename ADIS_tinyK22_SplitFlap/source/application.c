/*
 * application.c
 *
 *  Created on: 22.09.2022
 *      Author: jonas
 */

#include "application.h"
#include "McuWait.h"
#include "McuLED.h"
#include "McuGPIO.h"
#include "McuULN2003.h"
#include "splitflap_pins.h"
#include "splitflap.h"

/* blue led pins */
#define LED_BLUE_GPIO GPIOC
#define LED_BLUE_PORT PORTC
#define LED_BLUE_PIN 2U

static McuLED_Handle_t LED_blue;
static SF_Handle_t splitflap0;

/* Application initialization */
void App_Init(void){
	/* configure blue LED */
	McuLED_Config_t config;
	McuLED_GetDefaultConfig(&config);
	config.isLowActive = true;
	config.isOnInit = false;
	config.hw.gpio = LED_BLUE_GPIO;
	config.hw.port = LED_BLUE_PORT;
	config.hw.pin = LED_BLUE_PIN;
	LED_blue = McuLED_InitLed(&config);

	/* configure the motor */
	McuULN2003_Config_t motor0Config;
	McuULN2003_GetDefaultConfig(&motor0Config);
	motor0Config.hw[0].gpio = STEPPER_MOTOR0_IN1_GPIO;
	motor0Config.hw[0].port = STEPPER_MOTOR0_IN1_PORT;
	motor0Config.hw[0].pin 	= STEPPER_MOTOR0_IN1_PIN;
	motor0Config.hw[1].gpio = STEPPER_MOTOR0_IN2_GPIO;
	motor0Config.hw[1].port = STEPPER_MOTOR0_IN2_PORT;
	motor0Config.hw[1].pin 	= STEPPER_MOTOR0_IN2_PIN;
	motor0Config.hw[2].gpio = STEPPER_MOTOR0_IN3_GPIO;
	motor0Config.hw[2].port = STEPPER_MOTOR0_IN3_PORT;
	motor0Config.hw[2].pin	= STEPPER_MOTOR0_IN3_PIN;
	motor0Config.hw[3].gpio = STEPPER_MOTOR0_IN4_GPIO;
	motor0Config.hw[3].port = STEPPER_MOTOR0_IN4_PORT;
	motor0Config.hw[3].pin 	= STEPPER_MOTOR0_IN4_PIN;
	motor0Config.inverted 	= true;

	/* configure magnetic sensor for motor 0 */
	McuGPIO_Config_t magSensor0Config;
	McuGPIO_GetDefaultConfig(&magSensor0Config);
	magSensor0Config.hw.gpio 	= MAG_MOTOR0_GPIO;
	magSensor0Config.hw.port 	= MAG_MOTOR0_PORT;
	magSensor0Config.hw.pin 	= MAG_MOTOR0_PIN;
	magSensor0Config.isInput = true;
	magSensor0Config.hw.pull = McuGPIO_PULL_UP;

	/* create config instance for splitflap 0 */
	SF_Config_t sfConfig;
	sfConfig.magSensorConfig = magSensor0Config;
	sfConfig.motorConfig = motor0Config;

	/* initialize splitflap 0 */
	splitflap0 = SF_Init(&sfConfig, 0);
}

/* Application run */
void App_Run(void){
    while(1) {
    	McuLED_Toggle(LED_blue);
    	McuWait_Waitms(100); /* wait for 100 ms */
    }
}


/* Application de-initialization */
void App_Deinit(void){

}
