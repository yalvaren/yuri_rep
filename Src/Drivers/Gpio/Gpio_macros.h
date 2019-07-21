/*
 * Gpio_macros.h
 *
 *  Created on: 2 Oct 2018
 *      Author: Yuri ALVARENGA
 */

#ifndef GPIO_MACROS_H_
#define GPIO_MACROS_H_

#include "stm32f767xx.h"

#define GPIO__PIN_SET(PORT, PORTBIT, STATE)                {((*(volatile GPIO_DEF *)GPIO_PORT_LIST[PORT]).BSRR) = (STATE<<PORTBIT);}


#endif /* GPIO_MACROS_H_ */
