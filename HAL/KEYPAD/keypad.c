/*
 * keypad.c
 *
 *  Created on: Mar 31, 2020
 *      Author: CR0LL0
 */

#include"../../MCAL/GPIO/Inc/gpio.h"
#include "../../MCAL/GPIO/Inc/hw_gpio.h"
#include"keypad.h"
#include<util/delay.h>

DIO_errorState_t init_keypad(keypad_t *keypadx) {
	DIO_errorState_t error = NOT_OK;

	keypadx->pin_str.state_t = INPUT;
	keypadx->pin_str.input_res = 1;
	for (int i = 0; i < ROW; i++) {
		keypadx->pin_str.port_t = keypadx->row_port[i];
		keypadx->pin_str.pin_t = keypadx->row_pin[i];
		DIO_enuInitPin(&(keypadx->pin_str));
	}

	keypadx->pin_str.state_t = OUTPUT;
	for (int i = 0; i < COL; i++) {
		keypadx->pin_str.port_t = keypadx->col_port[i];
		keypadx->pin_str.pin_t = keypadx->col_pin[i];
		DIO_enuInitPin(&keypadx->pin_str);
	}
	error = OK;
	return error;
}

DIO_errorState_t keypad_scan(keypad_t *keypadx) {
	DIO_errorState_t error = NOT_OK;
	int row;
	int col;
		for (col = 0; col < COL; col++) {
			keypadx->pin_str.port_t = keypadx->col_port[col];
			keypadx->pin_str.pin_t = keypadx->col_pin[col];
			keypadx->pin_str.state_t = OUTPUT;
			keypadx->pin_str.val_t = 0;
			DIO_enuSetPin(&keypadx->pin_str);
			for (row = 0; row < ROW; row++) {
				keypadx->pin_str.port_t = keypadx->row_port[row];
				keypadx->pin_str.pin_t = keypadx->row_pin[row];
				DIO_enuGetPin(&keypadx->pin_str);
				if (keypadx->pin_str.val_t == 0) {
					keypadx->switch_p = keypadx->keypad[row][col];
					while (keypadx->pin_str.val_t == 0){
					DIO_enuGetPin(&keypadx->pin_str);
					}
					return error;
				}
			}
			keypadx->pin_str.port_t = keypadx->col_port[col];
			keypadx->pin_str.pin_t = keypadx->col_pin[col];
			keypadx->pin_str.state_t = OUTPUT;
			keypadx->pin_str.val_t = 1;
			DIO_enuSetPin(&keypadx->pin_str);
			keypadx->switch_p = 10;
		}
	return error;
}

/*
 while (1) {
 keypadx->pin_str.val_t = LOW;
 for (row = 0; row < ROW; row++) {
 keypadx->pin_str.port_t = keypadx->row_port[row];
 keypadx->pin_str.pin_t = keypadx->row_pin[row];
 DIO_enuGetPin(&keypadx->pin_str);
 for (col = 0; col < COL; col++) {
 keypadx->pin_str.port_t = keypadx->col_port[col];
 keypadx->pin_str.pin_t = keypadx->col_pin[col];
 DIO_enuGetPin(&keypadx->pin_str);
 if (keypadx->pin_str.val_t == 0) {
 keypadx->pin_str.port_t = keypadx->row_port[row];
 keypadx->pin_str.pin_t = keypadx->row_pin[row];
 keypadx->pin_str.val_t = HIGH;
 DIO_enuSetPin(&(keypadx->pin_str));
 DIO_enuGetPin(&keypadx->pin_str);
 keypadx->switch_p = keypadx->keypad[row][col];
 _delay_ms(300);
 return error;
 }
 }
 keypadx->pin_str.port_t = keypadx->row_port[row];
 keypadx->pin_str.pin_t = keypadx->row_pin[row];
 DIO_enuSetPin(&(keypadx->pin_str));
 }
 }
 }
 * */
/*
 DIO_errorState_t error = NOT_OK;
 int row;
 int col;
 keypad_t keypady;
 keypady.pin_str.state_t=OUTPUT;
 for (row = 0; row < ROW; row++) {
 keypady.pin_str.val_t=HIGH;
 keypady.pin_str.port_t = keypadx->row_port[row];
 keypady.pin_str.pin_t = keypadx->row_pin[row];
 DIO_enuSetPin(&keypady.pin_str);
 //_delay_ms(100);
 for (col = 0; col < COL; col++) {
 keypadx->pin_str.port_t = keypadx->col_port[col];
 keypadx->pin_str.pin_t = keypadx->col_pin[col];
 DIO_enuGetPin(&keypadx->pin_str);
 if (keypadx->pin_str.val_t == 0 && keypady.pin_str.val_t==1) {
 //DIO_enuGetPin(&keypadx->pin_str);
 keypadx->switch_p = keypadx->keypad[row][col];
 _delay_ms(20);
 return error;
 }
 }
 keypady.pin_str.val_t=LOW;
 DIO_enuSetPin(&(keypady.pin_str));
 }
 keypadx->switch_p = 10;
 return error;
 }
 */
