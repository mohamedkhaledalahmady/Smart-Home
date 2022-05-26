#include"GPIO.h"
#include "STD_Types.h"
#include "Utils.h"
#include "Seg.h"
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>

void Seg_Init(unit8 segNo){

	GPIO_InitPin(SEGA_PORT, SEGA_PIN, GPIO_OUTPUT);
	GPIO_InitPin(SEGB_PORT, SEGB_PIN, GPIO_OUTPUT);
	GPIO_InitPin(SEGC_PORT, SEGC_PIN, GPIO_OUTPUT);
	GPIO_InitPin(SEGD_PORT, SEGD_PIN, GPIO_OUTPUT);
	switch(segNo){
	  case SEG1:
          GPIO_InitPin(EN1_PORT, EN1_PIN,GPIO_OUTPUT);

		  break;
	  case SEG2:
		  GPIO_InitPin(EN2_PORT, EN2_PIN,GPIO_OUTPUT);

		  break;
	  case SEG3:
		  GPIO_InitPin(EN3_PORT, EN3_PIN,GPIO_OUTPUT);

		  break;
	  case SEG4:
		  GPIO_InitPin(EN4_PORT, EN4_PIN,GPIO_OUTPUT);

	}

}

void Seg_DeInit(unit8 segNo){
	switch(segNo){
		  case SEG1:
			  GPIO_WritePin(EN1_PORT, EN1_PIN,GPIO_HIGH);
			  GPIO_InitPin(EN1_PORT, EN1_PIN,GPIO_INPUT);

			  break;
		  case SEG2:
			  GPIO_WritePin(EN2_PORT, EN2_PIN,GPIO_HIGH);
			  GPIO_InitPin(EN2_PORT, EN2_PIN,GPIO_INPUT);

			  break;
		  case SEG3:
			  GPIO_WritePin(EN3_PORT, EN3_PIN,GPIO_HIGH);
			  GPIO_InitPin(EN3_PORT, EN3_PIN,GPIO_INPUT);

			  break;
		  case SEG4:
			  GPIO_WritePin(EN4_PORT, EN4_PIN,GPIO_HIGH);
			  GPIO_InitPin(EN4_PORT, EN4_PIN,GPIO_INPUT);

   }
}


void Seg_Write(unit8 segNo, unit8 value){
	GPIO_WritePin(EN1_PORT, EN1_PIN,GPIO_HIGH);
    GPIO_WritePin(EN2_PORT, EN2_PIN,GPIO_HIGH);
	GPIO_WritePin(EN3_PORT, EN3_PIN,GPIO_HIGH);
	GPIO_WritePin(EN4_PORT, EN4_PIN,GPIO_HIGH);

	switch(segNo){
	case SEG1:

	          GPIO_WritePin(EN1_PORT, EN1_PIN,GPIO_LOW);
			  break;
		  case SEG2:

			  GPIO_WritePin(EN2_PORT, EN2_PIN,GPIO_LOW);
			  break;
		  case SEG3:

			  GPIO_WritePin(EN3_PORT, EN3_PIN,GPIO_LOW);
			  break;
		  case SEG4:

			  GPIO_WritePin(EN4_PORT, EN4_PIN,GPIO_LOW);

	}


	switch(value){
	   case 0:
		   GPIO_WritePin(SEGA_PORT, SEGA_PIN,GPIO_LOW);
		   GPIO_WritePin(SEGB_PORT, SEGB_PIN,GPIO_LOW);
		   GPIO_WritePin(SEGC_PORT, SEGC_PIN,GPIO_LOW);
		   GPIO_WritePin(SEGD_PORT, SEGD_PIN,GPIO_LOW);
		   break;
	   case 1:
		   GPIO_WritePin(SEGA_PORT, SEGA_PIN,GPIO_HIGH);
		   GPIO_WritePin(SEGB_PORT, SEGB_PIN,GPIO_LOW);
		   GPIO_WritePin(SEGC_PORT, SEGC_PIN,GPIO_LOW);
		   GPIO_WritePin(SEGD_PORT, SEGD_PIN,GPIO_LOW);
		   break;
	   case 2:
	   		   GPIO_WritePin(SEGA_PORT, SEGA_PIN,GPIO_LOW);
	   		   GPIO_WritePin(SEGB_PORT, SEGB_PIN,GPIO_HIGH);
	   		   GPIO_WritePin(SEGC_PORT, SEGC_PIN,GPIO_LOW);
	   		   GPIO_WritePin(SEGD_PORT, SEGD_PIN,GPIO_LOW);
	   		   break;
	   case 3:
	   		   GPIO_WritePin(SEGA_PORT, SEGA_PIN,GPIO_HIGH);
	   		   GPIO_WritePin(SEGB_PORT, SEGB_PIN,GPIO_HIGH);
	   		   GPIO_WritePin(SEGC_PORT, SEGC_PIN,GPIO_LOW);
	   		   GPIO_WritePin(SEGD_PORT, SEGD_PIN,GPIO_LOW);
	   		   break;
	   case 4:
	   		   GPIO_WritePin(SEGA_PORT, SEGA_PIN,GPIO_LOW);
	   		   GPIO_WritePin(SEGB_PORT, SEGB_PIN,GPIO_LOW);
	   		   GPIO_WritePin(SEGC_PORT, SEGC_PIN,GPIO_HIGH);
	   		   GPIO_WritePin(SEGD_PORT, SEGD_PIN,GPIO_LOW);
	   		   break;
	   case 5:
	   		   GPIO_WritePin(SEGA_PORT, SEGA_PIN,GPIO_HIGH);
	   		   GPIO_WritePin(SEGB_PORT, SEGB_PIN,GPIO_LOW);
	   		   GPIO_WritePin(SEGC_PORT, SEGC_PIN,GPIO_HIGH);
	   		   GPIO_WritePin(SEGD_PORT, SEGD_PIN,GPIO_LOW);
	   		   break;
	   case 6:
	   		   GPIO_WritePin(SEGA_PORT, SEGA_PIN,GPIO_LOW);
	   		   GPIO_WritePin(SEGB_PORT, SEGB_PIN,GPIO_HIGH);
	   		   GPIO_WritePin(SEGC_PORT, SEGC_PIN,GPIO_HIGH);
	   		   GPIO_WritePin(SEGD_PORT, SEGD_PIN,GPIO_LOW);
	   		   break;
	   case 7:
	   		   GPIO_WritePin(SEGA_PORT, SEGA_PIN,GPIO_HIGH);
	   		   GPIO_WritePin(SEGB_PORT, SEGB_PIN,GPIO_HIGH);
	   		   GPIO_WritePin(SEGC_PORT, SEGC_PIN,GPIO_HIGH);
	   		   GPIO_WritePin(SEGD_PORT, SEGD_PIN,GPIO_LOW);
	   		   break;
	   case 8:
	   		   GPIO_WritePin(SEGA_PORT, SEGA_PIN,GPIO_LOW);
	   		   GPIO_WritePin(SEGB_PORT, SEGB_PIN,GPIO_LOW);
	   		   GPIO_WritePin(SEGC_PORT, SEGC_PIN,GPIO_LOW);
	   		   GPIO_WritePin(SEGD_PORT, SEGD_PIN,GPIO_HIGH);
	   		   break;
	   case 9:
	   		   GPIO_WritePin(SEGA_PORT, SEGA_PIN,GPIO_HIGH);
	   		   GPIO_WritePin(SEGB_PORT, SEGB_PIN,GPIO_LOW);
	   		   GPIO_WritePin(SEGC_PORT, SEGC_PIN,GPIO_LOW);
	   		   GPIO_WritePin(SEGD_PORT, SEGD_PIN,GPIO_HIGH);

	}
  }

//to write sequentially on the 4 seg's.

void Seg_WriteSeq(sint16 fullValue,unit8 segBegininng){
	for(unit8 k=1;k<=4;k++){
	    Seg_Init(k);
	 }
	if(9<fullValue){
			unit8 i=0;
            while(pow(10,i)<=fullValue){++i;}
	        --i;

	        unit8 segNum=segBegininng;
		    unit8 digit;

	        for(unit8 j=i;j>=0;j--){
	        	digit=fullValue/pow(10,j);
	        	++segNum;
	        	Seg_Write(segNum, digit);
	            _delay_ms(0.001);
                fullValue=fullValue-digit*pow(10,j);
                if(fullValue==0 && j==0){break;}
	        }
           // if(fullValue==0&&j==0){Seg_Write(segNum, 0);}
		}
		 else{

			   Seg_Write(segBegininng+1,0);
		       _delay_ms(0.1);
		       Seg_Write(segBegininng+2,fullValue);
		       _delay_ms(0.1);
		}
}


