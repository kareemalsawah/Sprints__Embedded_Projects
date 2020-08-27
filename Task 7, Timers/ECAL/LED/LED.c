#include "LED.h"

void LED_init(uint8_t port, uint8_t pin){
	LED_port = port;
	LED_pin = pin;
	LED_off(); // LED is initialized as off
}

void LED_off(){
	DIO_write(LED_port,0);
	LED_status = 0;
}

void LED_on(){
	DIO_write(LED_port,1<<LED_pin);
	LED_status = 1;
}

void LED_toggle(){
	if(LED_status){
		LED_off();
	}else{
		LED_on();
	}
}

uint8_t get_LED_status(){
	return LED_status;
}