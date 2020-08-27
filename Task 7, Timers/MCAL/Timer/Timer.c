#include "Timer.h"


void timer_init(){
	TCCR0 = 0x00;
}

void timer_led_toggle(int time_off, int time_on, void (*callback_led)()){
	int org_1 = time_off;
	TCCR0 = 0x05;
	TCNT0 = 0x00;
	while(1){
		if(TCNT0==0xff || time_off-TCNT0==0){
			if(time_off-TCNT0>0){
				TCNT0 = 0x00;
				time_off -= 256;
			}else{
				callback_led();
				break;
			}
		}
	}
	timer_led_toggle(time_on,org_1,callback_led);
}