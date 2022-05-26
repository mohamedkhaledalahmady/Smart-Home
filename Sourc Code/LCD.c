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

void lcd_enable_active(){
    GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_HIGH);
    _delay_us(1);
    GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_LOW);
    _delay_us(200);

}


void lcd_command(unit16 cmd){


	GPIO_WritePin(LCD_PORT, LCD_D4_PIN, ((cmd>>4)&1));
    GPIO_WritePin(LCD_PORT, LCD_D5_PIN, ((cmd>>5)&1));
    GPIO_WritePin(LCD_PORT, LCD_D6_PIN, ((cmd>>6)&1));
    GPIO_WritePin(D7_PORT, LCD_D7_PIN, ((cmd>>7)&1));

    GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_LOW);

    lcd_enable_active();

    GPIO_WritePin(LCD_PORT, LCD_D4_PIN, ((cmd>>0)&1));
    GPIO_WritePin(LCD_PORT, LCD_D5_PIN, ((cmd>>1)&1));
    GPIO_WritePin(LCD_PORT, LCD_D6_PIN, ((cmd>>2)&1));
    GPIO_WritePin(D7_PORT, LCD_D7_PIN, ((cmd>>3)&1));

    lcd_enable_active();

}



void lcd_Init(){

   GPIO_InitPin(LCD_RS_PORT,LCD_RS_PIN , GPIO_OUTPUT);
  // GPIO_InitPin(LCD_RW_PORT,LCD_RW_PIN , GPIO_OUTPUT);
   GPIO_InitPin(LCD_EN_PORT,LCD_EN_PIN , GPIO_OUTPUT);

   //GPIO_WritePin(LCD_RW_PORT,LCD_RW_PIN , GPIO_LOW);

   GPIO_InitPin(LCD_PORT,LCD_D4_PIN , GPIO_OUTPUT);
   GPIO_InitPin(LCD_PORT,LCD_D5_PIN , GPIO_OUTPUT);
   GPIO_InitPin(LCD_PORT,LCD_D6_PIN , GPIO_OUTPUT);
   GPIO_InitPin(D7_PORT,LCD_D7_PIN , GPIO_OUTPUT);

   lcd_command(Cursor_home);
   _delay_ms(0.1);
   lcd_command(BIT4_Mode);
   _delay_ms(0.1);
   lcd_command(DisplayON_CursorBlink);
   _delay_ms(0.1);
}


void lcd_write_charcter(sint8 charcter){

	GPIO_WritePin(LCD_PORT, LCD_D4_PIN, (1&(charcter>>4)));
	GPIO_WritePin(LCD_PORT, LCD_D5_PIN, (1&(charcter>>5)));
	GPIO_WritePin(LCD_PORT, LCD_D6_PIN, (1&(charcter>>6)));
	GPIO_WritePin(D7_PORT, LCD_D7_PIN, (1&(charcter>>7)));

	GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_HIGH);

	lcd_enable_active();

	GPIO_WritePin(LCD_PORT, LCD_D4_PIN, (1&(charcter>>0)));
	GPIO_WritePin(LCD_PORT, LCD_D5_PIN, (1&(charcter>>1)));
	GPIO_WritePin(LCD_PORT, LCD_D6_PIN, (1&(charcter>>2)));
	GPIO_WritePin(D7_PORT, LCD_D7_PIN, (1&(charcter>>3)));

	lcd_enable_active();
}

void lcd_write_string(char *str){
   unit8 charNum=0;

   while(str[charNum]!='\0'){

	   lcd_write_charcter(str[charNum]);
       _delay_ms(1);
       ++charNum;
   }
}


void lcd_setCursor(unit8 x, unit8 y){ // for new line lcd_setCursor(x, 0x80);

	switch(x)
	{
	case 0:
		lcd_command(0x80+y);
		break;
	case 1:
		lcd_command(0xc0+y);
		break;
	case 2:
		lcd_command(0x94+y);
		break;
	case 3:
		lcd_command(0xd4+y);
	}

}

void lcd_Clear()
{
	lcd_command(CLEAR);
	lcd_command(Home);
	lcd_setCursor(0, 0);
}


