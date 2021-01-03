/*
 * CUART.cpp
 *
 *  Created on: 6 Nov 2020
 *      Author: Sachin
 */

#include <CUART.h>

CUART::CUART()
{
	TM_USART_Init(USART1, TM_USART_PinsPack_1, en_Baudrate::BAUD115200);
	TM_CircularBuffInit();
}

void CUART::UARTDeInit()
{
	USART_DeInit(USART1);
}

void CUART::UARTWrite(uint8_t *pu_data, uint8_t size)
{
	TM_USART_Send(USART1, &pu_data[0], size);
}

void CUART::UARTRead(uint8_t *pu8_data, uint8_t size)
{
	TM_USART_Gets(USART1, &pu8_data[0], size);
}

uint16_t CUART::UARTIsDataAvailable()
{
	return TM_USART_DataAvailable();
}


CUART::~CUART()
{

}

