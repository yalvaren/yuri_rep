/*
 * Gpio.c
 *
 *  Created on: 2 Oct 2018
 *      Author: Yuri ALVARENGA
 */
#include "stm32f7xx_hal_rcc.h"
#include "Gpio.h"


const volatile GPIO_TypeDef * GPIO_PORT_LIST[] = {  (volatile GPIO_TypeDef *)GPIOA_BASE,
                                                    (volatile GPIO_TypeDef *)GPIOB_BASE,
												    (volatile GPIO_TypeDef *)GPIOC_BASE,
                                                    (volatile GPIO_TypeDef *)GPIOD_BASE,
                                                    (volatile GPIO_TypeDef *)GPIOE_BASE,
													(volatile GPIO_TypeDef *)GPIOF_BASE,
													(volatile GPIO_TypeDef *)GPIOG_BASE,
													(volatile GPIO_TypeDef *)GPIOH_BASE,
													(volatile GPIO_TypeDef *)GPIOI_BASE,
													(volatile GPIO_TypeDef *)GPIOJ_BASE,
													(volatile GPIO_TypeDef *)GPIOK_BASE};








void Gpio__Initialize(void)
{

	//Initialize Gpios clock
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
}

void Gpio__PinConfig(GPIO_PORT_TYPE port,GPIO_PIN_MODE_TYPE pin_mode, uint8 pin, GPIO_PIN_OUTPUT_SPEED_TYPE speed)
{
  volatile GPIO_TypeDef * port_ptr;

  port_ptr = (volatile GPIO_TypeDef *) GPIO_PORT_LIST[port];
// todo: validate pin
  switch(pin_mode)
  {
  case OUTPUT_PUSH_PULL:
	  port_ptr->MODER  |= (1 << (2*pin)); //Pin Direction: General purpose output mode
	  port_ptr->OTYPER |= (0 << pin);     //Set Output mode
	  port_ptr->PUPDR  |= (GPIO_NOPULL << (2*pin)); //Pull up mode: no pull
	  break;
  case  OUTPUT_OPEN_DRAIN:
	  //todo
	  break;
  case INPUT_PULL_DOWN:
	  port_ptr->MODER  |= (0 << (2*pin)); //Pin Direction: Input mode (reset state)
	  port_ptr->PUPDR  |= (2 << (2*pin)); //Pull up mode: pull down
	  break;
  case INPUT_PULL_UP:
	  //todo
	  break;
  case INPUT_ANALOG:
	  //todo
  case AF_PUSH_PULL:
	  port_ptr->MODER  |= (2 << (2*pin)); //Pin Direction: General purpose output mode
	  port_ptr->OTYPER |= (0 << pin);     //Set Output mode
	  port_ptr->PUPDR  |= (GPIO_NOPULL << (2*pin)); //Pull up mode: no pull
	  //todo
	  break;
  case AF_OPEN_DRAIN:
	  //todo
	  break;
  default:
	  break;
  }

 //Set pin speed
  port_ptr->OSPEEDR |= (speed << (2*pin));
}
void Gpio__PinWrite(GPIO_PORT_TYPE port,uint8 pin,GPIO_PIN_STATE pin_state)
{
	volatile GPIO_TypeDef * port_ptr;
	uint8 reg_shift = pin;

	port_ptr = (volatile GPIO_TypeDef *) GPIO_PORT_LIST[port];
    //todo: validate pin

	// shift 16 to reset corresponding ODRx bit
	if (pin_state != GPIO_PIN_SET)
	{
		reg_shift += 16;
	}

	port_ptr->BSRR |= (GPIO_PIN_SET << reg_shift);

}
GPIO_PIN_STATE Gpio__PinRead(GPIO_PORT_TYPE port,uint8 pin)
{
	GPIO_PIN_STATE pin_state;
	pin_state = GPIO_PIN_RESET;

	volatile GPIO_TypeDef * port_ptr;
	port_ptr = (volatile GPIO_TypeDef *) GPIO_PORT_LIST[port];

	// todo: validate pin
	pin_state = ((port_ptr->IDR) & (1 << pin)) >> pin;

	return(pin_state);
}

