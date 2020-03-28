/*
 * Seven_seg.c
 *
 *  Created on: Mar 28, 2020
 *      Author: CR0LL0
 */

#include"gpio.h"
#include "BIT_MATH.h"

#include "Seven_seg.h"

DIO_errorState_t DIO_enuInitSevenSeg(SevenSeg_str_t * sev) {

	DIO_errorState_t err = NOT_OK;

	sev->pin_struct[0].state_t = OUTPUT;
	sev->pin_struct[1].state_t = OUTPUT;
	sev->pin_struct[2].state_t = OUTPUT;
	sev->pin_struct[3].state_t = OUTPUT;
	sev->pin_struct[4].state_t = OUTPUT;
	sev->pin_struct[5].state_t = OUTPUT;
	sev->pin_struct[6].state_t = OUTPUT;
	sev->pin_struct[7].state_t = OUTPUT;

	DIO_enuInitPin(&sev->pin_struct[0]);
	DIO_enuInitPin(&sev->pin_struct[1]);
	DIO_enuInitPin(&sev->pin_struct[2]);
	DIO_enuInitPin(&sev->pin_struct[3]);
	DIO_enuInitPin(&sev->pin_struct[4]);
	DIO_enuInitPin(&sev->pin_struct[5]);
	DIO_enuInitPin(&sev->pin_struct[6]);
//	DIO_enuInitPin(&sev->pin_struct[7]);

	err = OK;
	return err;
}

DIO_errorState_t DIO_enuSetSevenSegValue(SevenSeg_str_t *sev) {
	DIO_errorState_t err;
	err = NOT_OK;

	int value = sev->value;

	for (int i = 0; i < 7; i++)
		sev->pin_struct[i].val_t = ((value >> i) & 1);

	DIO_enuSetPin(&sev->pin_struct[0]);
	DIO_enuSetPin(&sev->pin_struct[1]);
	DIO_enuSetPin(&sev->pin_struct[2]);
	DIO_enuSetPin(&sev->pin_struct[3]);
	DIO_enuSetPin(&sev->pin_struct[4]);
	DIO_enuSetPin(&sev->pin_struct[5]);
	DIO_enuSetPin(&sev->pin_struct[6]);
	//DIO_enuSetPin(&sev->pin_struct[7]);

	err = OK;
	return err;

}
DIO_errorState_t DIO_enuClearSevenSeg(SevenSeg_str_t* sev) {

	DIO_errorState_t err;
	err = NOT_OK;


	DIO_enuClearPin(&sev->pin_struct[0]);
	DIO_enuClearPin(&sev->pin_struct[1]);
	DIO_enuClearPin(&sev->pin_struct[2]);
	DIO_enuClearPin(&sev->pin_struct[3]);
	DIO_enuClearPin(&sev->pin_struct[4]);
	DIO_enuClearPin(&sev->pin_struct[5]);
	DIO_enuClearPin(&sev->pin_struct[6]);
	DIO_enuClearPin(&sev->pin_struct[7]);


	//DIO_enuSetPin(&sev->pin_struct[7]);

	err = OK;
	return err;

}
