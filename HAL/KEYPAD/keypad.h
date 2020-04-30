/*
 * keypad.h
 *
 *  Created on: Mar 31, 2020
 *      Author: CR0LL0
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include"../../MCAL/GPIO/Inc/gpio.h"
//#include<util/delay.h>

#define COL 3
#define ROW 4

typedef struct keypad{
	DIO_str_pin_t  pin_str;
	u8 row_no;
	u8 col_no;
	u8 col_port[COL];
	u8 row_port[ROW];
	u8 col_pin[COL];
	u8 row_pin[ROW];
	u8 val;
	u8 keypad[ROW][COL];
	int switch_p;
}keypad_t;



DIO_errorState_t init_keypad(keypad_t *keypadx);
DIO_errorState_t keypad_scan(keypad_t *keypadx);


#endif /* KEYPAD_H_ */
