/*
 * CError.h
 *
 *  Created on: 3 Oct 2020
 *      Author: Sachin
 */

#ifndef STM32F4_BASE_DRIVER_CERROR_H_
#define STM32F4_BASE_DRIVER_CERROR_H_

#include "tm_stm32f4_disco.h"
#include "tm_stm32f4_delay.h"

typedef enum
{
  NoError = 0,
  Error = 1,
  ModuleInitialisationOK = 2,
  ModuleInitialisationFailure = 3
}En_Error;

class CError
{
public:
	CError();
	static void ErrorHandler();
	static void NoErrorHandler();
	virtual ~CError();
};

#endif /* STM32F4_BASE_DRIVER_CERROR_H_ */
