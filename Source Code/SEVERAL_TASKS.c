#include"GPIO.h"
#include "STD_Types.h"
#include "Utils.h"
#include"Led.h"
#include <avr/io.h>
#include <util/delay.h>
#include "Button.h"
#include "Servo.h"
#include "SEVERAL_TASKS.h"

#include "Clock.h"
#include "Sebha.h"
#include "Seg.h"

char detect_Button() {

	///button 1 increases sebha
	unit8 pressedKey = Get_Button(BUTTON1); // volatile ??
	if (pressedKey == BUTTON1) {
		return pressedKey;
	}


	pressedKey = Get_Button(BUTTON2);
	if (pressedKey == BUTTON2) { // pressedKey2 required ??

		return pressedKey;

	}

	//button 3 to decrease minutes

	pressedKey = Get_Button(BUTTON3);
	if (pressedKey == BUTTON3) {

		return pressedKey;

	}

	//button 4 to increase hours
	pressedKey = Get_Button(BUTTON4);
	if (pressedKey == BUTTON4) {

		return pressedKey; //why puttig return here , put it in the last line ??

	}

	//button 5 to decrease hours
	pressedKey = Get_Button(BUTTON5);
	if (pressedKey == BUTTON5) {

		return pressedKey;

	}


	pressedKey = Get_Button(BUTTON6);
	if (pressedKey == BUTTON6) {

		return pressedKey;

	}


	pressedKey = Get_Button(BUTTON7);
	if (pressedKey == BUTTON7) {

		return pressedKey;

	}


	pressedKey = Get_Button(BUTTON8);
	if (pressedKey == BUTTON8) {

		return pressedKey;

	}

	pressedKey = Get_Button(BUTTON9);
	if (pressedKey == BUTTON9) {

		return pressedKey;

	}


	pressedKey = Get_Button(BUTTON10);
	if (pressedKey == BUTTON10) {

		return pressedKey;

	}


	pressedKey = Get_Button(BUTTON11);
	if (pressedKey == BUTTON11) {

		return pressedKey;

	}

	pressedKey = Get_Button(BUTTON12);
	if (pressedKey == BUTTON12) {

		return pressedKey;

	}

	pressedKey = Get_Button(BUTTON13);
	if (pressedKey == BUTTON13) {

		return pressedKey;

	}

	pressedKey = Get_Button(BUTTON14);
	if (pressedKey == BUTTON14) {

		return pressedKey;

	}

	pressedKey = Get_Button(BUTTON15);
	if (pressedKey == BUTTON15) {

		return pressedKey;

	}

	pressedKey = Get_Button(BUTTON16);
	if (pressedKey == BUTTON16) {

		return pressedKey;

	}


	else{
		return 0;
	}


	//_delay_ms(100); // is this delay suitable ???

}

