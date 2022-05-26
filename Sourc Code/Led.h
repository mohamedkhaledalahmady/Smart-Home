/*
 * Led.h
 *
 *  Created on: Sep 27, 2021
 *      Author: LENOVO
 */

#ifndef LED_H_
#define LED_H_

#include"GPIO.h"
#include "STD_Types.h"


#define REDLED      1
#define GREENLED    2
#define BLUELED     3
#define YELLOWLED   4

#define REDLED_PORT GPIO_A
#define REDLED_PIN  GPIO_PIN7

#define GREENLED_PORT GPIO_A
#define GREENLED_PIN  GPIO_PIN4

#define BLUELED_PORT GPIO_A
#define BLUELED_PIN  GPIO_PIN5

#define YELLOWLED_PORT GPIO_A
#define YELLOWLED_PIN  GPIO_PIN6


void ledOn(unit8 num);
void ledOff(unit8 num);
void closeAll();

#endif /* LED_H_ */
