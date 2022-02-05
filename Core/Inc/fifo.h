/**
 *	FIFO Lib
 * 	By Liyanboy74
 *	https://github.com/liyanboy74
 */
#ifndef _FIFO_H_
#define _FIFO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>

typedef enum
{
    FIFO_OK,
    FIFO_ERROR_EMPTY,
    FIFO_ERROR_BYFFER_OVF,
    FIFO_ERROR_BUFFER_OVR,
    FIFO_ERROR_MEMORY_ALLOCATION,
}FIFO_State_e;

FIFO_State_e    FIFO_Init(uint32_t Size);
FIFO_State_e    FIFO_Add(uint8_t Byte);
FIFO_State_e    FIFO_Read(uint8_t * Byte);
uint32_t        FIFO_GetLen(void);
uint32_t        FIFO_GetBufferSize(void);
void            FIFO_Reset(void);
void            FIFO_DeInit(void);

#ifdef __cplusplus
}
#endif

#endif
