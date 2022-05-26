#include"GPIO.h"
#include "STD_Types.h"
#include "Utils.h"
#include <avr/io.h>
#include <util/delay.h>
#include "Button.h"
#include "SEVERAL_TASKS.h"
#include "Seg.h"
#include "Clock.h"

sint8 minute=0;
sint8 hour=0;


void HoursDisplay(unit8 *hours){
	++*hours;
	if(*hours>23){
		*hours=0;
	}
	else if(*hours<0){
		*hours=23;
	}
	Seg_WriteSeq(*hours,0);
}

void MinutesDisplay(unit8 *minutes){
	++*minutes;
	if(*minutes>59){
		*minutes=0;
		//HoursDisplay(&hour);
		++hour;
		if(hour>23){
				hour=0;
			}
			else if(hour<0){
				hour=23;
			}

	}
	else if(*minutes<0){
		*minutes=59;
	}

	Seg_WriteSeq(*minutes,2);
	_delay_ms(0.2);
	Seg_WriteSeq(hour,0);
	_delay_ms(0.2);
}


void Clock(){
   //MinutesDisplay(&minute);
	++minute;
	if(minute>59){
		minute=0;
		++hour;
		if(hour>23){
			hour=0;
		}

	}

	Seg_WriteSeq(minute,2);
	_delay_ms(0.1);
	Seg_WriteSeq(hour,0);
	_delay_ms(0.1);

   _delay_ms(0.7);
}


void Clock_editMode(){





	Seg_WriteSeq(minute,2);
	_delay_ms(0.1);
	Seg_WriteSeq(hour,0);
	_delay_ms(0.1);

}

void Clock_IncreaseMinutes(){
	++minute;
	if(minute>59){
		minute=0;

	}
}

void Clock_DecreaseMinutes(){

	--minute;
    if(minute<0){
	    minute=59;
	}

}

void Clock_IncreaseHours(){
	++hour;
	if(hour>23){
	   hour=0;
	}

}

void Clock_DecreaseHours(){
	--hour;
	if(hour<0){
		hour=23;
	}
}





