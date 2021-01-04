/*
 * CI2C.cpp
 *
 *  Created on: 4 Jan 2021
 *      Author: Sachin
 */

#include <CI2C.h>

CI2C::CI2C()
{
	//TODO: check for the pins should not interfere with other interfaces
	TM_I2C_Init(I2C1, TM_I2C_PinsPack_1, 100000);
}

void CI2C::I2CRead(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg)
{
	TM_I2C_Read(I2C1, address, reg);
}

void CI2C::I2CWrite(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg, uint8_t data)
{
	TM_I2C_Write(I2C1, address, reg, data);
}

void CI2C::I2CReadMulti(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg, uint8_t* data, uint16_t count)
{
	TM_I2C_ReadMulti(I2C1, address, reg, &data[0], count);
}

void CI2C::I2CReadNoRegister(I2C_TypeDef* I2Cx, uint8_t address)
{
	TM_I2C_ReadNoRegister(I2C1, address);
}

void CI2C::I2CReadMultiNoRegister(I2C_TypeDef* I2Cx, uint8_t address, uint8_t* data, uint16_t count)
{
	TM_I2C_ReadMultiNoRegister(I2C1, address, &data[0], count);
}

void CI2C::I2CWriteMulti(I2C_TypeDef* I2Cx, uint8_t address, uint8_t reg, uint8_t* data, uint16_t count)
{
	TM_I2C_WriteMulti(I2C1, address, reg, &data[0], count);
}

void CI2C::I2CWriteNoRegister(I2C_TypeDef* I2Cx, uint8_t address, uint8_t data)
{
	TM_I2C_WriteNoRegister(I2C1, address, data);
}

void CI2C::I2CWriteMultiNoRegister(I2C_TypeDef* I2Cx, uint8_t address, uint8_t* data, uint16_t count)
{
	TM_I2C_WriteMultiNoRegister(I2C1, address, &data[0], count);
}

CI2C::~CI2C() {
	// TODO Auto-generated destructor stub
}

