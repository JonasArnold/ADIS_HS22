/*
 * platform.c
 *
 *  Created on: 29.09.2022
 *      Author: jonas
 */

#include "platform.h"
#include "McuLib.h"
#include "McuWait.h"
#include "McuLED.h"
#include "McuGPIO.h"
#include "McuULN2003.h"

void PL_Init(void){
	McuLib_Init();
	McuWait_Init();
	McuGPIO_Init();
	McuLED_Init();
	McuULN2003_Init();
}


void PL_Deinit(void){
	McuULN2003_Deinit();
	McuLED_Deinit();
	McuGPIO_Deinit();
	McuWait_Deinit();
	McuLib_Deinit();
}
