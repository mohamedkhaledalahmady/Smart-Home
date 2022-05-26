/*
 * addc.c
 *
 * Created: 4/24/2022 1:11:47 AM
 *  Author: mohamed
 */ 
#include "ttypes.h" // unsignedcahracter --> uint8 and so on
//#include "bbit_math.h" // setbit , clear bit
#include  "addc.h"
#include "Utils.h"

void ADC_Init (void)
{
	// ADC Enable
	SET_BIT(ADCSRA_Reg,7);

	// Prescaler Configuration as 128
	SET_BIT(ADCSRA_Reg,2);
	SET_BIT(ADCSRA_Reg,1);
	SET_BIT(ADCSRA_Reg,0);


	// Referance Voltage as AVCC with external capacitor
	CLEAR_BIT(ADMUX_Reg,7);
	SET_BIT(ADMUX_Reg,6);

	// ADC Data Rgith Adjustment
	CLEAR_BIT(ADMUX_Reg,5);
}

u16 ADC_Read (u8 channel)
{
	// ADC Channel Selection
	
	channel &= 0x07;  /* channel number must be from 0 --> 7 */
	ADMUX_Reg &= 0xE0;  /* clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX_Reg |= channel; /* choose the correct channel by setting the channel number in MUX4:0 bits */

	// Start Single Convertion
	SET_BIT(ADCSRA_Reg,6);

	//wait for the conversion
	while(!(ADCSRA_Reg & (1<<4)));

	//ADC Flag Clear
	SET_BIT(ADCSRA_Reg,4);

	u16 result =0;
	u16 lsb= ADCL_Reg & 0x00FF;
	u16 msb= ADCH_Reg & 0x0003;
	result = lsb | (msb<<8);
	return result;
}
