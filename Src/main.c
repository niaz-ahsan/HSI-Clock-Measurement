/**
 ******************************************************************************
 Problem Statement: Measure HSI clock frequency by a logic analyzer
 ******************************************************************************
 */

#include "header.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	RCC_CFGR_t volatile *const clock_config 		= RCC_CFGR_ADDR;
	RCC_AHB1ENR_t volatile *const AHB1_en		 	= RCC_AHB1ENR_ADDR;
	GPIOx_MODER_t volatile *const gpio_mode			= GPIOA_MODER_ADDR;
	GPIOx_AFRH_t volatile *const alt_function		= GPIOx_AFRH_ADDR;

	// RCC_CFGR 21, 22 bit clearing for enabling MCO1 for SYSCLK
	clock_config->MCO1 = 0;

	// RCC_CFGR setting MCO1 PRE to divide 16MHz with 4
	clock_config->MCO1_PRE = 6;

	/*
	 * MCO1 is read by PA8 in Alternate function mode
	 * GPIOx_MODER should be set for Alt func mode
	 * GPIOx_AFRH pin 8 should be set in AF0 mode
	 */

	// enabling clock for AHB1 to turn GPIO(A) on
	AHB1_en->gpio_a_en = 1;

	// GPIOx_MODER configuration
	gpio_mode->pin_8 = 2;

	// GPIOx_AFRH configuration
	alt_function->AFRH8 = 0;

	for(;;);
}
