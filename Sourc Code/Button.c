

#include <avr/io.h>
#include"GPIO.h"
#include "STD_Types.h"
#include "Utils.h"
#include "Button.h"

unit8 Get_Button(unit8 button){
    unit8 value=0;
    unit8 pressedKey=0;
	switch(button){
       case BUTTON1:
           GPIO_InitPin(KEYPAD_PORT,ROW1_PIN, GPIO_INPUT);
           Control_Pull_Up(KEYPAD_PORT,ROW1_PIN , GPIO_HIGH);

           GPIO_InitPin(KEYPAD_PORT,COL1_PIN, GPIO_OUTPUT);
           GPIO_WritePin(KEYPAD_PORT, COL1_PIN, GPIO_LOW);
           GPIO_InitPin(COL2_PORT,COL2_PIN, GPIO_OUTPUT);
           GPIO_WritePin(COL2_PORT, COL2_PIN, GPIO_HIGH);
           GPIO_InitPin(KEYPAD_PORT,COL3_PIN, GPIO_OUTPUT);
           GPIO_WritePin(KEYPAD_PORT, COL3_PIN, GPIO_HIGH);
           GPIO_InitPin(KEYPAD_PORT,COL4_PIN, GPIO_OUTPUT);
           GPIO_WritePin(KEYPAD_PORT, COL4_PIN, GPIO_HIGH);

           value =GPIO_GetPin(KEYPAD_PORT, ROW1_PIN);
           if(value == GPIO_LOW){

           pressedKey=BUTTON1;

           }
    	   break;
       case BUTTON2:
                  GPIO_InitPin(KEYPAD_PORT,ROW1_PIN, GPIO_INPUT);
                  Control_Pull_Up(KEYPAD_PORT,ROW1_PIN , GPIO_HIGH);

                  GPIO_InitPin(KEYPAD_PORT,COL1_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(KEYPAD_PORT, COL1_PIN, GPIO_HIGH);
                  GPIO_InitPin(COL2_PORT,COL2_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(COL2_PORT, COL2_PIN, GPIO_LOW);
                  GPIO_InitPin(KEYPAD_PORT,COL3_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(KEYPAD_PORT, COL3_PIN, GPIO_HIGH);
                  GPIO_InitPin(KEYPAD_PORT,COL4_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(KEYPAD_PORT, COL4_PIN, GPIO_HIGH);

                  value =GPIO_GetPin(KEYPAD_PORT, ROW1_PIN);
                  if(value == GPIO_LOW){

                     pressedKey=BUTTON2;

                  }

           	   break;
       case BUTTON3:
                  GPIO_InitPin(KEYPAD_PORT,ROW1_PIN, GPIO_INPUT);
                  Control_Pull_Up(KEYPAD_PORT,ROW1_PIN , GPIO_HIGH);

                  GPIO_InitPin(KEYPAD_PORT,COL1_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(KEYPAD_PORT, COL1_PIN, GPIO_HIGH);
                  GPIO_InitPin(COL2_PORT,COL2_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(COL2_PORT, COL2_PIN, GPIO_HIGH);
                  GPIO_InitPin(KEYPAD_PORT,COL3_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(KEYPAD_PORT, COL3_PIN, GPIO_LOW);
                  GPIO_InitPin(KEYPAD_PORT,COL4_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(KEYPAD_PORT, COL4_PIN, GPIO_HIGH);

                  value =GPIO_GetPin(KEYPAD_PORT, ROW1_PIN);
                  if(value == GPIO_LOW){

                     pressedKey=BUTTON3;

                  }

           	   break;
       case BUTTON4:
                  GPIO_InitPin(KEYPAD_PORT,ROW1_PIN, GPIO_INPUT);
                  Control_Pull_Up(KEYPAD_PORT,ROW1_PIN , GPIO_HIGH);

                  GPIO_InitPin(KEYPAD_PORT,COL1_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(KEYPAD_PORT, COL1_PIN, GPIO_HIGH);
                  GPIO_InitPin(COL2_PORT,COL2_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(COL2_PORT, COL2_PIN, GPIO_HIGH);
                  GPIO_InitPin(KEYPAD_PORT,COL3_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(KEYPAD_PORT, COL3_PIN, GPIO_HIGH);
                  GPIO_InitPin(KEYPAD_PORT,COL4_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(KEYPAD_PORT, COL4_PIN, GPIO_LOW);

                  value =GPIO_GetPin(KEYPAD_PORT, ROW1_PIN);
                  if(value == GPIO_LOW){

                             pressedKey=BUTTON4;

                             }

           	   break;
       case BUTTON5:
                  GPIO_InitPin(KEYPAD_PORT,ROW2_PIN, GPIO_INPUT);
                  Control_Pull_Up(KEYPAD_PORT,ROW2_PIN , GPIO_HIGH);

                  GPIO_InitPin(KEYPAD_PORT,COL1_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(KEYPAD_PORT, COL1_PIN, GPIO_LOW);
                  GPIO_InitPin(COL2_PORT,COL2_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(COL2_PORT, COL2_PIN, GPIO_HIGH);
                  GPIO_InitPin(KEYPAD_PORT,COL3_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(KEYPAD_PORT, COL3_PIN, GPIO_HIGH);
                  GPIO_InitPin(KEYPAD_PORT,COL4_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(KEYPAD_PORT, COL4_PIN, GPIO_HIGH);

                  value =GPIO_GetPin(KEYPAD_PORT, ROW2_PIN);
                  if(value == GPIO_LOW){

                      pressedKey=BUTTON5;

                  }

           	   break;
       case BUTTON6:
                  GPIO_InitPin(KEYPAD_PORT,ROW2_PIN, GPIO_INPUT);
                  Control_Pull_Up(KEYPAD_PORT,ROW2_PIN , GPIO_HIGH);


                  GPIO_InitPin(KEYPAD_PORT,COL1_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(KEYPAD_PORT, COL1_PIN, GPIO_HIGH);
                  GPIO_InitPin(COL2_PORT,COL2_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(COL2_PORT, COL2_PIN, GPIO_LOW);
                  GPIO_InitPin(KEYPAD_PORT,COL3_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(KEYPAD_PORT, COL3_PIN, GPIO_HIGH);
                  GPIO_InitPin(KEYPAD_PORT,COL4_PIN, GPIO_OUTPUT);
                  GPIO_WritePin(KEYPAD_PORT, COL4_PIN, GPIO_HIGH);

                  value =GPIO_GetPin(KEYPAD_PORT, ROW2_PIN);
                  if(value == GPIO_LOW){

                     pressedKey=BUTTON6;

                  }

           	   break;
       case BUTTON7:
                        GPIO_InitPin(KEYPAD_PORT,ROW2_PIN, GPIO_INPUT);
                        Control_Pull_Up(KEYPAD_PORT,ROW2_PIN , GPIO_HIGH);

                        GPIO_InitPin(KEYPAD_PORT,COL1_PIN, GPIO_OUTPUT);
                        GPIO_WritePin(KEYPAD_PORT, COL1_PIN, GPIO_HIGH);
                        GPIO_InitPin(COL2_PORT,COL2_PIN, GPIO_OUTPUT);
                        GPIO_WritePin(COL2_PORT, COL2_PIN, GPIO_HIGH);
                        GPIO_InitPin(KEYPAD_PORT,COL3_PIN, GPIO_OUTPUT);
                        GPIO_WritePin(KEYPAD_PORT, COL3_PIN, GPIO_LOW);
                        GPIO_InitPin(KEYPAD_PORT,COL4_PIN, GPIO_OUTPUT);
                        GPIO_WritePin(KEYPAD_PORT, COL4_PIN, GPIO_HIGH);

                        value =GPIO_GetPin(KEYPAD_PORT, ROW2_PIN);
                        if(value ==GPIO_LOW){

                            pressedKey=BUTTON7;

                        }

                 	   break;
       case BUTTON8:
                        GPIO_InitPin(KEYPAD_PORT,ROW2_PIN, GPIO_INPUT);
                        Control_Pull_Up(KEYPAD_PORT,ROW2_PIN , GPIO_HIGH);

                        GPIO_InitPin(KEYPAD_PORT,COL1_PIN, GPIO_OUTPUT);
                        GPIO_WritePin(KEYPAD_PORT, COL1_PIN, GPIO_HIGH);
                        GPIO_InitPin(COL2_PORT,COL2_PIN, GPIO_OUTPUT);
                        GPIO_WritePin(COL2_PORT, COL2_PIN, GPIO_HIGH);
                        GPIO_InitPin(KEYPAD_PORT,COL3_PIN, GPIO_OUTPUT);
                        GPIO_WritePin(KEYPAD_PORT, COL3_PIN, GPIO_HIGH);
                        GPIO_InitPin(KEYPAD_PORT,COL4_PIN, GPIO_OUTPUT);
                        GPIO_WritePin(KEYPAD_PORT, COL4_PIN, GPIO_LOW);

                        value =GPIO_GetPin(KEYPAD_PORT, ROW2_PIN);
                        if(value == GPIO_LOW){

                              pressedKey=BUTTON8;

                        }

                 	   break;
       case BUTTON9:
                         GPIO_InitPin(KEYPAD_PORT,ROW3_PIN, GPIO_INPUT);
                         Control_Pull_Up(KEYPAD_PORT,ROW3_PIN , GPIO_HIGH);

                         GPIO_InitPin(KEYPAD_PORT,COL1_PIN, GPIO_OUTPUT);
                         GPIO_WritePin(KEYPAD_PORT, COL1_PIN, GPIO_LOW);
                         GPIO_InitPin(COL2_PORT,COL2_PIN, GPIO_OUTPUT);
                         GPIO_WritePin(COL2_PORT, COL2_PIN, GPIO_HIGH);
                         GPIO_InitPin(KEYPAD_PORT,COL3_PIN, GPIO_OUTPUT);
                         GPIO_WritePin(KEYPAD_PORT, COL3_PIN, GPIO_HIGH);
                         GPIO_InitPin(KEYPAD_PORT,COL4_PIN, GPIO_OUTPUT);
                         GPIO_WritePin(KEYPAD_PORT, COL4_PIN, GPIO_HIGH);

                         value =GPIO_GetPin(KEYPAD_PORT, ROW3_PIN);
                         if(value ==GPIO_LOW){

                             pressedKey=BUTTON9;

                         }

                  	   break;
       case BUTTON10:
                                GPIO_InitPin(KEYPAD_PORT,ROW3_PIN, GPIO_INPUT);
                                Control_Pull_Up(KEYPAD_PORT,ROW3_PIN , GPIO_HIGH);


                                GPIO_InitPin(KEYPAD_PORT,COL1_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL1_PIN, GPIO_HIGH);
                                GPIO_InitPin(COL2_PORT,COL2_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(COL2_PORT, COL2_PIN, GPIO_LOW);
                                GPIO_InitPin(KEYPAD_PORT,COL3_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL3_PIN, GPIO_HIGH);
                                GPIO_InitPin(KEYPAD_PORT,COL4_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL4_PIN, GPIO_HIGH);

                                value =GPIO_GetPin(KEYPAD_PORT, ROW3_PIN);

                                if(value ==GPIO_LOW){

                                     pressedKey=BUTTON10;

                                }

                         	   break;
       case BUTTON11:
                                GPIO_InitPin(KEYPAD_PORT,ROW3_PIN, GPIO_INPUT);
                                Control_Pull_Up(KEYPAD_PORT,ROW3_PIN , GPIO_HIGH);


                                GPIO_InitPin(KEYPAD_PORT,COL1_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL1_PIN, GPIO_HIGH);
                                GPIO_InitPin(COL2_PORT,COL2_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(COL2_PORT, COL2_PIN, GPIO_HIGH);
                                GPIO_InitPin(KEYPAD_PORT,COL3_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL3_PIN, GPIO_LOW);
                                GPIO_InitPin(KEYPAD_PORT,COL4_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL4_PIN, GPIO_HIGH);

                                value =GPIO_GetPin(KEYPAD_PORT, ROW3_PIN);

                                if(value == GPIO_LOW){

                                     pressedKey=BUTTON11;

                                }

                         	   break;
       case BUTTON12:
                                GPIO_InitPin(KEYPAD_PORT,ROW3_PIN, GPIO_INPUT);
                                Control_Pull_Up(KEYPAD_PORT,ROW3_PIN , GPIO_HIGH);


                                GPIO_InitPin(KEYPAD_PORT,COL1_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL1_PIN, GPIO_HIGH);
                                GPIO_InitPin(COL2_PORT,COL2_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(COL2_PORT, COL2_PIN, GPIO_HIGH);
                                GPIO_InitPin(KEYPAD_PORT,COL3_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL3_PIN, GPIO_HIGH);
                                GPIO_InitPin(KEYPAD_PORT,COL4_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL4_PIN, GPIO_LOW);

                                value =GPIO_GetPin(KEYPAD_PORT, ROW3_PIN);
                                if(value ==GPIO_LOW){

                                   pressedKey=BUTTON12;

                                }

                         	   break;
       case BUTTON13:
                                GPIO_InitPin(KEYPAD_PORT,ROW4_PIN, GPIO_INPUT);
                                Control_Pull_Up(KEYPAD_PORT,ROW4_PIN , GPIO_HIGH);


                                GPIO_InitPin(KEYPAD_PORT,COL1_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL1_PIN, GPIO_LOW);
                                GPIO_InitPin(COL2_PORT,COL2_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(COL2_PORT, COL2_PIN, GPIO_HIGH);
                                GPIO_InitPin(KEYPAD_PORT,COL3_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL3_PIN, GPIO_HIGH);
                                GPIO_InitPin(KEYPAD_PORT,COL4_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL4_PIN, GPIO_HIGH);

                                value =GPIO_GetPin(KEYPAD_PORT, ROW4_PIN);
                                if(value == GPIO_LOW){

                                     pressedKey=BUTTON13;

                                }

                         	   break;
       case BUTTON14:
                                GPIO_InitPin(KEYPAD_PORT,ROW4_PIN, GPIO_INPUT);
                                Control_Pull_Up(KEYPAD_PORT,ROW4_PIN , GPIO_HIGH);


                                GPIO_InitPin(KEYPAD_PORT,COL1_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL1_PIN, GPIO_HIGH);
                                GPIO_InitPin(COL2_PORT,COL2_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(COL2_PORT, COL2_PIN, GPIO_LOW);
                                GPIO_InitPin(KEYPAD_PORT,COL3_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL3_PIN, GPIO_HIGH);
                                GPIO_InitPin(KEYPAD_PORT,COL4_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL4_PIN, GPIO_HIGH);

                                value =GPIO_GetPin(KEYPAD_PORT, ROW4_PIN);
                                if(value == GPIO_LOW){

                                      pressedKey=BUTTON14;

                                 }

                         	   break;
       case BUTTON15:
                                GPIO_InitPin(KEYPAD_PORT,ROW4_PIN, GPIO_INPUT);
                                Control_Pull_Up(KEYPAD_PORT,ROW4_PIN , GPIO_HIGH);


                                GPIO_InitPin(KEYPAD_PORT,COL1_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL1_PIN, GPIO_HIGH);
                                GPIO_InitPin(COL2_PORT,COL2_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(COL2_PORT, COL2_PIN, GPIO_HIGH);
                                GPIO_InitPin(KEYPAD_PORT,COL3_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL3_PIN, GPIO_LOW);
                                GPIO_InitPin(KEYPAD_PORT,COL4_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL4_PIN, GPIO_HIGH);

                                value =GPIO_GetPin(KEYPAD_PORT, ROW4_PIN);
                                if(value == GPIO_LOW){

                                           pressedKey=BUTTON15;

                                }

                         	   break;
       case BUTTON16:
                                GPIO_InitPin(KEYPAD_PORT,ROW4_PIN, GPIO_INPUT);
                                Control_Pull_Up(KEYPAD_PORT,ROW4_PIN , GPIO_HIGH);


                                GPIO_InitPin(KEYPAD_PORT,COL1_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL1_PIN, GPIO_HIGH);
                                GPIO_InitPin(COL2_PORT,COL2_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(COL2_PORT, COL2_PIN, GPIO_HIGH);
                                GPIO_InitPin(KEYPAD_PORT,COL3_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL3_PIN, GPIO_HIGH);
                                GPIO_InitPin(KEYPAD_PORT,COL4_PIN, GPIO_OUTPUT);
                                GPIO_WritePin(KEYPAD_PORT, COL4_PIN, GPIO_LOW);

                                value =GPIO_GetPin(KEYPAD_PORT, ROW4_PIN);
                                if(value == GPIO_LOW){

                                           pressedKey=BUTTON16;

                                }

                         	   break;



    }
	return pressedKey;
}
