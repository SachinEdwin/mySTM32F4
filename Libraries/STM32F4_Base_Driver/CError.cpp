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
	for (uint8_t loop = 0;  loop < MAX_LOOP; loop++)
	{
		TM_DISCO_LedToggle(LED_GREEN);
		Delayms(100);
		TM_DISCO_LedOff(LED_GREEN);
		Delayms(100);
	}
}

CError::~CError() {
	// TODO Auto-generated destructor stub
}

