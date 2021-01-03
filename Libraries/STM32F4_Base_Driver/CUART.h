/*
 * CUART.h
 *
 *  Created on: 6 Nov 2020
 *      Author: Sachin
 */

#ifndef STM32F4_BASE_DRIVER_CUART_H_
#define STM32F4_BASE_DRIVER_CUART_H_

#include "tm_stm32f4_usart.h"
#include "CRingbuffer.h"

typedef enum
{
	BAUD9600 = 9600,
	BAUD115200 = 115200,

} en_Baudrate;

class CUART {
public:
	CUART();
	void UARTWrite(uint8_t *data, uint8_t size = 1);
	void UARTRead(uint8_t *pu8_data, uint8_t size);
	uint16_t UARTIsDataAvailable();
	void UARTDeInit();
	virtual ~CUART();
};

#endif /* STM32F4_BASE_DRIVER_CUART_H_ */
