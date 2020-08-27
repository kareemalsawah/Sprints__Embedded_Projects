#include "../types.h"

#ifndef REGISTERS_H_
#define REGISTERS_H_

#define PA_DATA *((volatile uint8_t*)0x3B)
#define PA_DDR *((volatile uint8_t*)0x3A)
#define PA_IN *((volatile uint8_t*)0x39)

#define PB_DATA *((volatile uint8_t*)0x38)
#define PB_DDR *((volatile uint8_t*)0x37)
#define PB_IN *((volatile uint8_t*)0x36)

#define PC_DATA *((volatile uint8_t*)0x35)
#define PC_DDR *((volatile uint8_t*)0x34)
#define PC_IN *((volatile uint8_t*)0x33)

#define PD_DATA *((volatile uint8_t*)0x32)
#define PD_DDR *((volatile uint8_t*)0x31)
#define PD_IN *((volatile uint8_t*)0x30)

#define TCCR0 *((volatile uint8_t*)0x53)
#define TCNT0 *((volatile uint8_t*)0x52)
#endif