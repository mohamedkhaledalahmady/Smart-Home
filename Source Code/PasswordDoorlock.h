/*
 * PasswordDoorlock.h
 *
 *  Created on: Apr 17, 2022
 *      Author: LENOVO
 */

#ifndef PASSWORDDOORLOCK_H_
#define PASSWORDDOORLOCK_H_

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
#include "Servo.h"
#include<string.h>

#define PASSWORD  "4321"

#define PASSWORDDIGITS 4

#define MAXIMUMTRYS 3

#define NO_KEY 0



void password_page();
unit8 password_checking();
void change_password();

#endif /* PASSWORDDOORLOCK_H_ */
