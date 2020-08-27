#include "../registers.h"
#include "../../types.h"

#ifndef DIO_H_
#define DIO_H_

/*
Description: Initialize DIO using DDR configurations for all ports and pins

Args:
	DDR_configs (uint8_t[4]): array of 4 configurations for DDR registers for all 4 ports

Returns:
	None
*/
void DIO_init(uint8_t DDR_configs[4]);

/*
Description: Read data from a port

Args:
	port (uint8_t): the port to read from, one of {'A', 'B', 'C', 'D'}
	data (uint8_t*): save the data read into this variable

Returns:
	None
*/
void DIO_read(uint8_t port, uint8_t* data);

/*
Description: Write data to a port

Args:
	port (uint8_t): the port to write to, one of {'A', 'B', 'C', 'D'}
	data (uint8_t): data to write to the port

Returns:
	None
*/
void DIO_write(uint8_t port, uint8_t data);



#endif