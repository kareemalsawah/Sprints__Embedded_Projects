#include "../../types.h"
#include "../../MCAL/DIO/DIO.h"

#ifndef BUTTON_H_
#define BUTTON_H_

// Button variables
uint8_t button_port; // 'A', 'B', 'C', or 'D'
uint8_t button_pin; // integer from 0 to 7 inclusive
uint8_t button_status; // 0 if button is not currently pressed, 1 if it is currently pressed
void (*button_pressed_callback)(void); // Callback function to use when button is pressed and released

/*
Description: Initialize button port, pin, and pressed callback function

Args:
	port (uint8_t): the port to use for the button, one of {'A', 'B', 'C', 'D'}
	pin  (uint8_t): the pin to use for the button, should be between 0 and 7 inclusive
	callback_pressed (ptr to fnc): function to call when button is pressed and released

Returns:
	None
*/
void button_init(uint8_t port, uint8_t pin, void (*callback_pressed)(void));

/*
Description: Update the current button status and call callback function if needed

Args:
	None

Returns:
	None
*/
void update_button_status();

/*
Description: returns current button status

Args:
	None

Returns:
	uint8_t: 0 if button is not currently pressed, 1 if it is currently pressed
*/
uint8_t get_button_status();


#endif