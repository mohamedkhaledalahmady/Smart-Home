#include"GPIO.h"
#include "STD_Types.h"
#include "Utils.h"
#include"Led.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include "Button.h"
#include "Clock.h"
#include "SEVERAL_TASKS.h"
#include "Seg.h"
#include "LCD.h"
#include "Servo.h"
#include<string.h>
#include "PasswordDoorlock.h"

unit8 trysNo = MAXIMUMTRYS;
unit8 password_checking()
{
	unit8 state=0;
	unit8 charNo = 0; // charEntered ???
	char passEntered[4] = "0000";
	char correctPass[4] = "0000";
	eeprom_read_block((void*) correctPass, (void*) 0, PASSWORDDIGITS); //getting stored password into correctPass
	char pressedKey = NO_KEY; // char or int
	char oldDetectButton = NO_KEY;
	lcd_Clear();
	lcd_write_string("Enter password:");
	lcd_setCursor(1, 0);
	oldDetectButton = detect_Button();
	while (charNo < 4) { // 4 ??
		pressedKey = detect_Button();
		if (oldDetectButton == pressedKey)
		{
			continue;
		}
		oldDetectButton = pressedKey;
		if (pressedKey == BUTTON16) {

			if (charNo > 0) {
				lcd_setCursor(1, (charNo - 1));
				lcd_write_charcter(' ');
				lcd_setCursor(1, (charNo - 1));
				charNo--;
			}
		}
		else if (pressedKey != NO_KEY && pressedKey != BUTTON16) {
			lcd_write_charcter('*');
			passEntered[charNo] = pressedKey;
			charNo++;
		}
		_delay_ms(50);
	}
	charNo = 0;
	while (charNo < 4) {

		if (passEntered[charNo] != correctPass[charNo]) {
			break;
		}
		charNo++;
	}
	lcd_command(CLEAR);
	_delay_ms(400);
	if (charNo < 4) {
		lcd_setCursor(0, 0);
		_delay_ms(100);
		trysNo--;
		if (trysNo <= 0)
		{
			state = 3;
			lcd_command(CLEAR);
			_delay_ms(100);
			trysNo = MAXIMUMTRYS;
			lcd_write_string("try again in 10 sec");
			_delay_ms(10000);
			lcd_command(CLEAR);
		}
		else
		{
			state = 2;
			lcd_setCursor(0, 5);
			lcd_write_string("Oooops");
			lcd_setCursor(1, 0);
			lcd_write_string("Please try again");
			_delay_ms(1000);
			lcd_command(CLEAR);
		}
	}

	else if (charNo == 4) {
		state = 1;
		lcd_command(CLEAR);
		lcd_setCursor(0, 0);
		lcd_write_string("Password correct");
		rotate90();
		_delay_ms(2000); //here we will put different condition will close door like motion sensor //
		rotate00();
		lcd_command(CLEAR);
	}
	return state;
}

void change_password() {

//    password_checking();

	unit8 flag = 0;
	lcd_setCursor(0, 0);
	lcd_command(CLEAR);
//	lcd_write_string("Please enter pass");
	unit8 charNo = 0; // charEntered ???
	char passEntered[4] = "0000";

	char correctPass[4] = "0000";

	eeprom_read_block((void*) correctPass, (void*) 0, PASSWORDDIGITS);

	char pressedKey = NO_KEY; // char or int
	char oldDetectButton = NO_KEY;
	_delay_ms(50);
	lcd_write_string("Enter password:");
	lcd_setCursor(1, 0);
	oldDetectButton = detect_Button();
	while (charNo < 4) { // 4 ??

		pressedKey = detect_Button();

		if (oldDetectButton == pressedKey) {
			continue;
		}

		oldDetectButton = pressedKey;

		if (pressedKey != NO_KEY && pressedKey != BUTTON16) {

			lcd_write_charcter('*');
			passEntered[charNo] = pressedKey;
			charNo++;
		}

		if (pressedKey == BUTTON16) {
			if (charNo > 0) {
				lcd_setCursor(1, (charNo - 1));
				lcd_write_charcter(' ');
				lcd_setCursor(1, (charNo - 1));
				charNo--;
			}
		}

		_delay_ms(50);

	}

	charNo = 0;
	while (charNo < 4) {

		if (passEntered[charNo] != correctPass[charNo]) {
			break;
		}
		charNo++;

	}

	lcd_command(CLEAR);
	_delay_ms(100);
	if (charNo < 4) {
		lcd_setCursor(0, 0);
		_delay_ms(100);
		trysNo--;
		if (trysNo <= 0) {

			lcd_command(CLEAR);
			_delay_ms(100);
			trysNo = MAXIMUMTRYS;
			lcd_write_string("try again in 30 sec");
			_delay_ms(20000);
			lcd_command(CLEAR);

		} else
		{
			lcd_setCursor(0, 5);
			lcd_write_string("Oooops");
			lcd_setCursor(1, 0);
			lcd_write_string("Please try again");
			_delay_ms(2000);
			lcd_command(CLEAR);

		}

	}

	else if (charNo == 4) {
		lcd_command(CLEAR);
		_delay_ms(100);

		lcd_setCursor(0, 0);
		_delay_ms(100);
		lcd_write_string("Password correct");
		_delay_ms(2000);
		lcd_command(CLEAR);
		flag = 1; //old password correct--> allow him to change password
	}

	if (flag == 1) { //testing if the old password is entered properly
		//_delay_ms(1000);
		lcd_command(CLEAR);
		//_delay_ms(500);
//		lcd_write_string("enter new password");
		char newPassword[] = "0000";
		char keyPressed = NO_KEY;
		char oldButtonDetect = NO_KEY;

		charNo = 0;
		lcd_write_string("Enter new pass:");
		lcd_setCursor(1, 0);
		oldButtonDetect = detect_Button();
		while (charNo < 4) {

			keyPressed = detect_Button();
			if (oldButtonDetect == keyPressed) {
				continue;
			}
			oldButtonDetect = keyPressed;

			if (keyPressed == BUTTON16)
			{
				if (charNo > 0)
				{
					lcd_setCursor(1, (charNo - 1));
					lcd_write_charcter(' ');
					lcd_setCursor(1, (charNo - 1));
					charNo--;
				}
			}
			else if (keyPressed != NO_KEY && keyPressed != BUTTON16) {
				newPassword[charNo] = keyPressed;
				lcd_write_charcter('*');
				charNo++;
				_delay_ms(100); // why 300 is not enough + lights are blinking faster than its similars ????????????????
			}
		}
		eeprom_write_block((void*) newPassword, (void*) 0, PASSWORDDIGITS);
		lcd_command(CLEAR);
		_delay_ms(100);
	}
}

void password_page()
{
	//	lcd_command(CLEAR);
	lcd_setCursor(0, 0);
	//_delay_ms(200);
	lcd_write_string("1. open door");
	lcd_setCursor(1, 0);
	lcd_write_string("2. change pass");
	char keyPressed = detect_Button();
	if (keyPressed == BUTTON1) {
		password_checking();
	}
	else if (keyPressed == BUTTON2) {
		change_password();
	}

}

