#include "../registers.h"
#include "../../types.h"


#ifndef TIMER_H_
#define TIMER_H_

/*
Description: Initialize timer 0 with normal mode and not started (prescaler = 000)

Args:
	None

Returns:
	None
*/
void timer_init();

/*
Description: Toggle LED with time_1 off and time_2 on in ms

Args:
	time_1: time of the LED as off
	time_2: time of the LED as on
	callback_led: function to toggle LED

Returns:
	None
*/
void timer_led_toggle(int time_off, int time_on, void (*callback_led)());



#endif