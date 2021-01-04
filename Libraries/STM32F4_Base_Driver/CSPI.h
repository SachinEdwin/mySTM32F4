/*
 * CSPI.h
 *
 *  Created on: 3 Jan 2021
 *      Author: Sachin
 */

#ifndef STM32F4_BASE_DRIVER_CSPI_H_
#define STM32F4_BASE_DRIVER_CSPI_H_

#include "tm_stm32f4_disco.h"

class CSPI
{
public:
	CSPI();
	uint8_t SPIReadWrite(SPI_TypeDef* SPIx, uint8_t data);
	uint16_t SPIReadWrite(SPI_TypeDef* SPIx, uint16_t data);
	void SPIReadWriteMutlti(SPI_TypeDef* SPIx, uint8_t* dataOut, uint8_t* dataIn, uint32_t count);
	void SPIWriteMutlti(SPI_TypeDef* SPIx, uint8_t* dataIn, uint32_t count);
	void SPIReadMutlti(SPI_TypeDef* SPIx, uint8_t* dataIn, uint8_t dummy, uint32_t count);
	void SPIRead(SPI_TypeDef* SPIx, uint16_t* dataOut, uint16_t dummy, uint32_t count);
	uint16_t SPIIsDataAvailable();
	void SPIDeInit();
	virtual ~CSPI();
};

#endif /* STM32F4_BASE_DRIVER_CSPI_H_ */
