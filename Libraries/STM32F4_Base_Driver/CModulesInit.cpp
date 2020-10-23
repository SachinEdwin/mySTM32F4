/*
 * CModulesInit.cpp
 *
 *  Created on: 4 Oct 2020
 *      Author: Sachin
 */

#include <CModulesInit.h>

CModulesInit::CModulesInit():m_callbacks()
{
	for (const auto &module : mst_moduleInit)
	{
		cb_t st_module = module.cb;
		// we register all the modules in the constructor
		RegisterModuleCallback(st_module , module.en_callbackID);
	}
}

void CModulesInit::RegisterModuleCallback(const cb_t &fp_CB, const EN_ModuleCallbackID_t en_ID)
{
	if((en_ID != 0) && fp_CB != 0)
	{
		// add callback to end of callback list
		m_callbacks.push_back( {en_ID,fp_CB});
	}

}

void CModulesInit::DeRegisterModuleCallback()
{
	if(m_callbacks.size()!= 0)
	{
		// remove callback to end of callback list
		this->m_callbacks.pop_back();
	}
}

/// Call all the registered callback.
void CModulesInit::Run() const
{
	En_Error en_errorCode = ModuleInitialisationFailure;
	// iterate through callback list and call each one
	for (const auto &cb_module : m_callbacks)
	{
		en_errorCode = cb_module.cb();

		if(ModuleInitialisationOK != en_errorCode)
		{
			TM_DELAY_SetTime(0);
			CError::ErrorHandler();
		}
	}

	if(ModuleInitialisationOK == en_errorCode)
	{
		CError::NoErrorHandler();
	}
}

En_Error CModulesInit::SysInit()
{
	// Initialize Clock, PLL etc.
	SystemInit();
	return ModuleInitialisationOK;
}

En_Error CModulesInit::LEDInit()
{
	/* Set pins as output */
	TM_GPIO_Init(TM_DISCO_LED_PORT, LED_ALL, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High);
	/* Turn leds off */
	TM_DISCO_LedOff(LED_ALL);

	return ModuleInitialisationOK;
}

En_Error CModulesInit::TimerInit()
{
	//Initialize delay
	TM_DELAY_Init();

	//Reset counter to 0
	TM_DELAY_SetTime(0);
	return ModuleInitialisationOK;
}

CModulesInit::~CModulesInit()
{
	// TODO Auto-generated destructor stub
}

