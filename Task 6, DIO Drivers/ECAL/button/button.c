#include "button.h"

void button_init(uint8_t port, uint8_t pin, void (*callback_pressed)()){
	// Initialize button variables
	button_port = port;
	button_pin = pin;
	button_pressed_callback = callback_pressed;

	button_status = 0; // Initialize the button as unpressed
}

void update_button_status(){
	// Get new button status
	uint8_t new_status;
	DIO_read(button_port,&new_status);

	if(new_status&(1<<button_pin) != 0){ // Button is down (pressed)
		button_status = 1;
	}else{ // Button is up (not pressed)
		if(button_status==1){ // Was previously pressed, click complete, trigger callback
			button_pressed_callback();
			button_status = 0;
		}
	}
}

uint8_t get_button_status(){
	return button_status;
}