/*
******************************************************************************
File:     main.cpp
Info:     Generated by Atollic TrueSTUDIO(R) 9.3.0   2020-08-08

The MIT License (MIT)
Copyright (c) 2019 STMicroelectronics

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

******************************************************************************
*/

/* Includes */
#include "stm32f4xx.h"
#include "tm_stm32f4_disco.h"
#include "tm_stm32f4_gpio.h"
#include "tm_stm32f4_delay.h"

/* Private macro */
/* Private variables */
/* Private function prototypes */
/* Private functions */



/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
	/* Initialize system */
	SystemInit();

	/* Initialize delay */
	TM_DELAY_Init();

	/* Reset counter to 0 */
	TM_DELAY_SetTime(0);

	/* Initialize leds on board */
	/* Set pins as output */
	TM_GPIO_Init(TM_DISCO_LED_PORT, LED_ALL, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High);

	/* Turn leds off */
	TM_DISCO_LedOff(LED_ALL);

	/* Set pin as input */
	TM_GPIO_Init(TM_DISCO_BUTTON_PORT, TM_DISCO_BUTTON_PIN, TM_GPIO_Mode_IN, TM_GPIO_OType_PP, TM_DISCO_BUTTON_PULL, TM_GPIO_Speed_Low);

  /* Infinite loop */
  while (1)
  {
	  /* If button pressed */
	 if (TM_DISCO_ButtonPressed()) {
		 /* Turn on leds */
		 TM_DISCO_LedOn(LED_RED | LED_GREEN);
	 } else {
		 /* Turn off leds */
		 TM_DISCO_LedOff(LED_RED | LED_GREEN);
	 }
  }
}




/*
 * Callback used by stm324xg_eval_i2c_ee.c.
 * Refer to stm324xg_eval_i2c_ee.h for more info.
 */
extern "C" uint32_t sEE_TIMEOUT_UserCallback(void)
{
  /* TODO, implement your code here */
  while (1)
  {
  }
}
