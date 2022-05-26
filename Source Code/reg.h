/*
 * reg.h
 *
 * Created: 4/24/2022 1:10:18 AM
 *  Author: mohamed
 */ 


#ifndef REG_H_
#define REG_H_

//#include "bbit_math.h"
#include "ttypes.h"

/* Group A Registers */
#define PORTA_Reg  *((volatile u8*)0x3B)
#define DDRA_Reg   *((volatile u8*)0x3A)
#define PINA_Reg   *((volatile u8*)0x39)

/* Group B Registers */
#define PORTB_Reg  *((volatile u8*)0x38)
#define DDRB_Reg   *((volatile u8*)0x37)
#define PINB_Reg   *((volatile u8*)0x36)

/* Group C Registers */
#define PORTC_Reg  *((volatile u8*)0x35)
#define DDRC_Reg   *((volatile u8*)0x34)
#define PINC_Reg   *((volatile u8*)0x33)

/* Group D Registers */
#define PORTD_Reg  *((volatile u8*)0x32)
#define DDRD_Reg   *((volatile u8*)0x31)
#define PIND_Reg   *((volatile u8*)0x30)



#endif /* REG_H_ */
