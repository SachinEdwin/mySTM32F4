/*
 * CError.cpp
 *
 *  Created on: 3 Oct 2020
 *      Author: Sachin
 */

#include <CError.h>

CError::CError() {
	// TODO Auto-generated constructor stub

}

void CError::ErrorHandler()
{
	while(1)
	{
		if (TM_DELAY_Time() >= 500)
		{
			TM_DELAY_SetTime(0);
			TM_DISCO_LedToggle(LED_RED);
		}
	}
}

void CError::NoErrorHandler()
{
	while(1)
	{
		if (TM_DELAY_Time() >= 500)
		{
			TM_DELAY_SetTime(0);
			TM_DISCO_LedToggle(LED_GREEN);
		}
	}
}

CError::~CError() {
	// TODO Auto-generated destructor stub
}

