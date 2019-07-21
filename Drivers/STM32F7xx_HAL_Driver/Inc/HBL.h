/*
 * HBL.h
 *
 *  Created on: 27 Oct 2018
 *      Author: Yuri ALVARENGA
 */

#ifndef HBL_HBL_H_
#define HBL_HBL_H_

#include "C_Extensions.h"
#include "HBL_config.h"

void HBL__Initialize(void);
void HBL__SetDigitalOutput(DIGITAL_OUTPUTS_TYPE digital_output, ON_OFF_TYPE state);
BOOL_TYPE HBL__GetDigitalOutput(DIGITAL_OUTPUTS_TYPE digital_output);
BOOL_TYPE HBL__GetDigitalInput(DIGITAL_INPUTS_TYPE digital_input);
uint16 HBL__GetAnalogOutput(ANALOG_INPUTS_TYPE digital_output);

#endif /* HBL_HBL_H_ */
