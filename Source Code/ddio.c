/*
 * ddio.c
 *
 * Created: 4/24/2022 1:09:57 AM
 *  Author: mohamed
 */ 
#include "ttypes.h"
//#include "bbit_math.h"
#include "intt.h"
#include "reg.h"
#include "Utils.h"
#include "GPIO.h"
/* IO Pins */

void DIO_SetPinDirection (u8 PortId_Pin, u8 PinId, u8 PinDir)
{
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((PortId_Pin <= GPIO_D) && (PinId <= GPIO_PIN7))
	{
		if ( PinDir == OUTPUT )
		{
			/* Check on the Required PORT Number */
			switch (PortId_Pin)
			{
				case GPIO_A: SET_BIT(DDRA_Reg,PinId); break;
				case GPIO_B: SET_BIT(DDRB_Reg,PinId); break;
				case GPIO_C: SET_BIT(DDRC_Reg,PinId); break;
				case GPIO_D: SET_BIT(DDRD_Reg,PinId); break;
			}
		}
		
		else if ( PinDir == INPUT )
		{
			/* Check on the Required PORT Number */
			switch (PortId_Pin)
			{
				case GPIO_A: CLEAR_BIT(DDRA_Reg,PinId); break;
				case GPIO_B: CLEAR_BIT(DDRB_Reg,PinId); break;
				case GPIO_C: CLEAR_BIT(DDRC_Reg,PinId); break;
				case GPIO_D: CLEAR_BIT(DDRD_Reg,PinId); break;
			}
		}
		
		else
		{
			/* Do nothing, Wrong Direction Required */
		}
	}
	
	else
	{
		/* Do nothing, Error in the Pin ID or PORT ID */
	}
}


void DIO_SetPinValue(u8 PortId_Pin , u8 PinId, u8 PinVal)
{
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((PortId_Pin <= GPIO_D) && (PinId <= GPIO_PIN7))
	{
		if (PinVal == HIGH)
		{
			/* Check on the Required PORT Number */
			switch (PortId_Pin)
			{
				case GPIO_A: SET_BIT(PORTA_Reg,PinId); break;
				case GPIO_B: SET_BIT(PORTB_Reg,PinId); break;
				case GPIO_C: SET_BIT(PORTC_Reg,PinId); break;
				case GPIO_D: SET_BIT(PORTD_Reg,PinId); break;
			}
			
		}
		
		else if (PinVal == LOW)
		{
			/* Check on the Required PORT Number */
			switch (PortId_Pin)
			{
				case GPIO_A: CLEAR_BIT(PORTA_Reg,PinId); break;
				case GPIO_B: CLEAR_BIT(PORTB_Reg,PinId); break;
				case GPIO_C: CLEAR_BIT(PORTC_Reg,PinId); break;
				case GPIO_D: CLEAR_BIT(PORTD_Reg,PinId); break;
			}
		}
		
		else
		{
			/* Do nothing, Wrong value to set */
		}
	}
	
	else
	{
		/* Do nothing, Error in the Pin ID or PORT ID */
	}
}

u8 DIO_GetPinValue(u8 PortId_Pin, u8 PinId)
{
	/* Define Local Variable to get the BIT Value */
	u8 ResultLocal;
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((PortId_Pin <= GPIO_D) && (PinId <= GPIO_PIN7))
	{
		/* Check on the Required PORT Number */
		switch (PortId_Pin)
		{
			case GPIO_A: ResultLocal= GET_BIT(PINA_Reg,PinId); break;
			case GPIO_B: ResultLocal= GET_BIT(PINB_Reg,PinId); break;
			case GPIO_C: ResultLocal= GET_BIT(PINC_Reg,PinId); break;
			case GPIO_D: ResultLocal= GET_BIT(PIND_Reg,PinId); break;
		}
	}
	
	else
	{
		/* return 0xff in case of error in the Pin ID or PORT ID */
		ResultLocal = 0xFF;
	}
	
	return ResultLocal;
}


/* IO Ports */
void DIO_SetPortDirection (u8 PortId, u8 PortDir)
{
	/* Check on the Required PORT Number */
	switch (PortId)
	{
		case     GPIO_A: DDRA_Reg = PortDir; break;
		case     GPIO_B: DDRB_Reg = PortDir; break;
		case     GPIO_C: DDRC_Reg = PortDir; break;
		case     GPIO_D: DDRD_Reg = PortDir; break;
		default: /* Wrong Port ID */       break;
	}
}

void DIO_SetPortValue (u8 PortId, u8 PortVal)
{
	/* Check on the Required PORT Number */
	switch (PortId)
	{
		case     GPIO_A: PORTA_Reg = PortVal; break;
		case     GPIO_B: PORTB_Reg = PortVal; break;
		case     GPIO_C: PORTC_Reg = PortVal; break;
		case     GPIO_D: PORTD_Reg = PortVal; break;
		default: /* Wrong Port ID */        break;
	}
}

