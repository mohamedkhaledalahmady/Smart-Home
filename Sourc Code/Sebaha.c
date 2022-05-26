#include"GPIO.h"
#include "STD_Types.h"
#include "Utils.h"
#include"Led.h"
#include <avr/io.h>
#include <util/delay.h>
#include "Button.h"
#include "SEVERAL_TASKS.h"
#include "Seg.h"
#include "Sebha.h"
unit16 i=0;

void Tasbeh(){

    ++i;
    if(i>99){
    	i=0;
    }
}

void Tasbeh_Decrease(){
	--i;
	if(i<0){
		i=0;
	}
}
