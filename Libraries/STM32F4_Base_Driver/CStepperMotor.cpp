/*
 * CStepperMotor.cpp
 *
 *  Created on: 6 Jan 2021
 *      Author: Sachin
 */

#include <CStepperMotor.h>
#include "tm_stm32f4_gpio.h"

CStepperMotor::CStepperMotor():mu32_stepsPerRev(4096), mu32_delayFactor(60000000)
{
	// TODO Auto-generated constructor stub
	TM_GPIO_Init(GPIOE, GPIO_PIN_10 |GPIO_PIN_11 |GPIO_PIN_12 |GPIO_PIN_13, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);
}

void CStepperMotor::StepperSetRPM(uint32_t u32_rpm)
{
	Delay(mu32_delayFactor/ mu32_stepsPerRev/ u32_rpm);
}

void CStepperMotor::StepperStepAngle (float f32_angle, uint8_t u8_direction, uint8_t u8_rpm)
{
	float f32_anglepersequence = 0.703125;  // 360 = 512 sequences
	uint32_t u32_numberofsequences = (uint32_t) (f32_angle/f32_anglepersequence);

	for (uint32_t seq = 0; seq < u32_numberofsequences; seq++)
	{
		if (u8_direction == 0)  // for clockwise
		{
			for (uint8_t u8_step = 7; u8_step >= 0; u8_step--)
			{
				StepperHalfDrive(u8_step);
				StepperSetRPM(u8_rpm);
			}
		}
		else if (u8_direction == 1)  // for anti-clockwise
		{
			for (uint8_t u8_step = 0; u8_step < 8; u8_step++)
			{
				StepperHalfDrive(u8_step);
				StepperSetRPM(u8_rpm);
			}
		}
		else
		{
			// for now do nothing
		}
	}
}

void CStepperMotor::StepperHalfDrive (uint32_t step)
{
	switch (step)
	{
		case 0:
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_10, 1);   // IN1
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_11, 0);   // IN2
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_12, 0);   // IN3
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_13, 0);   // IN4
			 break;

		case 1:
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_10, 1);   // IN1
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_11, 1);   // IN2
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_12, 0);   // IN3
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_13, 0);   // IN4
			  break;

		case 2:
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_10, 0);   // IN1
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_11, 1);   // IN2
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_12, 0);   // IN3
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_13, 0);   // IN4
			  break;

		case 3:
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_10, 0);   // IN1
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_11, 1);   // IN2
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_12, 1);   // IN3
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_13, 0);   // IN4
			  break;

		case 4:
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_10, 0);   // IN1
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_11, 0);   // IN2
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_12, 1);   // IN3
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_13, 0);   // IN4
			  break;

		case 5:
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_10, 0);   // IN1
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_11, 0);   // IN2
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_12, 1);   // IN3
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_13, 1);   // IN4
			  break;

		case 6:
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_10, 0);   // IN1
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_11, 0);   // IN2
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_12, 0);   // IN3
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_13, 1);   // IN4
			  break;

		case 7:
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_10, 1);   // IN1
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_11, 0);   // IN2
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_12, 0);   // IN3
			TM_GPIO_SetPinValue(GPIOE, GPIO_PIN_13, 1);   // IN4
			  break;

		default:
			// do nothing here
			break;
		}
}
CStepperMotor::~CStepperMotor() {
	// TODO Auto-generated destructor stub
}

