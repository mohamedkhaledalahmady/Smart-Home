/*
 * addc.h
 *
 * Created: 4/24/2022 1:11:29 AM
 *  Author: mohamed
 */ 


#ifndef ADDC_H_
#define ADDC_H_


/* Naming the registers according to their address in the data sheet  */
#define ADMUX_Reg 	*((volatile u8*)0x27) 	// ADC Multiplexer Register
#define ADCSRA_Reg 	*((volatile u8*)0x26) 	// ADC Control And Status Register
#define ADCH_Reg 	*((volatile u8*)0x25) 		// ADC High Register
#define ADCL_Reg 	*((volatile u8*)0x24) 		// ADC Low Register

/* Functions Prototypes */
/*
 * Description :
 * Function responsible for initializing the ADC driver.
 */
extern void ADC_Init (void); // ADC Initialization And Enable 

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */

extern u16 ADC_Read (u8); // Read From The ADC Channel




#endif /* ADDC_H_ */