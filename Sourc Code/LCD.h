/*
 * LCD.h
 *
 *  Created on: Oct 7, 2021
 *      Author: LENOVO
 */

#ifndef LCD_H_
#define LCD_H_

#include"GPIO.h"
#include "STD_Types.h"
#include "Utils.h"
#include"Led.h"
//#include <avr/io.h>
#include <util/delay.h>
#include "Button.h"
#include "Clock.h"
#include "SEVERAL_TASKS.h"
#include "Seg.h"



#define LCD_PORT       GPIO_D
#define D7_PORT        GPIO_A

#define LCD_RS_PORT    GPIO_A
#define LCD_EN_PORT    GPIO_A
#define LCD_RW_PORT    GPIO_A

//#define LCD_RW_PIN   GPIO_PIN6
#define LCD_RS_PIN    GPIO_PIN6
#define LCD_EN_PIN    GPIO_PIN7

#define LCD_D4_PIN    GPIO_PIN3
#define LCD_D5_PIN    GPIO_PIN6
#define LCD_D6_PIN    GPIO_PIN7
#define LCD_D7_PIN    GPIO_PIN5
#define LCD_DATA     1
#define LCD_COMMAND  0



#define CLEAR       			0x01
#define Home 					0x02
#define BIT4_Mode   			0x28
#define DisplayON_CursorOFF  	0x0c
#define DisplayOFF_CursorON  	0x0a
#define DisplayON_CursorBlink  	0x0c
#define Cursor_home 			0x02
#define First_Line 				0x80


void lcd_Init();
void lcd_command(unit16 cmd);
void lcd_write_charcter(sint8 charcter);
void lcd_enable_active();
void lcd_write_string(char *str);
void lcd_setCursor(unit8 x, unit8 y);
void lcd_Clear();


#endif /* LCD_H_ */
