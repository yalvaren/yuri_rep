/*
 * Gpio_config.h
 *
 *  Created on: 28 Oct 2018
 *      Author: Yuri ALVARENGA
 */

#ifndef DRIVERS_CONFIG_GPIO_CONFIG_H_
#define DRIVERS_CONFIG_GPIO_CONFIG_H_

#include "Gpio_defs.h"

//! Structure to define the pin configuration.
typedef struct
{
	GPIO_PORT_TYPE port;
    uint8 pin;
    GPIO_PIN_MODE_TYPE mode;
    GPIO_PIN_OUTPUT_SPEED_TYPE speed;
    uint8 dummy1;
    uint8 dummy2;
    uint8 dummy3;
} PIN_CONFIG_DATA_TYPE;




#define OUTPUT_PIN_LIST { \
	/*port          pin   pin_config          pin speed                device       param0      param1               */  \
	{GPIO_PORTB    ,7    ,OUTPUT_PUSH_PULL   ,GPIO_SPEED_HIGH        ,0          ,0        ,0},  /* Blue LED     */  \
    {GPIO_PORTB   ,14    ,OUTPUT_PUSH_PULL   ,GPIO_SPEED_HIGH        ,0          ,0        ,0},} /* Red LED      */

#define NUM_OF_OUTPUT_PIN   2 // Must be equal to the number of the OUTPUT_PIN_CONFIG_LIST components

#define INPUT_PIN_LIST { \
	/*port          pin   pin_config          pin speed                device       param0      param1              */  \
    {GPIO_PORTC,    7,    INPUT_PULL_UP,      GPIO_SPEED_HIGH,         0,           0,          0},} /* User switch */

#define NUM_OF_INPUT_PIN   1 // Must be equal to the number of the INTPUT_PIN_CONFIG_LIST components

#define NUM_OF_PIN_  (NUM_OF_OUTPUT_PIN + INTPUT_PIN_LIST)

#endif /* DRIVERS_CONFIG_GPIO_CONFIG_H_ */
