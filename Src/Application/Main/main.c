/*
 * main.c
 *
 *  Created on: 1 Oct 2018
 *      Author: Yuri ALVARENGA
 */
#include "stm32f7xx_hal.h"
#include "main.h"
#include "Gpio.h"
#include "HBL.h"


void SystemClockConfig(void);
void SysTick_Handler(void);



int main(void)
{
	HAL_Init();
	SystemClockConfig();

	Gpio__Initialize();
	HBL__Initialize();


	while (1)
	{
		if (Gpio__PinRead(GPIO_PORTC, 13) == GPIO_PIN_SET)
		{
			//led_state = ON;
			HBL__SetDigitalOutput(DO_LED_BLUE, ON);
		}
		else
		{
			//led_state = OFF;
			HBL__SetDigitalOutput(DO_LED_BLUE, OFF);
		}
	}


	return(0);
}

/*
 * brief: Configure Oscillator, Clock Source and SysTick
 */
void SystemClockConfig()
{
	RCC_OscInitTypeDef osc_config;
	RCC_ClkInitTypeDef clk_config;
	uint8 flash_latency;

	flash_latency = 0;

	osc_config.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	osc_config.HSIState = RCC_HSI_ON;
	osc_config.HSICalibrationValue = 16;
	osc_config.PLL.PLLState = RCC_PLL_ON;
    osc_config.PLL.PLLSource = RCC_PLLSOURCE_HSI;

    // Clock frequency 120MHz config
    osc_config.PLL.PLLM = 16;
    osc_config.PLL.PLLN = 240;
    osc_config.PLL.PLLP = 2;
	osc_config.PLL.PLLQ = 2;
	osc_config.PLL.PLLR = 2;

	clk_config.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	clk_config.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	clk_config.AHBCLKDivider = RCC_SYSCLK_DIV1;
	clk_config.APB1CLKDivider = RCC_HCLK_DIV4;
	clk_config.APB2CLKDivider = RCC_HCLK_DIV2;

	flash_latency = FLASH_ACR_LATENCY_3WS;

 if(HAL_RCC_OscConfig(&osc_config) != HAL_OK)
 {
	 //Error_Handler();
 }

 if(HAL_RCC_ClockConfig(&clk_config, flash_latency) != HAL_OK)
 {
	// Error_Handler();
 }

 // Configure SysTick
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
}

void SysTick_Handler(void){


    HAL_IncTick();


    HAL_SYSTICK_IRQHandler();


}

