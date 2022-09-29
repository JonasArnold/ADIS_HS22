/*
 * application.h
 *
 *  Created on: 22.09.2022
 *      Author: jonas
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "splitflap_pins.h"

#define LED_BLUE_GPIO GPIOC
#define LED_BLUE_PORT PORTC
#define LED_BLUE_PIN 2U

/* Application initialization */
void App_Init(void);

/* Application run */
void App_Run(void);

/* Application de-initialization */
void App_Deinit(void);

#endif /* APPLICATION_H_ */
