/**
 *  Defines for your entire project at one place
 * 
 *	@author 	Tilen Majerle
 *	@email		tilen@majerle.eu
 *	@website	http://stm32f4-discovery.com
 *	@version 	v1.0
 *	@ide		Keil uVision 5
 *	@license	GNU GPL v3
 *	
 * |----------------------------------------------------------------------
 * | Copyright (C) Tilen Majerle, 2014
 * | 
 * | This program is free software: you can redistribute it and/or modify
 * | it under the terms of the GNU General Public License as published by
 * | the Free Software Foundation, either version 3 of the License, or
 * | any later version.
 * |  
 * | This program is distributed in the hope that it will be useful,
 * | but WITHOUT ANY WARRANTY; without even the implied warranty of
 * | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * | GNU General Public License for more details.
 * | 
 * | You should have received a copy of the GNU General Public License
 * | along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * |----------------------------------------------------------------------
 */
#ifndef TM_DEFINES_H
#define TM_DEFINES_H

/* Put your global defines for all libraries here used in your project */
#define STM32F429_DISCOVERY
#define TM_DISCO_STM32F429_DISCOVERY
#define STM32F429_439xx

// Timer Configuration
#define TM_DELAY_TIM            TIM2
#define TM_DELAY_TIM_IRQ        TIM2_IRQn
#define TM_DELAY_TIM_IRQ_HANDLER    TIM2_IRQHandler

// //SPI Configuration
//#define USE_SPI5
////Options can be overwriten in defines.h file
//#define TM_SPI5_PRESCALER    SPI_BaudRatePrescaler_32
////Specify datasize
//#define TM_SPI5_DATASIZE     SPI_DataSize_8b
////Specify which bit is first
//#define TM_SPI5_FIRSTBIT     SPI_FirstBit_MSB
////Mode, master or slave
//#define TM_SPI5_MASTERSLAVE SPI_Mode_Master
////Specify mode of operation, clock polarity and clock phase
////Modes 0 to 3 are possible
//#define TM_SPI5_MODE        TM_SPI_Mode_0

/* Change custom SPI for LCD */
#define ILI9341_SPI                 SPI5 //OR something similar
#define ILI9341_SPI_PINS            TM_SPI_PinsPack_1

/* Change custom CS, DC and RESET pins */
/* CS pin */
#define ILI9341_CS_PORT                GPIOC
#define ILI9341_CS_PIN                GPIO_PIN_2
/* WRX or DC pin */
#define ILI9341_WRX_PORT            GPIOD
#define ILI9341_WRX_PIN                GPIO_PIN_13
/* RST pin */
#define ILI9341_RST_PORT            GPIOD
#define ILI9341_RST_PIN                GPIO_PIN_12

#endif
