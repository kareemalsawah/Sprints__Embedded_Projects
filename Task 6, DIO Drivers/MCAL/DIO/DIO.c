#include "DIO.h"

void DIO_init(uint8_t DDR_configs[4]){
	// Default configurations for DDR registers for all 4 ports
	PA_DDR = DDR_configs[0];
	PB_DDR = DDR_configs[1];
	PC_DDR = DDR_configs[2];
	PD_DDR = DDR_configs[3];
}

void DIO_read(uint8_t port, uint8_t* data){
	switch(port){
		case 'A':
			*data = PA_IN;
		break;
		case 'B':
			*data = PB_IN;
		break;
		case 'C':
			*data = PC_IN;
		break;
		case 'D':
			*data = PD_IN;
		break;
	}
}

void DIO_write(uint8_t port, uint8_t data){
	switch(port){
		case 'A':
			PA_DATA = data;
		break;
		case 'B':
			PB_DATA = data;
		break;
		case 'C':
			PC_DATA = data;
		break;
		case 'D':
			PD_DATA = data;
		break;
	}
}