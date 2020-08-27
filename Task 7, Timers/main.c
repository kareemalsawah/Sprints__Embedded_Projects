#include "MCAL/DIO/DIO.h"
#include "ECAL/LED/LED.h"
#include "MCAL/Timer/Timer.h"


int main(void)
{
	// Initializers
	uint8_t DDR_configs[4] = {0x01,0x00,0x00,0x00};
	DIO_init(DDR_configs);
	timer_init();
	LED_init('A',0); // Put LED on Port A and pin 0
	timer_led_toggle(300,500,LED_toggle);
}

