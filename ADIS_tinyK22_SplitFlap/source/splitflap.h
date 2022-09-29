/*
 * splitflap.h
 *
 *  Created on: 29.09.2022
 *      Author: jonas
 */

#ifndef SPLITFLAP_H_
#define SPLITFLAP_H_

#include "McuULN2003.h"
#include "McuGPIO.h"

/* define splitflap handle type. SF_Handle_t points to SF_t */
typedef void* SF_Handle_t;

typedef struct {
  McuULN2003_Handle_t motor;
  McuGPIO_Handle_t magSensor;
  int id;
} SF_t;

typedef struct {
  McuULN2003_Config_t motorConfig;
  McuGPIO_Config_t magSensorConfig;
} SF_Config_t;

/* split flap initialization */
SF_Handle_t SF_Init(SF_Config_t* instance, int id);

/* split flap deinitialization */
void SF_Deinit(SF_Handle_t* instance);

#endif /* SPLITFLAP_H_ */
