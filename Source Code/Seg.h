/*
 * Seg.h
 *
 *  Created on: Oct 2, 2021
 *      Author: LENOVO
 */

#ifndef SEG_H_
#define SEG_H_

/*typedef enum{
	seg1,seg2,seg3,seg4
} en_segNumber ;*/

#define SEG1 1
#define SEG2 2
#define SEG3 3
#define SEG4 4

#define SEGA_PORT GPIO_B
#define SEGB_PORT GPIO_B
#define SEGC_PORT GPIO_B
#define SEGD_PORT GPIO_B

#define SEGA_PIN GPIO_PIN0
#define SEGB_PIN GPIO_PIN1
#define SEGC_PIN GPIO_PIN2
#define SEGD_PIN GPIO_PIN4

#define EN1_PORT GPIO_A
#define EN2_PORT GPIO_A
#define EN3_PORT GPIO_B
#define EN4_PORT GPIO_B

#define EN1_PIN GPIO_PIN3
#define EN2_PIN GPIO_PIN2
#define EN3_PIN GPIO_PIN5
#define EN4_PIN GPIO_PIN6

#define FIRST_HALF    1
#define SECOND_HALF   2


void Seg_Init(unit8 segNo);
void Seg_Write(unit8 segNo, unit8 value);
void Seg_WriteSeq(sint16 fullValue,unit8 segBegininng);
void Seg_DeInit(unit8 segNo);


#endif /* SEG_H_ */
