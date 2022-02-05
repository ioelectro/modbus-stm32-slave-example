/**
 *	FIFO Lib
 * 	By Liyanboy74
 *	https://github.com/liyanboy74
 */

#include <stdint.h>
#include <stdlib.h>

#include "fifo.h"

uint32_t FIFO_Buffer_Size=0;
uint32_t FIFO_RxIndex=0,FIFO_RxReadIndex=0;
uint8_t *FIFO_RxBuffer;

FIFO_State_e FIFO_Init(uint32_t Size)
{
	if(FIFO_Buffer_Size!=0)return FIFO_ERROR_BUFFER_OVR;
    FIFO_RxBuffer=(uint8_t*)malloc(Size*sizeof(uint8_t));
    if(FIFO_RxBuffer==NULL)return FIFO_ERROR_MEMORY_ALLOCATION;
    else FIFO_Buffer_Size=Size;
    return FIFO_OK;
}

void FIFO_DeInit(void)
{
	free(FIFO_RxBuffer);
	FIFO_Buffer_Size=0;
}

void FIFO_Reset(void)
{
	FIFO_RxIndex=0;
	FIFO_RxReadIndex=0;
}

uint32_t FIFO_GetBufferSize(void)
{
	return FIFO_Buffer_Size;
}

FIFO_State_e FIFO_Add(uint8_t Byte)
{
    FIFO_RxBuffer[FIFO_RxIndex]=Byte;
	FIFO_RxIndex++;
	if(FIFO_RxIndex>FIFO_Buffer_Size)FIFO_RxIndex=0;
	if(FIFO_RxIndex==FIFO_RxReadIndex)return FIFO_ERROR_BYFFER_OVF;
	return FIFO_OK;
}

uint32_t FIFO_GetLen(void)
{
	if(FIFO_RxIndex>=FIFO_RxReadIndex)return FIFO_RxIndex-FIFO_RxReadIndex;
	else return FIFO_Buffer_Size-(FIFO_RxReadIndex-FIFO_RxIndex)+1;
}

FIFO_State_e FIFO_Read(uint8_t * Byte)
{
	if(FIFO_GetLen())
	{
		*Byte=FIFO_RxBuffer[FIFO_RxReadIndex];
		FIFO_RxReadIndex++;
		if(FIFO_RxReadIndex>FIFO_Buffer_Size)FIFO_RxReadIndex=0;
		return FIFO_OK;
	}
	else return FIFO_ERROR_EMPTY;
}

