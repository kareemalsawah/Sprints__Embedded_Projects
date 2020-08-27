#include "../../types.h"
#include "../../MCAL/DIO/DIO.h"

#ifndef LED_H_
#define LED_H_

// LED variables
uint8_t LED_status; // 0 if off, 1 if on
uint8_t LED_port; // 'A', 'B', 'C', or 'D'
uint8_t LED_pin; // integer from 0 to 7 inclusive

/*
Description: Initialize port and pin for the led

Args:
	port (uint8_t): the port to use for the led, one of {'A', 'B', 'C', 'D'}
	pin  (uint8_t): the pin to use for the led, should be between 0 and 7 inclusive

Returns:
	None
*/
void LED_init(uint8_t port, uint8_t pin);

/*
Description: Turns the led off

Args:
	None

Returns:
	None
*/
void LED_off();

/*
Description: Turns the led on

Args:
	None

Returns:
	None
*/
void LED_on();

/*
Description: Toggles the led

Args:
	None

Returns:
	None
*/
void LED_toggle();

/*
Description: Returns the led status

Args:
	None

Returns:
	uint8_t: 0 if led is currently off, 1 if it is currently on
*/
uint8_t get_LED_status();

#endif