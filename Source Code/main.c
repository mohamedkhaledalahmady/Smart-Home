#include"GPIO.h"
#include "STD_Types.h"
#include "Utils.h"
#include"Led.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include "Button.h"
#include "Clock.h"
#include "SEVERAL_TASKS.h"
#include "Seg.h"
#include "LCD.h"
#include "Servo.h"
#include<string.h>
#include "PasswordDoorlock.h"

//sayedd

#include "intt.h"
#include "reg.h"
#include "ttypes.h"
#include "addc.h"

#define data1 1000
#define data2 1500

#define NUMBER_OF_OVERFLOWS_FOR_1SECOND 4

unit8 NoOfQuarterSecondT2 = 0;
unit8 NoOfQuarterSecondT0 = 0;

volatile u8 x = 0;
//#define F_CPU 1000000
u8 result;
u8 flag = 0;
u8 flag_2 = 0;
u8 flag_3 = 0;
u8 flag_4 = 0;
u8 red_led = 0;

//Neyazi
void timer_neyazi_1() {
	DDRD |= (1 << 5);
	TCCR1A |= (1 << COM1A1);
	TCCR1A |= (1 << WGM11);
	TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS10);
	ICR1 = 19999;
	OCR1A = data2;
}
void timer_neyazi_2() {
	DDRD |= (1 << 5);

	//GPIO_init_pin(GPIO_D, PIN5, GPIO_OUTPUT);
	TCCR1A |= (1 << COM1A1);
	TCCR1A |= (1 << WGM11);
	TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS10);
	ICR1 = 19999;
	OCR1A = data1;
}
///Neyazi
void Set_Password()
{
	lcd_Clear();
	lcd_setCursor(0, 5);
	lcd_write_string("Hello");
	lcd_setCursor(1, 2);
	lcd_write_string("first User :)");
	_delay_ms(2000);
	lcd_Clear();
	lcd_write_string("default pass is");
	lcd_setCursor(1, 0);
	lcd_write_string("0000");
	_delay_ms(2000);
	lcd_Clear();
	char correctPass[4] = "0000";
	eeprom_write_block((void*) correctPass, (void*) 0, PASSWORDDIGITS);
}
void Main_Screen()
{
	lcd_setCursor(0, 0);
	lcd_write_string("1.Room1 ");
	lcd_write_string("2.Room2");
	lcd_setCursor(1, 0);
	lcd_write_string("3.Temperature");
}
void Screen_Room_1()
{
	lcd_setCursor(0, 0);
	lcd_write_string("1. Red  2. Green");
	lcd_setCursor(1, 0);
	lcd_write_string("3. Return");
}
void Screen_Room_2()
{
	lcd_setCursor(0, 0);
	lcd_write_string("1. Blue 2. White");
	lcd_setCursor(1, 0);
	lcd_write_string("3. Return");
}
void Screen_Temp()
{
	lcd_setCursor(0, 0);
	lcd_write_string("Temp: 50");
	lcd_setCursor(1, 0);
	lcd_write_string("3. Return");
}
void Screen_Time()
{
	lcd_setCursor(0, 0);
	lcd_write_string("Date: 25/5/2022");
	lcd_setCursor(1, 0);
	lcd_write_string("Time: 00:00");
}
void LEDS_Init()
{
	GPIO_InitPin(GPIO_C, GPIO_PIN1, GPIO_OUTPUT);
	GPIO_InitPin(GPIO_A, GPIO_PIN0, GPIO_OUTPUT);
	GPIO_InitPin(GPIO_A, GPIO_PIN1, GPIO_OUTPUT);
	GPIO_InitPin(GPIO_A, GPIO_PIN2, GPIO_OUTPUT);

	GPIO_WritePin(GPIO_C, GPIO_PIN1, GPIO_LOW);
	GPIO_WritePin(GPIO_A, GPIO_PIN0, GPIO_LOW);
	GPIO_WritePin(GPIO_A, GPIO_PIN1, GPIO_LOW);
	GPIO_WritePin(GPIO_A, GPIO_PIN2, GPIO_LOW);
}
void Check_leds_room_1(unit8 choose)
{
	if(choose == '1')
		GPIO_Toggle(GPIO_C, GPIO_PIN1);
	else if(choose =='2')
		GPIO_Toggle(GPIO_A, GPIO_PIN0);
}
void Check_leds_room_2(unit8 choose)
{
	if(choose == '1')
		GPIO_Toggle(GPIO_A, GPIO_PIN1);
	else if(choose =='2')
		GPIO_Toggle(GPIO_A, GPIO_PIN2);
}
void Buttons_Init()
{
	GPIO_InitPin(GPIO_C, GPIO_PIN6, GPIO_INPUT);
	GPIO_InitPin(GPIO_C, GPIO_PIN7, GPIO_INPUT);
	SET_BIT(PORTC,6);
	SET_BIT(PORTC,7);
}
int main()
{
		lcd_Init();
		LEDS_Init();
		Buttons_Init();
		if(eeprom_read_byte(0x10) == 0xFF)
		{
			Set_Password();
			eeprom_write_byte(0x10,0);
		}
	    int(*ptr[4])()={Main_Screen,Screen_Room_1,Screen_Room_2,Screen_Temp,Screen_Time};
	    unit8 screen_no = 0;

		DIO_SetPinDirection(PORTA_Reg, PIN0, INPUT);
		//Enable
		DIO_SetPinDirection(PORTA_Reg, PIN5, OUTPUT);
		//Read/Write
		DIO_SetPinDirection(PORTA_Reg, PIN6, OUTPUT);
		unit8 state = 0;
		lcd_Clear();
		label:
			lcd_setCursor(0, 0);
			lcd_write_string("1. open door");
			lcd_setCursor(1, 0);
			lcd_write_string("2. change pass");
			while(!detect_Button()){}
			char keyPressed = detect_Button();
			if (keyPressed == BUTTON1)
			{
				state = password_checking();
			}
			else if (keyPressed == BUTTON2)
			{
				change_password();
			}
			if (state == 2 || state == 3)
				goto label;
		unit8 pressed_button=0;
		while (1)
		{
			if(screen_no == 0)
			{
				if(detect_Button()!=0)
				{
					screen_no = detect_Button();
					while(detect_Button()){}
					lcd_Clear();
				}
				screen_no == 0 ? (*ptr[screen_no])() : (*ptr[screen_no-'0'])();
			}
			else if(screen_no == '1')
			{
				if(detect_Button()!=0)
				{
					pressed_button = detect_Button();
					while(detect_Button()){}
					if(pressed_button == '3')
					{
						screen_no = 0;
						lcd_Clear();
					}
					Check_leds_room_1(pressed_button);
				};
			}
			else if(screen_no == '2')
			{
				if(detect_Button()!=0)
				{
					pressed_button = detect_Button();
					while(detect_Button()){}
					if(pressed_button == '3')
					{
						screen_no = 0;
						lcd_Clear();
					}
					Check_leds_room_2(pressed_button);
				};
			}
			else if(screen_no == '3')
			{
				if(detect_Button()!=0)
				{
					pressed_button = detect_Button();
					while(detect_Button()){}
					if(pressed_button == '3')
					{
						screen_no = 0;
						lcd_Clear();
					}
				};
			}
			else
			{
				lcd_Clear();
				lcd_write_string("Error");
			}
		}
	return 0;
}






ISR( TIMER2_OVF_vect ) {
	/**CODE**/

	NoOfQuarterSecondT2++;

	if (NoOfQuarterSecondT2 == 4) {
		//SAYED PART

		result = (ADC_Read(0) * 500) / 1023;
		//If temp>50, blink RED-LED
		if (result > 50) {
			SET_BIT(PORTA_Reg, PIN2);
			SET_BIT(PORTA_Reg, PIN3); // RED LED
			_delay_ms(20);
			CLEAR_BIT(PORTA_Reg, PIN3);
			_delay_ms(20);
			flag = 1;  //FLAG FOR FIRE !!
		} else {
			flag = 0;
		}

		if (!flag) { // { flag=0 }  =  { result<50 }
			CLEAR_BIT(PORTA_Reg, PIN2); //BUZZER PIN
			SET_BIT(PORTA_Reg, PIN1); //GREEN LED
			_delay_ms(20);
			CLEAR_BIT(PORTA_Reg, PIN1);
			_delay_ms(20);
			//result = (ADC_Read(0) * 500) / 1023;
			if (result > 50)
				flag = 1;
		}

		//SAYED PART #END
		NoOfQuarterSecondT2 = 0;
	}

}

//INTRRUPT FOR NYAZI PART

ISR(TIMER0_OVF_vect) {

	NoOfQuarterSecondT0++;

	if (NoOfQuarterSecondT0 == 1) {
		//		GPIO_InitPin(GPIO_A, GPIO_PIN5, GPIO_OUTPUT);
		//		GPIO_WritePin(GPIO_A, GPIO_PIN5, GPIO_HIGH);
		//
		//		_delay_ms(200);
		//
		//		GPIO_WritePin(GPIO_A, GPIO_PIN5, GPIO_LOW);
		if (DIO_GetPinValue(GPIO_D, GPIO_PIN2)) {
			timer_neyazi_2();
//					while (DIO_GetPinValue(GPIO_D, GPIO_PIN2))
//						;
//                    if( ! DIO_GetPinValue(GPIO_D, GPIO_PIN2)){
////					_delay_ms(500);
//					timer_neyazi_1();
//                    }
		}

		else if (!DIO_GetPinValue(GPIO_D, GPIO_PIN2)) {
			//					_delay_ms(500);
			timer_neyazi_1();
		}

		NoOfQuarterSecondT0 = 0;
//				lcd_command(CLEAR);
	}

}

