/*
 * Seven_seg.h
 *
 *  Created on: Mar 28, 2020
 *      Author: CR0LL0
 */

#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include"gpio.h"

typedef struct SevenSeg_str {
	DIO_str_pin_t pin_struct[8];
	u8 value;
} SevenSeg_str_t;


DIO_errorState_t DIO_enuInitSevenSeg(SevenSeg_str_t *);
DIO_errorState_t DIO_enuSetSevenSegValue(SevenSeg_str_t*);
DIO_errorState_t DIO_enuClearSevenSeg(SevenSeg_str_t*);




#endif /* SEVEN_SEG_H_ */
