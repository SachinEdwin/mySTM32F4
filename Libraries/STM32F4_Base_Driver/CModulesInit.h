/*
 * CModulesInit.h
 *
 *  Created on: 4 Oct 2020
 *      Author: Sachin
 */

#ifndef STM32F4_BASE_DRIVER_CMODULESINIT_H_
#define STM32F4_BASE_DRIVER_CMODULESINIT_H_

#include <functional>
#include <vector>
#include "tm_stm32f4_disco.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_gpio.h"
#include "CError.h"

typedef enum
{
	ModuleSystemInit = 1,
	ModuleLEDInit = 2,
	ModuleTimerInit = 3,
	// add all the modules here
	MaxModules

}EN_ModuleCallbackID_t;

/*
typedef enum
{
	STATE_SYSINIT,
	STATE_LEDINIT,
	STATE_TIMERINIT,
	NUM_STATES
}EN_StateType;
*/
// callback declaration
typedef std::function<En_Error()> cb_t;

typedef struct
{
	EN_ModuleCallbackID_t en_callbackID;
	std::function<En_Error()> cb;

}ST_ModuleInit;

//we implement a state machine in order to understand the process better

class CModulesInit
{
public:
	CModulesInit();
	void Run() const;
	virtual ~CModulesInit();
private:
	static En_Error SysInit();
	static En_Error LEDInit();
	static En_Error TimerInit();

	void Test();
	void RegisterModuleCallback(const cb_t &cb, const EN_ModuleCallbackID_t id);
	void DeRegisterModuleCallback();

	// add all the modules which needs to be initialized below
	ST_ModuleInit mst_moduleInit[MaxModules]  =
	{
		{EN_ModuleCallbackID_t::ModuleSystemInit, &CModulesInit::SysInit},
		{EN_ModuleCallbackID_t::ModuleLEDInit, &CModulesInit::LEDInit},
		{EN_ModuleCallbackID_t::ModuleTimerInit, &CModulesInit::TimerInit}
	};
	/// List of callback functions.
	std::vector<ST_ModuleInit> m_callbacks;

};
#endif /* STM32F4_BASE_DRIVER_CMODULESINIT_H_ */
