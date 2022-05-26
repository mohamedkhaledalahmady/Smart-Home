/*
 * Button.h
 *
 *  Created on: Sep 29, 2021
 *      Author: LENOVO
 */

#ifndef BUTTON_H_
#define BUTTON_H_

//BUTTONS
#define BUTTON1   '1'
#define BUTTON2   '2'
#define BUTTON3   '3'
#define BUTTON4   'A'
#define BUTTON5   '4'
#define BUTTON6   '5'
#define BUTTON7   '6'
#define BUTTON8   'B'
#define BUTTON9   '7'
#define BUTTON10  '8'
#define BUTTON11  '9'
#define BUTTON12  'C'
#define BUTTON13  '*'
#define BUTTON14  '0'
#define BUTTON15  '#'
#define BUTTON16  'D'

//KEYPAD PORT
#define KEYPAD_PORT GPIO_B
#define COL2_PORT GPIO_B

//rows connections
#define ROW1_PIN GPIO_PIN0
#define ROW2_PIN GPIO_PIN1
#define ROW3_PIN GPIO_PIN2
#define ROW4_PIN GPIO_PIN3


//cols connections
#define COL1_PIN GPIO_PIN4
#define COL2_PIN GPIO_PIN5
#define COL3_PIN GPIO_PIN6
#define COL4_PIN GPIO_PIN7

unit8 Get_Button(unit8 button);

#endif /* BUTTON_H_ */
