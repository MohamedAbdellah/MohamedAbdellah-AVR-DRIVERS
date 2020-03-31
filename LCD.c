/*
 * LCD.c
 *
 *  Created on: Mar 28, 2020
 *      Author: CR0LL0
 */

#include"gpio.h"
#include"LCD.h"
#include<util/delay.h>

DIO_errorState_t LCD_enuInitLcd(LCD_str_t *lcd) {

	DIO_errorState_t error = NOT_OK;
	_delay_ms(30);

	if (lcd->bit_mode == LCD_8BitMode) {

		lcd->lcd_data_pin_struct[0].state_t = OUTPUT;
		lcd->lcd_data_pin_struct[1].state_t = OUTPUT;
		lcd->lcd_data_pin_struct[2].state_t = OUTPUT;
		lcd->lcd_data_pin_struct[3].state_t = OUTPUT;
		lcd->lcd_data_pin_struct[4].state_t = OUTPUT;
		lcd->lcd_data_pin_struct[5].state_t = OUTPUT;
		lcd->lcd_data_pin_struct[6].state_t = OUTPUT;
		lcd->lcd_data_pin_struct[7].state_t = OUTPUT;

		lcd->lcd_cmd_pin_struct[0].state_t = OUTPUT;
		lcd->lcd_cmd_pin_struct[1].state_t = OUTPUT;
		lcd->lcd_cmd_pin_struct[2].state_t = OUTPUT;

		DIO_enuInitPin(&lcd->lcd_data_pin_struct[0]);
		DIO_enuInitPin(&lcd->lcd_data_pin_struct[1]);
		DIO_enuInitPin(&lcd->lcd_data_pin_struct[2]);
		DIO_enuInitPin(&lcd->lcd_data_pin_struct[3]);
		DIO_enuInitPin(&lcd->lcd_data_pin_struct[4]);
		DIO_enuInitPin(&lcd->lcd_data_pin_struct[5]);
		DIO_enuInitPin(&lcd->lcd_data_pin_struct[6]);
		DIO_enuInitPin(&lcd->lcd_data_pin_struct[7]);

		DIO_enuInitPin(&lcd->lcd_cmd_pin_struct[0]);
		DIO_enuInitPin(&lcd->lcd_cmd_pin_struct[1]);
		DIO_enuInitPin(&lcd->lcd_cmd_pin_struct[2]);

		lcd->lcd_cmd = lcd_Function8bitMode;
		//LCD_enuClearLCDcmd(lcd) ;
		LCD_enuWriteCMDLcd(lcd);
	}

	lcd->lcd_cmd = lcd_DisplayOn;

	//LCD_enuClearLCDcmd(lcd) ;
	LCD_enuWriteCMDLcd(lcd);

	lcd->lcd_cmd = lcd_Clear;

	//LCD_enuClearLCDcmd(lcd) ;
	LCD_enuWriteCMDLcd(lcd);

	return error;
}

DIO_errorState_t LCD_enuWriteCMDLcd(LCD_str_t *lcd) {
	DIO_errorState_t error = NOT_OK;

	//0->RS, 1->RW, 2->E

	/* Instruction Mode RS=0 */
	lcd->lcd_cmd_pin_struct[0].val_t = 0;
	DIO_enuSetPin(&lcd->lcd_cmd_pin_struct[0]);

	/* Instruction Mode RW=0 */
	lcd->lcd_cmd_pin_struct[1].val_t = 0;
	DIO_enuSetPin(&lcd->lcd_cmd_pin_struct[1]);
	_delay_ms(1);

	/* Instruction Mode E=1 */
	lcd->lcd_cmd_pin_struct[2].val_t = 1;
	DIO_enuSetPin(&lcd->lcd_cmd_pin_struct[2]);
	_delay_ms(1);

	int value = lcd->lcd_cmd;

	//LCD_enuClearLCDdata(lcd);

	for (int i = 0; i < 8; i++) {
		lcd->lcd_data_pin_struct[i].val_t = ((value >> i) & 1);
		DIO_enuSetPin(&lcd->lcd_data_pin_struct[i]);
	}

	_delay_ms(1);

	/* Instruction Mode E=0 */
	lcd->lcd_cmd_pin_struct[2].val_t = 0;
	DIO_enuSetPin(&lcd->lcd_cmd_pin_struct[2]);
	_delay_ms(1);

	return error;
}

DIO_errorState_t LCD_enuWriteDataLcd(LCD_str_t * lcd) {
	DIO_errorState_t error = NOT_OK;

	//0->RS, 1->RW, 2->E

	/* Instruction Mode RS=1 */
	lcd->lcd_cmd_pin_struct[0].val_t = 1;
	DIO_enuSetPin(&lcd->lcd_cmd_pin_struct[0]);

	/* Instruction Mode RW=0 */
	lcd->lcd_cmd_pin_struct[1].val_t = 0;
	DIO_enuSetPin(&lcd->lcd_cmd_pin_struct[1]);
	_delay_ms(1);

	/* Instruction Mode E=1 */
	lcd->lcd_cmd_pin_struct[2].val_t = 1;
	DIO_enuSetPin(&lcd->lcd_cmd_pin_struct[2]);
	_delay_ms(1);

	//LCD_enuClearLCDdata(lcd);

	int value = lcd->value;

	for (int i = 0; i < 8; i++) {
		lcd->lcd_data_pin_struct[i].val_t = ((value >> i) & 1);
	}

	DIO_enuSetPin(&lcd->lcd_data_pin_struct[0]);
	DIO_enuSetPin(&lcd->lcd_data_pin_struct[1]);
	DIO_enuSetPin(&lcd->lcd_data_pin_struct[2]);
	DIO_enuSetPin(&lcd->lcd_data_pin_struct[3]);
	DIO_enuSetPin(&lcd->lcd_data_pin_struct[4]);
	DIO_enuSetPin(&lcd->lcd_data_pin_struct[5]);
	DIO_enuSetPin(&lcd->lcd_data_pin_struct[6]);
	DIO_enuSetPin(&lcd->lcd_data_pin_struct[7]);

	_delay_ms(1);

	/* Instruction Mode E=1 */
	lcd->lcd_cmd_pin_struct[2].val_t = 0;
	DIO_enuSetPin(&lcd->lcd_cmd_pin_struct[2]);
	_delay_ms(1);
	return error;
}
/*
 DIO_errorState_t LCD_enuClearLCDdata(LCD_str_t* lcd){
 DIO_errorState_t err;
 err = NOT_OK;

 DIO_enuClearPin(&lcd->lcd_data_pin_struct[0]);
 DIO_enuClearPin(&lcd->lcd_data_pin_struct[1]);
 DIO_enuClearPin(&lcd->lcd_data_pin_struct[2]);
 DIO_enuClearPin(&lcd->lcd_data_pin_struct[3]);
 DIO_enuClearPin(&lcd->lcd_data_pin_struct[4]);
 DIO_enuClearPin(&lcd->lcd_data_pin_struct[5]);
 DIO_enuClearPin(&lcd->lcd_data_pin_struct[6]);
 DIO_enuClearPin(&lcd->lcd_data_pin_struct[7]);

 err = OK;
 return err;
 }


 DIO_errorState_t LCD_enuClearLCDcmd(LCD_str_t* lcd){

 DIO_errorState_t err;
 err = NOT_OK;

 DIO_enuClearPin(&lcd->lcd_cmd_pin_struct[0]);
 DIO_enuClearPin(&lcd->lcd_cmd_pin_struct[1]);
 DIO_enuClearPin(&lcd->lcd_cmd_pin_struct[2]);

 err = OK;
 return err;

 }
 */

DIO_errorState_t LCD_GOTO(LCD_str_t *lcd) {
	DIO_errorState_t error = NOT_OK;

	if (lcd->row == 0) {
		lcd->lcd_cmd = 0x80 | lcd->col;
		LCD_enuWriteCMDLcd(lcd);
	}

	else {
		lcd->lcd_cmd = 0xC0 | lcd->col;
		LCD_enuWriteCMDLcd(lcd);
	}

	//lcd->lcd_cmd = lcd->col;
	//LCD_enuWriteCMDLcd(lcd);
	error = OK;
	return error;
}

DIO_errorState_t LCD_enuWriteStringLcd(LCD_str_t *lcd) {

	DIO_errorState_t error = NOT_OK;

	int i=0,value=0;
	for (i = 0; lcd->str[i] != 0; i++){
		value = (u8)(lcd->str[i]);
	/* Instruction Mode RS=1 */
	lcd->lcd_cmd_pin_struct[0].val_t = 1;
	DIO_enuSetPin(&lcd->lcd_cmd_pin_struct[0]);

	/* Instruction Mode RW=0 */
	lcd->lcd_cmd_pin_struct[1].val_t = 0;
	DIO_enuSetPin(&lcd->lcd_cmd_pin_struct[1]);
	_delay_ms(1);

	/* Instruction Mode E=1 */
	lcd->lcd_cmd_pin_struct[2].val_t = 1;
	DIO_enuSetPin(&lcd->lcd_cmd_pin_struct[2]);
	_delay_ms(1);

	//LCD_enuClearLCDdata(lcd);

	for (int i = 0; i < 8; i++) {
		lcd->lcd_data_pin_struct[i].val_t = ((value >> i) & 1);
	}

	DIO_enuSetPin(&lcd->lcd_data_pin_struct[0]);
	DIO_enuSetPin(&lcd->lcd_data_pin_struct[1]);
	DIO_enuSetPin(&lcd->lcd_data_pin_struct[2]);
	DIO_enuSetPin(&lcd->lcd_data_pin_struct[3]);
	DIO_enuSetPin(&lcd->lcd_data_pin_struct[4]);
	DIO_enuSetPin(&lcd->lcd_data_pin_struct[5]);
	DIO_enuSetPin(&lcd->lcd_data_pin_struct[6]);
	DIO_enuSetPin(&lcd->lcd_data_pin_struct[7]);

	_delay_ms(1);

	/* Instruction Mode E=1 */
	lcd->lcd_cmd_pin_struct[2].val_t = 0;
	DIO_enuSetPin(&lcd->lcd_cmd_pin_struct[2]);
	_delay_ms(1);
}
error = OK;
return error;
}
DIO_errorState_t LCD_enuWriteSineString(LCD_str_t *lcd){

	DIO_errorState_t error = NOT_OK;

	lcd->row=0;
	lcd->col=0;
	lcd->value='M';
	LCD_GOTO(lcd);
	LCD_enuWriteDataLcd(lcd);
	//lcd->lcd_cmd=
	//LCD_enuWriteCMDLcd
	lcd->row=1;
	lcd->col=8;
	lcd->value='o';
	LCD_GOTO(lcd);
	LCD_enuWriteDataLcd(lcd);

	lcd->row=0;
	lcd->col=15;
	lcd->value='H';
	LCD_GOTO(lcd);
	LCD_enuWriteDataLcd(lcd);



	error = OK;
	return error;
}
