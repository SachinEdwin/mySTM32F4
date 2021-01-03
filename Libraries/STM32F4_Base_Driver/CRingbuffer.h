/*
 * CRingbuffer.h
 *
 *  Created on: 3 Jan 2021
 *      Author: Sachin
 */

#ifndef STM32F4_BASE_DRIVER_CRINGBUFFER_H_
#define STM32F4_BASE_DRIVER_CRINGBUFFER_H_

#include "tm_stm32f4_disco.h"

#define CB_TX_RX_BUFFER_SIZE 32

// The hidden definition of our circular buffer structure
typedef struct
{
    bool b_full;
	uint8_t pu8_buffer[CB_TX_RX_BUFFER_SIZE];
	uint16_t u16_head;
	uint16_t u16_tail;
	uint16_t u16_max; //of the buffer
}ST_circular_buf_t;

/* Initialize the circular buffer */
void TM_CircularBuffInit();
/// Returns 1 on success, 0 if buffer is full
uint8_t TM_CircularBufPut(ST_circular_buf_t *p_handle, uint8_t u8_data);
/// Retrieve a value from the buffer
/// Returns 1 on success, 0 if buffer is full
uint8_t TM_CircularBufGet(ST_circular_buf_t *p_handle, uint8_t *pu8_data);

/// Returns true if the buffer is full
bool TM_CircularBufFull(ST_circular_buf_t *p_handle);
void AdvancePointer(ST_circular_buf_t *p_handle);
void RetreatPointer(ST_circular_buf_t *p_handle);

/// Returns true if the buffer is empty
bool TM_CircularBufEmpty(ST_circular_buf_t *p_handle);
/// Reset the circular buffer to empty, head == tail
void TM_CircularBufReset(ST_circular_buf_t *p_handle);

/// Returns the maximum capacity of the buffer
uint16_t TM_CircularBufCapacity(ST_circular_buf_t p_handle);

/// Returns the current number of elements in the buffer
uint16_t TM_CircularBufSize(ST_circular_buf_t *p_handle);

/// Returns the current number of elements in the rx buffer
uint16_t TM_IsDataAvailable(ST_circular_buf_t *p_handle);

void TM_FlushRxBuffer(ST_circular_buf_t *p_handle);
void TM_FlushTxBuffer(ST_circular_buf_t *p_handle);

#endif /* STM32F4_BASE_DRIVER_CRINGBUFFER_H_ */
