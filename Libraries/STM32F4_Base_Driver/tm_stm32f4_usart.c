/**	
 * |----------------------------------------------------------------------
 * | Copyright (C) Tilen Majerle, 2014
 * | 
 * | This program is free software: you can redistribute it and/or modify
 * | it under the terms of the GNU General Public License as published by
 * | the Free Software Foundation, either version 3 of the License, or
 * | any later version.
 * |  
 * | This program is distributed in the hope that it will be useful,
 * | but WITHOUT ANY WARRANTY; without even the implied warranty of
 * | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * | GNU General Public License for more details.
 * | 
 * | You should have received a copy of the GNU General Public License
 * | along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * |----------------------------------------------------------------------
 */
#include "tm_stm32f4_usart.h"

/**
 * @brief Internal USART struct
 */

ST_circular_buf_t st_rx_buffer = { { 0 }, 0, 0, 0, false };
ST_circular_buf_t st_tx_buffer = { { 0 }, 0, 0, 0, false };

ST_circular_buf_t *stp_rx_buffer;
ST_circular_buf_t *stp_tx_buffer;

/* Set variables for buffers */
#ifdef USE_USART1
#endif
#ifdef USE_USART2
uint8_t TM_USART2_Buffer[TM_USART2_BUFFER_SIZE];
#endif
#ifdef USE_USART3
uint8_t TM_USART3_Buffer[TM_USART3_BUFFER_SIZE];
#endif
#ifdef USE_UART4
uint8_t TM_UART4_Buffer[TM_UART4_BUFFER_SIZE];
#endif
#ifdef USE_UART5
uint8_t TM_UART5_Buffer[TM_UART5_BUFFER_SIZE];
#endif
#ifdef USE_USART6
uint8_t TM_USART6_Buffer[TM_USART6_BUFFER_SIZE];
#endif
#ifdef USE_UART7
uint8_t TM_UART7_Buffer[TM_UART7_BUFFER_SIZE];
#endif
#ifdef USE_UART8
uint8_t TM_UART8_Buffer[TM_UART8_BUFFER_SIZE];
#endif

#ifdef USE_USART1
#endif
#ifdef USE_USART2
TM_USART_t TM_USART2 = {TM_USART2_Buffer, TM_USART2_BUFFER_SIZE, 0, 0, 0, 0, USART_STRING_DELIMITER};
#endif
#ifdef USE_USART3
TM_USART_t TM_USART3 = {TM_USART3_Buffer, TM_USART3_BUFFER_SIZE, 0, 0, 0, 0, USART_STRING_DELIMITER};
#endif
#ifdef USE_UART4
TM_USART_t TM_UART4 = {TM_UART4_Buffer, TM_UART4_BUFFER_SIZE, 0, 0, 0, 0, USART_STRING_DELIMITER};
#endif
#ifdef USE_UART5
TM_USART_t TM_UART5 = {TM_UART5_Buffer, TM_UART5_BUFFER_SIZE, 0, 0, 0, 0, USART_STRING_DELIMITER};
#endif
#ifdef USE_USART6
TM_USART_t TM_USART6 = {TM_USART6_Buffer, TM_USART6_BUFFER_SIZE, 0, 0, 0, 0, USART_STRING_DELIMITER};
#endif
#ifdef USE_UART7
TM_USART_t TM_UART7 = {TM_UART7_Buffer, TM_UART7_BUFFER_SIZE, 0, 0, 0, 0, USART_STRING_DELIMITER};
#endif
#ifdef USE_UART8
TM_USART_t TM_UART8 = {TM_UART8_Buffer, TM_UART8_BUFFER_SIZE, 0, 0, 0, 0, USART_STRING_DELIMITER};
#endif

/* Private functions */
void TM_USART1_InitPins(TM_USART_PinsPack_t pinspack);

/* Private initializator function */
static void TM_USART_INT_Init(
	USART_TypeDef* USARTx,
	TM_USART_PinsPack_t pinspack,
	uint32_t baudrate,
	TM_USART_HardwareFlowControl_t FlowControl,
	uint32_t Mode,
	uint32_t Parity,
	uint32_t StopBits,
	uint32_t WordLength
);

void TM_USART_Init(USART_TypeDef* USARTx, TM_USART_PinsPack_t pinspack, uint32_t baudrate) {
#ifdef USE_USART1
	if (USARTx == USART1) {
		TM_USART_INT_Init(USART1, pinspack, baudrate, TM_USART1_HARDWARE_FLOW_CONTROL, TM_USART1_MODE, TM_USART1_PARITY, TM_USART1_STOP_BITS, TM_USART1_WORD_LENGTH);
	}
#endif
#ifdef USE_USART2
	if (USARTx == USART2) {
		TM_USART_INT_Init(USART2, pinspack, baudrate, TM_USART2_HARDWARE_FLOW_CONTROL, TM_USART2_MODE, TM_USART2_PARITY, TM_USART2_STOP_BITS, TM_USART2_WORD_LENGTH);
	}
#endif
#ifdef USE_USART3
	if (USARTx == USART3) {
		TM_USART_INT_Init(USART3, pinspack, baudrate, TM_USART3_HARDWARE_FLOW_CONTROL, TM_USART3_MODE, TM_USART3_PARITY, TM_USART3_STOP_BITS, TM_USART3_WORD_LENGTH);
	}
#endif
#ifdef USE_UART4
	if (USARTx == UART4) {
		TM_USART_INT_Init(UART4, pinspack, baudrate, TM_UART4_HARDWARE_FLOW_CONTROL, TM_UART4_MODE, TM_UART4_PARITY, TM_UART4_STOP_BITS, TM_UART4_WORD_LENGTH);
	}
#endif
#ifdef USE_UART5
	if (USARTx == UART5) {
		TM_USART_INT_Init(UART5, pinspack, baudrate, TM_UART5_HARDWARE_FLOW_CONTROL, TM_UART5_MODE, TM_UART5_PARITY, TM_UART5_STOP_BITS, TM_UART5_WORD_LENGTH);
	}
#endif
#ifdef USE_USART6
	if (USARTx == USART6) {
		TM_USART_INT_Init(USART6, pinspack, baudrate, TM_USART6_HARDWARE_FLOW_CONTROL, TM_USART6_MODE, TM_USART6_PARITY, TM_USART6_STOP_BITS, TM_USART6_WORD_LENGTH);
	}
#endif
#ifdef USE_UART7
	if (USARTx == UART7) {
		TM_USART_INT_Init(UART7, pinspack, baudrate, TM_UART7_HARDWARE_FLOW_CONTROL, TM_UART7_MODE, TM_UART7_PARITY, TM_UART7_STOP_BITS, TM_UART7_WORD_LENGTH);
	}
#endif
#ifdef USE_UART8
	if (USARTx == UART8) {
		TM_USART_INT_Init(UART8, pinspack, baudrate, TM_UART8_HARDWARE_FLOW_CONTROL, TM_UART8_MODE, TM_UART8_PARITY, TM_UART8_STOP_BITS, TM_UART8_WORD_LENGTH);
	}
#endif
}

void TM_USART_InitWithFlowControl(USART_TypeDef* USARTx, TM_USART_PinsPack_t pinspack, uint32_t baudrate, TM_USART_HardwareFlowControl_t FlowControl) {
#ifdef USE_USART1
	if (USARTx == USART1) {
		TM_USART_INT_Init(USART1, pinspack, baudrate, FlowControl, TM_USART1_MODE, TM_USART1_PARITY, TM_USART1_STOP_BITS, TM_USART1_WORD_LENGTH);
	}
#endif
#ifdef USE_USART2
	if (USARTx == USART2) {
		TM_USART_INT_Init(USART2, pinspack, baudrate, FlowControl, TM_USART2_MODE, TM_USART2_PARITY, TM_USART2_STOP_BITS, TM_USART2_WORD_LENGTH);
	}
#endif
#ifdef USE_USART3
	if (USARTx == USART3) {
		TM_USART_INT_Init(USART3, pinspack, baudrate, FlowControl, TM_USART3_MODE, TM_USART3_PARITY, TM_USART3_STOP_BITS, TM_USART3_WORD_LENGTH);
	}
#endif
#ifdef USE_UART4
	if (USARTx == UART4) {
		TM_USART_INT_Init(UART4, pinspack, baudrate, FlowControl, TM_UART4_MODE, TM_UART4_PARITY, TM_UART4_STOP_BITS, TM_UART4_WORD_LENGTH);
	}
#endif
#ifdef USE_UART5
	if (USARTx == UART5) {
		TM_USART_INT_Init(UART5, pinspack, baudrate, FlowControl, TM_UART5_MODE, TM_UART5_PARITY, TM_UART5_STOP_BITS, TM_UART5_WORD_LENGTH);
	}
#endif
#ifdef USE_USART6
	if (USARTx == USART6) {
		TM_USART_INT_Init(USART6, pinspack, baudrate, FlowControl, TM_USART6_MODE, TM_USART6_PARITY, TM_USART6_STOP_BITS, TM_USART6_WORD_LENGTH);
	}
#endif
#ifdef USE_UART7
	if (USARTx == UART7) {
		TM_USART_INT_Init(UART7, pinspack, baudrate, FlowControl, TM_UART7_MODE, TM_UART7_PARITY, TM_UART7_STOP_BITS, TM_UART7_WORD_LENGTH);
	}
#endif
#ifdef USE_UART8
	if (USARTx == UART8) {
		TM_USART_INT_Init(UART8, pinspack, baudrate, FlowControl, TM_UART8_MODE, TM_UART8_PARITY, TM_UART8_STOP_BITS, TM_UART8_WORD_LENGTH);
	}
#endif
}

uint8_t TM_USART_Gets(USART_TypeDef* USARTx, uint8_t *pu8_data, uint8_t u8_size)
{
	uint8_t data = 0;

	for (uint8_t i = 0; i < u8_size; i++)
	{
		TM_CircularBufGet(stp_rx_buffer, &data);
		*pu8_data++ = data;
	}

	/* Return number of characters in buffer */
	return u8_size;
}

void TM_USART_Send(USART_TypeDef* USARTx, uint8_t* pu8_data, uint8_t u8_count)
{
	for (uint8_t i = 0; i < u8_count; i++)
	{
		// we add data to Tx buffer
		TM_CircularBufPut(stp_tx_buffer, *pu8_data++);
	}

	/* Enable TX interrupt */
	USARTx->CR1 |= USART_CR1_TXEIE;
}


__weak void TM_USART_InitCustomPinsCallback(USART_TypeDef* USARTx, uint16_t AlternateFunction) {
	/* Custom user function. */
	/* In case user needs functionality for custom pins, this function should be declared outside this library */
}

uint8_t TM_USART_INT_GetSubPriority(USART_TypeDef* USARTx) {
	uint8_t u;
	
#ifdef USE_USART1
	if (USARTx == USART1) {
		u = 0;
	}
#endif
#ifdef USE_USART2
	if (USARTx == USART2) {
		u = 1;
	}
#endif
#ifdef USE_USART3
	if (USARTx == USART3) {
		u = 2;
	}
#endif
#ifdef USE_UART4
	if (USARTx == UART4) {
		u = 4;
	}
#endif
#ifdef USE_UART5
	if (USARTx == UART5) {
		u = 5;
	}
#endif
#ifdef USE_USART6
	if (USARTx == USART6) {
		u = 6;
	}
#endif
#ifdef USE_UART7
	if (USARTx == UART7) {
		u = 7;
	}
#endif
#ifdef USE_UART8
	if (USARTx == UART8) {
		u = 8;
	}
#endif
	
	return u;
}

#ifdef USE_USART1
void TM_USART1_InitPins(TM_USART_PinsPack_t pinspack)
{
	/* Init pins */
	if (pinspack == TM_USART_PinsPack_1)
	{
		TM_GPIO_InitAlternate(GPIOA, GPIO_Pin_9 | GPIO_Pin_10, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High, GPIO_AF_USART1);
	}
}
#endif

#ifdef USE_USART2
void TM_USART2_InitPins(TM_USART_PinsPack_t pinspack) {
	/* Init pins */
#if defined(GPIOA)
	if (pinspack == TM_USART_PinsPack_1) {
		TM_GPIO_InitAlternate(GPIOA, GPIO_Pin_2 | GPIO_Pin_3, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High, GPIO_AF_USART2);
	}
#endif
#if defined(GPIOD)
	if (pinspack == TM_USART_PinsPack_2) {
		TM_GPIO_InitAlternate(GPIOD, GPIO_Pin_5 | GPIO_Pin_6, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High, GPIO_AF_USART2);
	}
#endif
	if (pinspack == TM_USART_PinsPack_Custom) {
		/* Init custom pins, callback used */
		TM_USART_InitCustomPinsCallback(USART2, GPIO_AF_USART2);
	}
}
#endif

#ifdef USE_USART3
void TM_USART3_InitPins(TM_USART_PinsPack_t pinspack) {
	/* Init pins */
#if defined(GPIOB)
	if (pinspack == TM_USART_PinsPack_1) {
		TM_GPIO_InitAlternate(GPIOB, GPIO_Pin_10 | GPIO_Pin_11, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High, GPIO_AF_USART3);
	}
#endif
#if defined(GPIOC)
	if (pinspack == TM_USART_PinsPack_2) {
		TM_GPIO_InitAlternate(GPIOC, GPIO_Pin_10 | GPIO_Pin_11, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High, GPIO_AF_USART3);
	}
#endif
#if defined(GPIOD)
	if (pinspack == TM_USART_PinsPack_3) {
		TM_GPIO_InitAlternate(GPIOD, GPIO_Pin_8 | GPIO_Pin_9, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High, GPIO_AF_USART3);
	}
#endif
	if (pinspack == TM_USART_PinsPack_Custom) {
		/* Init custom pins, callback used */
		TM_USART_InitCustomPinsCallback(USART3, GPIO_AF_USART3);
	}
}
#endif

#ifdef USE_UART4
void TM_UART4_InitPins(TM_USART_PinsPack_t pinspack) {
	/* Init pins */
#if defined(GPIOA)
	if (pinspack == TM_USART_PinsPack_1) {
		TM_GPIO_InitAlternate(GPIOA, GPIO_Pin_0 | GPIO_Pin_1, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High, GPIO_AF_UART4);
	}
#endif
#if defined(GPIOC)
	if (pinspack == TM_USART_PinsPack_2) {
		TM_GPIO_InitAlternate(GPIOC, GPIO_Pin_10 | GPIO_Pin_11, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High, GPIO_AF_UART4);
	}
#endif
	if (pinspack == TM_USART_PinsPack_Custom) {
		/* Init custom pins, callback used */
		TM_USART_InitCustomPinsCallback(UART4, GPIO_AF_UART4);
	}
}
#endif

#ifdef USE_UART5
void TM_UART5_InitPins(TM_USART_PinsPack_t pinspack) {
	/* Init pins */
#if defined(GPIOC) && defined(GPIOD)
	if (pinspack == TM_USART_PinsPack_1) {
		TM_GPIO_InitAlternate(GPIOC, GPIO_Pin_12, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High, GPIO_AF_UART5);
		TM_GPIO_InitAlternate(GPIOD, GPIO_Pin_2, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High, GPIO_AF_UART5);
	}
#endif
	if (pinspack == TM_USART_PinsPack_Custom) {
		/* Init custom pins, callback used */
		TM_USART_InitCustomPinsCallback(UART5, GPIO_AF_UART5);
	}
}
#endif

#ifdef USE_USART6
void TM_USART6_InitPins(TM_USART_PinsPack_t pinspack) {
	/* Init pins */
#if defined(GPIOC)
	if (pinspack == TM_USART_PinsPack_1) {
		TM_GPIO_InitAlternate(GPIOC, GPIO_Pin_6 | GPIO_Pin_7, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High, GPIO_AF_USART6);
	}
#endif
#if defined(GPIOG)
	if (pinspack == TM_USART_PinsPack_2) {
		TM_GPIO_InitAlternate(GPIOG, GPIO_Pin_14 | GPIO_Pin_9, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High, GPIO_AF_USART6);
	}
#endif
	if (pinspack == TM_USART_PinsPack_Custom) {
		/* Init custom pins, callback used */
		TM_USART_InitCustomPinsCallback(USART6, GPIO_AF_USART6);
	}
}
#endif

#ifdef USE_UART7
void TM_UART7_InitPins(TM_USART_PinsPack_t pinspack) {
	/* Init pins */
#if defined(GPIOE)
	if (pinspack == TM_USART_PinsPack_1) {
		TM_GPIO_InitAlternate(GPIOE, GPIO_Pin_8 | GPIO_Pin_7, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High, GPIO_AF_UART7);
	}
#endif
#if defined(GPIOF)
	if (pinspack == TM_USART_PinsPack_2) {
		TM_GPIO_InitAlternate(GPIOF, GPIO_Pin_7 | GPIO_Pin_6, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High, GPIO_AF_UART7);
	}
#endif
	if (pinspack == TM_USART_PinsPack_Custom) {
		/* Init custom pins, callback used */
		TM_USART_InitCustomPinsCallback(UART7, GPIO_AF_UART7);
	}
}
#endif

#ifdef USE_UART8
void TM_UART8_InitPins(TM_USART_PinsPack_t pinspack) {
	/* Init pins */
#if defined(GPIOE)
	if (pinspack == TM_USART_PinsPack_1) {
		TM_GPIO_InitAlternate(GPIOE, GPIO_Pin_1 | GPIO_Pin_0, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_High, GPIO_AF_UART8);
	}
#endif
	if (pinspack == TM_USART_PinsPack_Custom) {
		/* Init custom pins, callback used */
		TM_USART_InitCustomPinsCallback(UART8, GPIO_AF_UART8);
	}
}
#endif

#ifdef USE_USART1
void USART1_IRQHandler(void) {

	// Check if interrupt was because data is received
	if (USART1->SR & USART_SR_RXNE)
	{
		TM_CircularBufPut(stp_rx_buffer, (uint8_t)USART1->DR);
	}
	else if(USART1->SR & USART_SR_TXE)
	{
		// reset the transmission interrupt
		USART1->CR1 &= ~(USART_CR1_TXEIE);

		uint8_t u8_data = 0;

		uint8_t size = (uint8_t)TM_CircularBufSize(stp_tx_buffer);

		for (uint8_t i = 0;  i < size; i++)
		{
			for (int loop = 0; loop < 2000; loop++)
			{
				// dummy loop with out this transmission is very quick
			}

			TM_CircularBufGet(stp_tx_buffer, &u8_data);

			USART1->DR = u8_data;
		}

		// flush Tx buffer, prepare for next transmission
		TM_FlushTxBuffer();
	}
	else
	{
		// TODO: do nothing for now
	}
}
#endif

static void TM_USART_INT_Init(
	USART_TypeDef* USARTx,
	TM_USART_PinsPack_t pinspack,
	uint32_t baudrate,
	TM_USART_HardwareFlowControl_t FlowControl,
	uint32_t Mode,
	uint32_t Parity,
	uint32_t StopBits,
	uint32_t WordLength
)
{
	USART_InitTypeDef USART_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;

	/* Set USART baudrate */
	USART_InitStruct.USART_BaudRate = baudrate;
	
	/*
	 * Initialize USARTx pins
	 * Set channel for USARTx NVIC
	 */
#ifdef USE_USART1
	if (USARTx == USART1) {
		/* Enable USART clock */
		RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
		
		/* Init pins */
		TM_USART1_InitPins(pinspack);
		
		/* Set IRQ channel */
		NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	}
#endif

	/* Deinit USART, force reset */
	USART_DeInit(USARTx);
	
	/* Fill NVIC settings */
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = USART_NVIC_PRIORITY;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = TM_USART_INT_GetSubPriority(USARTx);
	NVIC_Init(&NVIC_InitStruct);
	
	/* Fill default settings */
	USART_InitStruct.USART_HardwareFlowControl = FlowControl;
	USART_InitStruct.USART_Mode = Mode;
	USART_InitStruct.USART_Parity = Parity;
	USART_InitStruct.USART_StopBits = StopBits;
	USART_InitStruct.USART_WordLength = WordLength;
	
	/* Init */
	USART_Init(USARTx, &USART_InitStruct);
	
	/* Enable RX interrupt */
	USARTx->CR1 |= USART_CR1_RXNEIE;
	
	/* We are initialized now */
	//u->Initialized = 1;
	
	/* Enable USART peripheral */
	USARTx->CR1 |= USART_CR1_UE;
}

// TODO: should be made private
void TM_USARTCircularBuffInit()
{
	stp_rx_buffer = &st_rx_buffer;
	stp_tx_buffer = &st_tx_buffer;
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

uint16_t TM_IsDataAvailable()
{
	return TM_CircularBufSize(stp_rx_buffer);
}

void TM_FlushRxBuffer()
{
	stp_rx_buffer->u16_head = 0;
	stp_rx_buffer->u16_tail = 0;
	stp_rx_buffer->b_full = false;

	for (uint8_t reset = 0; reset < sizeof(stp_rx_buffer->pu8_buffer); reset++)
	{
		stp_rx_buffer->pu8_buffer[reset] = 0;
	}
}

void TM_FlushTxBuffer()
{
	stp_tx_buffer->u16_head = 0;
	stp_tx_buffer->u16_tail = 0;
	stp_tx_buffer->b_full = false;

	for (uint8_t reset = 0; reset < sizeof(stp_tx_buffer->pu8_buffer); reset++)
	{
		stp_tx_buffer->pu8_buffer[reset] = 0;
	}
}

