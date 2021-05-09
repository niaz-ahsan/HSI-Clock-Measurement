/*
 * header.h
 *
 *  Created on: May 8, 2021
 *      Author: Niaz
 */

#ifndef HEADER_H_
#define HEADER_H_

#define RCC_BASE_ADDR 		(0x40023800)
#define RCC_CFGR_OFFSET 	(0x08)
#define RCC_CFGR_ADDR 		( (RCC_CFGR_t*)(RCC_BASE_ADDR + RCC_CFGR_OFFSET) )

#define RCC_AHB1ENR_OFFSET 	(0x30)
#define RCC_AHB1ENR_ADDR	( (RCC_AHB1ENR_t*)(RCC_BASE_ADDR + RCC_AHB1ENR_OFFSET) )

#define GPIOA_BASE_ADDR 	(0x40020000)
#define GPIOA_MODER_OFFSET	(0X00)
#define GPIOx_AFRH_OFFSET 	(0X24)
#define GPIOA_MODER_ADDR	( (GPIOx_MODER_t*)(GPIOA_BASE_ADDR + GPIOA_MODER_OFFSET) )
#define GPIOx_AFRH_ADDR		( (GPIOx_AFRH_t*)(GPIOA_BASE_ADDR + GPIOx_AFRH_OFFSET) )

#include <stdint.h>

typedef struct {
	uint32_t SW0 		:1;
	uint32_t SW1		:1;
	uint32_t SWS0		:1;
	uint32_t SWS1		:1;
	uint32_t HPRE		:4;
	uint32_t res1		:2;
	uint32_t PPRE1		:3;
	uint32_t PPRE2		:3;
	uint32_t RTCPRE		:5;
	uint32_t MCO1		:2;
	uint32_t I2SSCR		:1;
	uint32_t MCO1_PRE	:3;
	uint32_t MCO2_PRE	:3;
	uint32_t MCO2		:2;
} RCC_CFGR_t;

typedef struct {
	uint32_t gpio_a_en		:1;
	uint32_t gpio_b_en		:1;
	uint32_t gpio_c_en		:1;
	uint32_t gpio_d_en		:1;
	uint32_t gpio_e_en		:1;
	uint32_t gpio_f_en		:1;
	uint32_t gpio_g_en		:1;
	uint32_t gpio_h_en		:1;
	uint32_t gpio_i_en		:1;
	uint32_t gpio_j_en		:1;
	uint32_t gpio_k_en		:1;
	uint32_t res_1			:1;
	uint32_t crc_en			:1;
	uint32_t res_2			:3;
	uint32_t res_3			:2;
	uint32_t bkpsram_en		:1;
	uint32_t res_4			:1;
	uint32_t ccm_dat_aram_en:1;
	uint32_t dma1_en		:1;
	uint32_t dma2_en		:1;
	uint32_t dma2d_en		:1;
	uint32_t res_5			:1;
	uint32_t eth_mac_en		:1;
	uint32_t eth_mac_txe	:1;
	uint32_t eth_mac_rxe	:1;
	uint32_t eth_mac_ptp_en	:1;
	uint32_t otghs_en		:1;
	uint32_t otghs_ulpi_en	:1;
	uint32_t res_6			:1;
} RCC_AHB1ENR_t;

typedef struct {
	uint32_t pin_0		:2;
	uint32_t pin_1		:2;
	uint32_t pin_2		:2;
	uint32_t pin_3		:2;
	uint32_t pin_4		:2;
	uint32_t pin_5		:2;
	uint32_t pin_6		:2;
	uint32_t pin_7		:2;
	uint32_t pin_8		:2;
	uint32_t pin_9		:2;
	uint32_t pin_10		:2;
	uint32_t pin_11		:2;
	uint32_t pin_12		:2;
	uint32_t pin_13		:2;
	uint32_t pin_14		:2;
	uint32_t pin_15		:2;
} GPIOx_MODER_t;

typedef struct {
	uint32_t AFRH8 		:4;
	uint32_t AFRH9 		:4;
	uint32_t AFRH10 	:4;
	uint32_t AFRH11 	:4;
	uint32_t AFRH12 	:4;
	uint32_t AFRH13 	:4;
	uint32_t AFRH14 	:4;
	uint32_t AFRH15 	:4;
} GPIOx_AFRH_t;

#endif /* HEADER_H_ */
