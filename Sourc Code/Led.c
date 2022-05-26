#include <avr/io.h>
#include"GPIO.h"
#include "STD_Types.h"
#include "Utils.h"
#include"Led.h"
unit8 ledNum=4;
void ledOn(unit8 num){
  switch(num){
    case REDLED:
//    	GPIO_InitPin(REDLED_PORT, REDLED_PIN, GPIO_OUTPUT);
    	GPIO_WritePin(REDLED_PORT, REDLED_PIN, GPIO_HIGH);
        break;

    case GREENLED:
    	GPIO_WritePin(GREENLED_PORT,GREENLED_PIN,GPIO_HIGH);
    	break;

    case YELLOWLED:
    	GPIO_WritePin(YELLOWLED_PORT,YELLOWLED_PIN,GPIO_HIGH);
    	break;

    case BLUELED:
        	GPIO_WritePin(BLUELED_PORT,BLUELED_PIN,GPIO_HIGH);
  }
}


void ledOff(unit8 num){
  switch(num){
    case REDLED:
//    	GPIO_InitPin(REDLED_PORT, REDLED_PIN, GPIO_OUTPUT);
    	GPIO_WritePin(REDLED_PORT, REDLED_PIN, GPIO_LOW);

        break;

    case GREENLED:

    	GPIO_WritePin(GREENLED_PORT,GREENLED_PIN,GPIO_LOW);
    	break;

    case YELLOWLED:
    	GPIO_WritePin(YELLOWLED_PORT,YELLOWLED_PIN,GPIO_LOW);
    	break;

    case BLUELED:
        	GPIO_WritePin(BLUELED_PORT,BLUELED_PIN,GPIO_LOW);
  }
}


void closeAll(){
	for(unit8 i=ledNum;i>=1;i--){
	          ledOff(i);
	      }
}
