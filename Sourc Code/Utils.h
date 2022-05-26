/*
 * Utils.h
 *
 *  Created on: Sep 25, 2021
 *      Author: LENOVO
 */

#ifndef UTILS_H_
#define UTILS_H_

#define SET_BIT(REG,INDEX)	 (REG|=(1<<(INDEX)))
#define CLEAR_BIT(REG,INDEX) (REG&=~(1<<(INDEX)))
#define GET_BIT(REG,INDEX)	  ((REG>>INDEX)&0x01)
#define Toggle_BIT(REG,INDEX) (REG^=(0x01<<INDEX))

#endif /* UTILS_H_ */
