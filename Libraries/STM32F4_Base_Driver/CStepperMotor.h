/*
 * CStepperMotor.h
 *
 *  Created on: 6 Jan 2021
 *      Author: Sachin
 */

#ifndef STM32F4_BASE_DRIVER_CSTEPPERMOTOR_H_
#define STM32F4_BASE_DRIVER_CSTEPPERMOTOR_H_

#include "tm_stm32f4_disco.h"
#include "CModulesInit.h"

class CStepperMotor {
public:
	CStepperMotor();
	void StepperSetRPM (uint32_t u32_rpm);
	void StepperHalfDrive (uint32_t step);
	void StepperStepAngle (float f32_angle, uint8_t u8_direction, uint8_t u8_rpm);
	virtual ~CStepperMotor();

private:
	uint32_t mu32_stepsPerRev;
	uint32_t mu32_delayFactor;


};

#endif /* STM32F4_BASE_DRIVER_CSTEPPERMOTOR_H_ */
