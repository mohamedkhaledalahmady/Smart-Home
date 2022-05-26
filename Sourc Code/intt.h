/*
 * intt.h
 *
 * Created: 4/24/2022 1:10:45 AM
 *  Author: mohamed
 */ 


#ifndef INTT_H_
#define INTT_H_

//#include "bbit_math.h"
#include "ttypes.h"


/* Port Defines */
//#define PORTA    0
//#define PORTB    1
//#define PORTC    2
//#define PORTD    3

/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

/* PIN Directions */
#define INPUT  0
#define OUTPUT 1

/* PIN Value Options */
#define HIGH   1
#define LOW    0

/* IO Pins */
void DIO_SetPinDirection (u8 PortId_Pin, u8 PinId, u8 PinDir);

void DIO_SetPinValue(u8 PortId_Pin , u8 PinId, u8 PinVal);

u8 DIO_GetPinValue(u8 PortId_Pin, u8 PinId);


/* IO Ports */
void DIO_SetPortDirection (u8 PortId, u8 PortDir);

void DIO_SetPortValue     (u8 PortId, u8 PortVal);






#endif /* INTT_H_ */
