/*
 * splitflap.c
 *
 *  Created on: 29.09.2022
 *      Author: jonas
 */

#include "splitflap.h"
#include "McuULN2003.h"

SF_Handle_t SF_Init(SF_Config_t* instance, int id){
	SF_t splitflap;

	splitflap.magSensor = McuGPIO_InitGPIO(&instance->magSensorConfig);
	splitflap.motor = McuULN2003_InitMotor(&instance->motorConfig);
	splitflap.id = id;

	return &splitflap;
}



void SF_Deinit(SF_t* instance){
	McuULN2003_DeinitMotor(&instance->motorConfig);
	McuGPIO_DeinitGPIO(&instance->magSensorConfig);
}
