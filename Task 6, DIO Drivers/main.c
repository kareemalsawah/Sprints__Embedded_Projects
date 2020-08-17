#include "MCAL/DIO/DIO.h"
#include "ECAL/button/button.h"
#include "ECAL/LED/LED.h"


int main(void)
{
	// Initializers
	uint8_t DDR_configs[4] = {0x01,0x00,0x00,0x00};
	DIO_init(DDR_configs);
	LED_init('A',0); // Put LED on Port A and pin 0
	button_init('C',0,LED_toggle); // Put button on Port C and pin 0, call LED_toggle() whenever the button is pressed and released

	// Main loop
    while (1) 
    {
		update_button_status();
    }
}

