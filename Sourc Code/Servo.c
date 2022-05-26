#include"GPIO.h"
#include "STD_Types.h"
#include "Utils.h"
#include"Led.h"
#include <avr/io.h>
#include <util/delay.h>
#include "Servo.h"
#include<string.h>

void rotate90() {

	DDRD |= (1 << 4);
	TCCR1A &= ~(1 << FOC1B); //ask neyazi
	TCCR1A |= (1 << COM1B1);
	TCCR1A |= (1 << WGM11);
	TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS10);
	ICR1 = 19999; //timer will count from 0 to ICR1(TOP Value), FPWM = FOSC / ( N * ( 1 + TOP ) ) , We are using the 14th waveform generation mode of Timer1 in ATmega16, where TOP value for timer1 is decided by ICR1 register i.e. we can load TOP value in the ICR1 register, where timer1 overflow occurs and timer1 overflow flag gets set.
	OCR1B = 1000; //OCR1B= desired high pwm time / total period--> (1/ frequency prescaled)
}


void rotate00() {
	DDRD |= (1 << PD4); /* Make OC1A pin as output */

	DDRD |= (1 << 4);
		TCCR1A &= ~(1 << FOC1A);  //ask neyazi
		TCCR1A |= (1 << COM1B1);
		TCCR1A |= (1 << WGM11);
		TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS10);
		ICR1 = 19999;
		OCR1B = 1500;
}
