/*
 * Servo.h
 *
 *  Created on: Apr 16, 2022
 *      Author: LENOVO
 */

#ifndef SERVO_H_
#define SERVO_H_

#include"GPIO.h"
#include "STD_Types.h"
#include "Utils.h"
#include"Led.h"
#include <avr/io.h>
#include <util/delay.h>
#include "Button.h"
#include "Clock.h"
#include "SEVERAL_TASKS.h"
#include "Seg.h"
#include "LCD.h"
#include<string.h>

#define servo_PORT  GPIO_C
#define servo_PIN   PIN0

#define time_90deg 1000

#define time_00deg 1498

void rotate90();
void rotate00();

#endif /* SERVO_H_ */
