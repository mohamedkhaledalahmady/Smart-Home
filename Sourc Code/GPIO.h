/*
 * GPIO.h
 *Input:
 *Port: GPIO_D ,GPIO_C ,GPIO_B ,GPIO_A
 *pin:{0...7}
 *direction: GPIO_OUTPUT ,GPIO_INPUT
 * output: VOID
 *description:
 * log:
 *  Created on: Sep 25, 2021
 *      Author: LENOVO
 */

#ifndef GPIO_H_
#define GPIO_H_
#include "STD_Types.h"

//
#define GPIO_PIN0   0
#define GPIO_PIN1   1
#define GPIO_PIN2   2
#define GPIO_PIN3   3
#define GPIO_PIN4   4
#define GPIO_PIN5   5
#define GPIO_PIN6   6
#define GPIO_PIN7   7

#define GPIO_A   0
#define GPIO_B   1
#define GPIO_C   2
#define GPIO_D   3

#define GPIO_OUTPUT  1
#define GPIO_INPUT   0

#define GPIO_HIGH  1
#define GPIO_LOW   0


#define ERROR_Fail  0
#define SUCCESS     1

void GPIO_InitPin(unit8 port,unit8 pin,unit8 direction);
void GPIO_WritePin(unit8 port,unit8 pin,unit8 value);
unit8 GPIO_GetPin(unit8 port,unit8 pin);
void Control_Pull_Up(unit8 port,unit8 pin,unit8 value);
unit8 GPIO_Toggle(unit8 port,unit8 pin);
#endif /* GPIO_H_ */
