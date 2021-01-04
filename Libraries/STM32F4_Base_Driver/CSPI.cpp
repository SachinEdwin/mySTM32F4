/*
 * CSPI.cpp
 *
 *  Created on: 3 Jan 2021
 *      Author: Sachin
 */

#include <CSPI.h>
#include "tm_stm32f4_spi.h"

CSPI::CSPI()
{
	TM_SPI_Init(SPI1, TM_SPI_PinsPack_2);
	//TODO: ringbuffer implementation
}

void CSPI::SPIDeInit()
{
	// we are using SPI1
	TM_SPI_DeInit(SPI1);
}

uint8_t CSPI::SPIReadWrite(SPI_TypeDef* SPIx, uint8_t data)
{
	return TM_SPI_Send(SPI1, data);
}

uint16_t CSPI::SPIReadWrite(SPI_TypeDef* SPIx, uint16_t data)
{
	return TM_SPI_Send16(SPI1, data);
}

void CSPI::SPIReadWriteMutlti(SPI_TypeDef* SPIx, uint8_t* dataOut, uint8_t* dataIn, uint32_t count)
{
	TM_SPI_SendMulti(SPI1, &dataOut[0], &dataIn[0], count);
}

void CSPI::SPIWriteMutlti(SPI_TypeDef* SPIx, uint8_t* dataIn, uint32_t count)
{
	TM_SPI_WriteMulti(SPI1, &dataIn[0], count);
}

void CSPI::SPIReadMutlti(SPI_TypeDef* SPIx, uint8_t* dataOut, uint8_t dummy, uint32_t count)
{
	TM_SPI_ReadMulti(SPI1, &dataOut[0], dummy, count);
}

void CSPI::SPIRead(SPI_TypeDef* SPIx, uint16_t* dataOut, uint16_t dummy, uint32_t count)
{
	TM_SPI_ReadMulti16(SPI1, &dataOut[0], dummy, count);
}

CSPI::~CSPI()
{
	// TODO Auto-generated destructor stub
}

