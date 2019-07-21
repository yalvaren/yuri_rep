/*
 * Gpio.h
 *
 *  Created on: 2 Oct 2018
 *      Author: Yuri ALVARENGA
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f767xx.h"
#include "stm32f7xx.h"
#include "C_Extensions.h"
#include "Gpio_defs.h"


void Gpio__Initialize(void);
void Gpio__PinConfig(GPIO_PORT_TYPE port,GPIO_PIN_MODE_TYPE pin_mode, uint8 pin,GPIO_PIN_OUTPUT_SPEED_TYPE speed);
void Gpio__PinWrite(GPIO_PORT_TYPE port,uint8 pin,GPIO_PIN_STATE state);
GPIO_PIN_STATE Gpio__PinRead(GPIO_PORT_TYPE port,uint8 pin);


#endif /* GPIO_H_ */
