/*
 * Seven_seg.h
 *
 *  Created on: Mar 28, 2020
 *      Author: CR0LL0
 */

#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include"../../MCAL/GPIO/Inc/gpio.h"

typedef enum SevSeg_enm_state {
	CMCATH = 0, CMANODE = 1
} SevSeg_enm_state_t;

typedef struct SevenSeg_str {
	DIO_str_pin_t pin_struct[8];
	u8 value;
	DIO_str_pin_t enable;
} SevenSeg_str_t;

DIO_errorState_t SevSeg_enuInitSevenSeg(SevenSeg_str_t *);
DIO_errorState_t SevSeg_enuSetSevenSegValue(SevenSeg_str_t*);
DIO_errorState_t SevSeg_enuClearSevenSeg(SevenSeg_str_t*);
DIO_errorState_t SevSeg_enuWriteSevenSegEnablebit(SevenSeg_str_t*);
DIO_errorState_t SevSeg_enuClearSevenSegEnablebit(SevenSeg_str_t*);


#endif /* SEVEN_SEG_H_ */
