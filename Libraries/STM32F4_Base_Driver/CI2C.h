/*
 * CI2C.h
 *
 *  Created on: 4 Jan 2021
 *      Author: Sachin
 */

#ifndef STM32F4_BASE_DRIVER_CI2C_H_
#define STM32F4_BASE_DRIVER_CI2C_H_

#include "tm_stm32f4_disco.h"
#include "tm_stm32f4_i2c.h"
class CI2C
{
public:
	CI2C();
	void I2CRead(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg);
	void I2CReadNoRegister(I2C_TypeDef* I2Cx, uint8_t address);
	void I2CReadMultiNoRegister(I2C_TypeDef* I2Cx, uint8_t address, uint8_t* data, uint16_t count);
	void I2CReadMulti(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg, uint8_t* data, uint16_t count);
	void I2CWrite(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg, uint8_t data);
	void I2CWriteMulti(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg, uint8_t* data, uint16_t count);
	void I2CWriteNoRegister(I2C_TypeDef* I2Cx, uint8_t address, uint8_t data);
	void I2CWriteMultiNoRegister(I2C_TypeDef* I2Cx, uint8_t address, uint8_t* data, uint16_t count);
	virtual ~CI2C();
};

#endif /* STM32F4_BASE_DRIVER_CI2C_H_ */
