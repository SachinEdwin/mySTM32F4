/*
 * CRingbuffer.c
 *
 *  Created on: 3 Jan 2021
 *      Author: Sachin
 */

#include "CRingbuffer.h"
#include "tm_stm32f4_usart.h"

// TODO: should be made private
void TM_CircularBuffInit()
{
	// we call different interfaces here for future
	TM_USARTCircularBuffInit();
}

uint8_t TM_CircularBufPut(ST_circular_buf_t *p_handle, uint8_t u8_data)
{
	uint8_t u8_success = 0;

	if(!TM_CircularBufFull(p_handle))
	{
		p_handle->pu8_buffer[p_handle->u16_head] = u8_data;
		AdvancePointer(p_handle);
		u8_success = 1;
	}

	return u8_success;
}


uint8_t TM_CircularBufGet(ST_circular_buf_t *p_handle, uint8_t *pu8_data)
{
	uint8_t u8_success = 0;

	if(!TM_CircularBufEmpty(p_handle))
	{
		*pu8_data = p_handle->pu8_buffer[p_handle->u16_tail];
		RetreatPointer(p_handle);
		u8_success = 1;
	}
	return u8_success;
}

bool TM_CircularBufFull(ST_circular_buf_t *p_handle)
{
	return p_handle->b_full;
}

void AdvancePointer(ST_circular_buf_t *p_handle)
{
	if(p_handle->b_full)
	{
		p_handle->u16_tail = (p_handle->u16_tail + 1) % p_handle->u16_max;
	}

	p_handle->u16_head = (p_handle->u16_head + 1) % p_handle->u16_max;
	p_handle->b_full = (p_handle->u16_head == p_handle->u16_tail);
}

void RetreatPointer(ST_circular_buf_t *p_handle)
{
	p_handle->b_full = false;
	p_handle->u16_tail = (p_handle->u16_tail + 1) % p_handle->u16_max;
}

bool TM_CircularBufEmpty(ST_circular_buf_t *p_handle)
{
	return (!p_handle->b_full && (p_handle->u16_head == p_handle->u16_tail));
}

void TM_CircularBufReset(ST_circular_buf_t *p_handle)
{
	p_handle->u16_head = 0;
	p_handle->u16_tail = 0;
	p_handle->b_full = false;
}


uint16_t TM_CircularBufCapacity(ST_circular_buf_t p_handle)
{
	return p_handle.u16_max;
}


uint16_t TM_CircularBufSize(ST_circular_buf_t *p_handle)
{
	uint16_t size = p_handle->u16_max;

	if(!p_handle->b_full)
	{
		if(p_handle->u16_head >= p_handle->u16_tail)
		{
			size = (p_handle->u16_head - p_handle->u16_tail);
		}
		else
		{
			size = (p_handle->u16_max + p_handle->u16_head - p_handle->u16_tail);
		}
	}

return size;
}

uint16_t TM_IsDataAvailable(ST_circular_buf_t *p_handle)
{
	return TM_CircularBufSize(p_handle);
}

void TM_FlushRxBuffer(ST_circular_buf_t *p_handle)
{
	p_handle->u16_head = 0;
	p_handle->u16_tail = 0;
	p_handle->b_full = false;

	for (uint8_t reset = 0; reset < sizeof(p_handle->pu8_buffer); reset++)
	{
		p_handle->pu8_buffer[reset] = 0;
	}
}

void TM_FlushTxBuffer(ST_circular_buf_t *p_handle)
{
	p_handle->u16_head = 0;
	p_handle->u16_tail = 0;
	p_handle->b_full = false;

	for (uint8_t reset = 0; reset < sizeof(p_handle->pu8_buffer); reset++)
	{
		p_handle->pu8_buffer[reset] = 0;
	}
}
