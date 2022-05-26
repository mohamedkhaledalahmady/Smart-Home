/*
 * GPIO.C
 *
 *  Created on: Sep 25, 2021
 *      Author: LENOVO
 */


#include <avr/io.h>
#include"GPIO.h"
#include "STD_Types.h"
#include "Utils.h"



void GPIO_InitPin(unit8 port,unit8 pin,unit8 direction){

		switch(port){
		case GPIO_A:
			if(direction==GPIO_OUTPUT){
				SET_BIT(DDRA,pin);
			}
			else{
				CLEAR_BIT(DDRA,pin);
			}
			break;
		case GPIO_B:
			if(direction==GPIO_OUTPUT){
				SET_BIT(DDRB,pin);
			}
			else{
				CLEAR_BIT(DDRB,pin);
			}
			break;
		case GPIO_C:
			if(direction==GPIO_OUTPUT){
				SET_BIT(DDRC,pin);
			}
			else{
				CLEAR_BIT(DDRC,pin);
			}
			break;
		case GPIO_D:
			if(direction==GPIO_OUTPUT){
				SET_BIT(DDRD,pin);
			}
			else{
				CLEAR_BIT(DDRD,pin);
			}
			break;
		}


}

void GPIO_WritePin(unit8 port,unit8 pin,unit8 value){

		switch(port)
		{
		case GPIO_A:
			if(value==GPIO_HIGH){
				SET_BIT(PORTA,pin);
			}
			else{
				CLEAR_BIT(PORTA,pin);
			}
			break;
		case GPIO_B:
			if(value==GPIO_HIGH){
				SET_BIT(PORTB,pin);
			}
			else{
				CLEAR_BIT(PORTB,pin);
			}
			break;
		case GPIO_C:
			if(value==GPIO_HIGH){
				SET_BIT(PORTC,pin);
			}
			else{
				CLEAR_BIT(PORTC,pin);
			}
			break;
		case GPIO_D:
			if(value==GPIO_HIGH){
				SET_BIT(PORTD,pin);
			}
			else{
				CLEAR_BIT(PORTD,pin);
			}
			break;
		}


}

void Control_Pull_Up(unit8 port,unit8 pin,unit8 value){

	switch(port){
	case GPIO_A:

		if(value==GPIO_HIGH)
		SET_BIT(PORTA,pin);
		else
		CLEAR_BIT(PORTA,pin);

		break;
	case GPIO_B:
		    if(value==1)
			SET_BIT(PORTB,pin);
		    else
		    CLEAR_BIT(PORTB,pin);
			break;
	case GPIO_C:
		if(value==0)
		SET_BIT(PORTC,pin);
		else
			CLEAR_BIT(PORTC,pin);
			break;
	case GPIO_D:
		if(value==1)
		SET_BIT(PORTD,pin);
		else
		CLEAR_BIT(PORTD,pin);
	}

}

unit8 GPIO_GetPin(unit8 port,unit8 pin){
	unit8 ret_val=0;
	switch(port){

	case GPIO_A:
		ret_val=GET_BIT(PINA,pin);
		break;

	case GPIO_B:
		ret_val=GET_BIT(PINB,pin);
		break;

	case GPIO_C:
		ret_val=GET_BIT(PINC,pin);
		break;

	case GPIO_D:
		ret_val=GET_BIT(PIND,pin); ////////////////////////////
		break;

	}
	return ret_val;
}

unit8 GPIO_Toggle(unit8 port,unit8 pin)
{
	unit8 ret_val=0;
	switch(port)
	{
	case GPIO_A:
		ret_val=Toggle_BIT(PORTA,pin);
		break;

	case GPIO_B:
		ret_val=Toggle_BIT(PORTB,pin);
		break;

	case GPIO_C:
		ret_val=Toggle_BIT(PORTC,pin);
		break;

	case GPIO_D:
		ret_val=Toggle_BIT(PORTD,pin);
		break;
	}
	return ret_val;
}

