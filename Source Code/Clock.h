/*
 * Clock.h
 *
 *  Created on: Oct 6, 2021
 *      Author: LENOVO
 */

#ifndef CLOCK_H_
#define CLOCK_H_

void Clock();
void MinutesDisplay(unit8 *minutes);
void HoursDisplay(unit8 *hours);
void Clock_editMode();
void Clock_IncreaseMinutes();
void Clock_DecreaseMinutes();
void Clock_IncreaseHours();
void Clock_DecreaseHours();

#endif /* CLOCK_H_ */
