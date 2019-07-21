/*I2C.c
 Created on: 8 Dec 2018
     Author: Yuri ALVARENGA*/

//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------


//-------------------------------------- Include Files ----------------------------------------------------------------
#include "I2C.h"

//-------------------------------------- PUBLIC (Variables) -----------------------------------------------------------

//-------------------------------------- PRIVATE (Variables, Constants & Defines) -------------------------------------

//-------------------------------------- PRIVATE (Function Prototypes) ------------------------------------------------

//=====================================================================================================================
//-------------------------------------- Public Functions -------------------------------------------------------------
//=====================================================================================================================
void I2C__Initialize(void)
{
	I2C_HandleTypeDef i2c_handle;
	BOOL_TYPE         clk_stretching;

	clk_stretching = TRUE;
  // Init clock
  // Set i2c addressing mode
  // Enable Ack
  // Handle Clock streching
	if (clk_stretching != FALSE)
	{
		i2c_handle.Instance->CR1 &= ~I2C_CR1_NOSTRETCH;
	}
	else
	{
		i2c_handle.Instance->CR1 |= I2C_CR1_NOSTRETCH;
	}
  // config own address

  // enable peripheral
	i2c_handle.Instance->CR1 |= I2C_CR1_PE;
}
//---------------------------------------------------------------------------------------------------------------------
