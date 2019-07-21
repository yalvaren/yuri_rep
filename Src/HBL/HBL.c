/*
 * HBL.c
 *
 *  Created on: 27 Oct 2018
 *      Author: Yuri ALVARENGA
 */

#include "HBL.h"
#include "Gpio_config.h"
#include "Gpio.h"

const PIN_CONFIG_DATA_TYPE OUTPUT_PORT_CONFIG[NUM_OF_OUTPUT_PIN] = OUTPUT_PIN_LIST;
const PIN_CONFIG_DATA_TYPE INPUT_PORT_CONFIG[NUM_OF_INPUT_PIN] = INPUT_PIN_LIST;


void HBL__Initialize(void)
{
	uint8 pin_counter;

   // Configure the GPIO pins based on the PIN_CONFIG_LIST table
	for (pin_counter = 0; pin_counter < NUM_OF_OUTPUT_PIN; pin_counter++)
	{

		Gpio__PinConfig(OUTPUT_PORT_CONFIG[pin_counter].port, OUTPUT_PORT_CONFIG[pin_counter].mode,
				        OUTPUT_PORT_CONFIG[pin_counter].pin,  OUTPUT_PORT_CONFIG[pin_counter].speed);

	}


	for(pin_counter = 0; pin_counter < NUM_OF_INPUT_PIN; pin_counter++)
	{

		Gpio__PinConfig(INPUT_PORT_CONFIG[pin_counter].port, INPUT_PORT_CONFIG[pin_counter].mode,
				        INPUT_PORT_CONFIG[pin_counter].pin,  INPUT_PORT_CONFIG[pin_counter].speed);

	}
}
void HBL__SetDigitalOutput(DIGITAL_OUTPUTS_TYPE digital_output, ON_OFF_TYPE state)
{
	if (digital_output < DO_MAX)
	{
		Gpio__PinWrite(OUTPUT_PORT_CONFIG[digital_output].port,OUTPUT_PORT_CONFIG[digital_output].pin,(GPIO_PIN_STATE)state);
	}
}

BOOL_TYPE HBL__GetDigitalOutput(DIGITAL_OUTPUTS_TYPE digital_output)
{
	BOOL_TYPE state;
	state = FALSE;

	return(state);
}
uint16 HBL__GetAnalogOutput(ANALOG_INPUTS_TYPE digital_output)
{
	uint16 value;
	value = 0;

	return(value);
}
