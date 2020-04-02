/*
 * main.c
 *
 *  Created on: Mar 26, 2020
 *      Author: CR0LL01
 */
#include"STD_types.h"
#include"hw_gpio.h"
#include"gpio_error.h"
#include"gpio.h"
#include<util/delay.h>
#include "Seven_seg.h"
#include "LCD.h"
#include "keypad.h"

int main() {

//#define LED
#ifdef LED
	DIO_str_pin_t led1;
	// DIO_str_pin_t swit;

	led1.pin_t = 1;
	led1.port_t = DIO_OFFSET_A;
	led1.state_t = OUTPUT;
	led1.val_t = 1;

	DIO_enuInitPin(&led1);

	DIO_enuSetPin(&led1);

#endif

	/*
	 DIO_str_pin_t led2;

	 led2.pin_t = 0;
	 led2.port_t = PORTB;
	 led2.state_t = OUTPUT;
	 led2.val_t = 1;

	 DIO_str_pin_t led3;

	 led3.pin_t = 0;
	 led3.port_t = PORTC;
	 led3.state_t = OUTPUT;
	 led3.val_t = 1;

	 DIO_str_pin_t led4;

	 led4.pin_t = 0;
	 led4.port_t = PORTD;
	 led4.state_t = OUTPUT;
	 led4.val_t = 1;

	 swit.pin_t = 1;
	 swit.port_t = PORT_A;
	 swit.state_t = INPUT;
	 //swit.input_res=1;

	 DIO_enuInitPin(&led1);

	 DIO_enuInitPin(&led2);

	 DIO_enuInitPin(&led3);

	 DIO_enuInitPin(&led4);

	 while (1) {

	 DIO_enuSetPin(&led1);
	 _delay_ms(350);
	 DIO_enuClearPin(&led1);
	 _delay_ms(350);

	 DIO_enuSetPin(&led2);
	 _delay_ms(350);
	 DIO_enuClearPin(&led2);
	 _delay_ms(350);

	 DIO_enuSetPin(&led3);
	 _delay_ms(350);
	 DIO_enuClearPin(&led3);
	 _delay_ms(350);

	 DIO_enuSetPin(&led4);
	 _delay_ms(350);
	 DIO_enuClearPin(&led4);
	 _delay_ms(350);

	 DIO_enuTogglePin(&led1);
	 _delay_ms(350);
	 DIO_enuTogglePin(&led1);
	 _delay_ms(350);

	 DIO_enuTogglePin(&led2);
	 _delay_ms(350);
	 DIO_enuTogglePin(&led2);
	 _delay_ms(350);

	 DIO_enuTogglePin(&led3);
	 _delay_ms(350);
	 DIO_enuTogglePin(&led3);
	 _delay_ms(350);

	 DIO_enuTogglePin(&led4);
	 _delay_ms(350);
	 DIO_enuTogglePin(&led4);
	 _delay_ms(350);
	 }
	 DIO_enuInitPin(&swit);

	 while (1) {
	 DIO_enuClearPin(&led);
	 DIO_enuGetPin(&swit);
	 while (swit.val_t) {
	 DIO_enuSetPin(&led);
	 DIO_enuGetPin(&swit);
	 }
	 }*/

//#endif
//#define  SevSEG
#ifdef SevSEG

	int seg[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110,
		0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};

	SevenSeg_str_t seven1, seven2;

	seven1.enable.pin_t = DIO_OFFSET_D;
	seven1.enable.pin_t = 6;
	seven1.enable.state_t = CMCATH;

	seven2.enable.pin_t = DIO_OFFSET_D;
	seven2.enable.pin_t = 7;
	seven2.enable.state_t = CMCATH;

	seven1.pin_struct[0].port_t = DIO_OFFSET_A;
	seven1.pin_struct[0].pin_t = 0;

	seven1.pin_struct[1].port_t = DIO_OFFSET_B;
	seven1.pin_struct[1].pin_t = 0;

	seven1.pin_struct[2].port_t = DIO_OFFSET_C;
	seven1.pin_struct[2].pin_t = 0;

	seven1.pin_struct[3].port_t = DIO_OFFSET_D;
	seven1.pin_struct[3].pin_t = 0;

	seven1.pin_struct[4].port_t = DIO_OFFSET_A;
	seven1.pin_struct[4].pin_t = 1;

	seven1.pin_struct[5].port_t = DIO_OFFSET_B;
	seven1.pin_struct[5].pin_t = 1;

	seven1.pin_struct[6].port_t = DIO_OFFSET_C;
	seven1.pin_struct[6].pin_t = 1;

	seven2.pin_struct[0].port_t = DIO_OFFSET_A;
	seven2.pin_struct[0].pin_t = 0;

	seven2.pin_struct[1].port_t = DIO_OFFSET_B;
	seven2.pin_struct[1].pin_t = 0;

	seven2.pin_struct[2].port_t = DIO_OFFSET_C;
	seven2.pin_struct[2].pin_t = 0;

	seven2.pin_struct[3].port_t = DIO_OFFSET_D;
	seven2.pin_struct[3].pin_t = 0;

	seven2.pin_struct[4].port_t = DIO_OFFSET_A;
	seven2.pin_struct[4].pin_t = 1;

	seven2.pin_struct[5].port_t = DIO_OFFSET_B;
	seven2.pin_struct[5].pin_t = 1;

	seven2.pin_struct[6].port_t = DIO_OFFSET_C;
	seven2.pin_struct[6].pin_t = 1;

	SevSeg_enuInitSevenSeg(&seven1);
	SevSeg_enuInitSevenSeg(&seven2);

	seven1.enable.val_t = 1;
	seven2.enable.val_t = 0;

	SevSeg_enuWriteSevenSegEnablebit(&seven1);
	SevSeg_enuWriteSevenSegEnablebit(&seven2);
	while (1) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k <100; k++) {

					seven1.value = seg[i];
					SevSeg_enuSetSevenSegValue(&seven1);
					_delay_ms(3);

					seven1.enable.val_t ^= 1;
					SevSeg_enuWriteSevenSegEnablebit(&seven1);
					SevSeg_enuClearSevenSeg(&seven1);

					seven2.value = seg[j];
					SevSeg_enuSetSevenSegValue(&seven2);
					_delay_ms(2);

					seven2.enable.val_t ^= 1;
					SevSeg_enuWriteSevenSegEnablebit(&seven2);
					SevSeg_enuClearSevenSeg(&seven2);
				}
			}
		}
	}

#endif

//#define LCD
#ifdef LCD

	LCD_str_t lcd1;
	lcd1.row=0;
	lcd1.col=10;

	lcd1.value ='A';
	lcd1.bit_mode=LCD_8BitMode;

	for (int i = 0; i < 8; i++) {
		lcd1.lcd_data_pin_struct[i].port_t = DIO_OFFSET_C;
		lcd1.lcd_data_pin_struct[i].pin_t = i;
	}

	for (int i = 0; i < 3; i++) {
		lcd1.lcd_cmd_pin_struct[i].port_t = DIO_OFFSET_D;
		lcd1.lcd_cmd_pin_struct[i].pin_t = i;
	}

	LCD_enuInitLcd(&lcd1);
	//LCD_GOTO(&lcd1);
	//LCD_enuWriteDataLcd(&lcd1);

	//lcd1.str="Mohamed";
	//LCD_enuWriteStringLcd(&lcd1);

	lcd1.lcd_cmd=lcd_CGRAM;
	LCD_enuWriteCMDLcd(&lcd1);

	lcd1.value=0b00000110;
	LCD_enuWriteDataLcd(&lcd1);

	lcd1.value=0b00001000;
	LCD_enuWriteDataLcd(&lcd1);

	lcd1.value=0b00000110;
	LCD_enuWriteDataLcd(&lcd1);

	lcd1.value=0b00000100;
	LCD_enuWriteDataLcd(&lcd1);

	lcd1.value=0b00001000;
	LCD_enuWriteDataLcd(&lcd1);

	lcd1.value=0b00010000;
	LCD_enuWriteDataLcd(&lcd1);

	lcd1.value=0b00001111;
	LCD_enuWriteDataLcd(&lcd1);

	lcd1.lcd_cmd=lcd_SetCursor+5;
	LCD_enuWriteCMDLcd(&lcd1);

	lcd1.value=3;
	LCD_enuWriteDataLcd(&lcd1);

	//LCD_enuWriteSineString(&lcd1);

#endif

#define KEYPAD
#ifdef KEYPAD
	int seg[11] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110,
		0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111, 0};

	SevenSeg_str_t seven1;

	//seven1.enable.val_t=0;
	//seven1.enable.
	for (int i = 0; i < 7; i++) {

		seven1.pin_struct[i].port_t = DIO_OFFSET_C;
		seven1.pin_struct[i].pin_t = i;
	}

	SevSeg_enuInitSevenSeg(&seven1);

	seven1.value = seg[0];

	keypad_t key1 = {
		{	DIO_OFFSET_A, 0, OUTPUT, 0, 0},
		ROW,
		COL,
		{	DIO_OFFSET_A, DIO_OFFSET_A, DIO_OFFSET_A},
		{	DIO_OFFSET_B, DIO_OFFSET_B, DIO_OFFSET_B, DIO_OFFSET_B},
		{	0, 1, 2},
		{	0, 1, 2, 3},
		0,
		{
			{	1, 2, 3},
			{	4, 5, 6},
			{	7, 8, 9},
			{	10, 0, 11}
		},
		0
	};

	key1.switch_p= 11;
	init_keypad(&key1);

	while(1) {
		keypad_scan(&key1);
		seven1.value = seg[(key1.switch_p)];
		SevSeg_enuSetSevenSegValue(&seven1);
		_delay_ms(1000);
	}
#endif
	/*
	 int seg[11] = { 0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110,
	 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111, 0 };

	 SevenSeg_str_t seven1;

	 //seven1.enable.val_t=0;
	 //seven1.enable.
	 for (int i = 0; i < 7; i++) {

	 seven1.pin_struct[i].port_t = DIO_OFFSET_C;
	 seven1.pin_struct[i].pin_t = i;
	 }

	 SevSeg_enuInitSevenSeg(&seven1);

	 seven1.value = seg[0];
	 SevSeg_enuSetSevenSegValue(&seven1);

	 _delay_ms(500);
	 seven1.value = seg[1];
	 SevSeg_enuSetSevenSegValue(&seven1);

	 _delay_ms(500);
	 */


//#define MOTOR
#ifdef MOTOR
	DIO_str_pin_t m1;
    //DIO_str_pin_t swit;

    m1.pin_t = 0;
	m1.port_t = DIO_OFFSET_C;
	m1.state_t = OUTPUT;
	m1.val_t = 1;

	DIO_str_pin_t m2;
	// DIO_str_pin_t swit;

	m2.pin_t = 1;
	m2.port_t = DIO_OFFSET_C;
	m2.state_t = OUTPUT;
	m2.val_t = 0;

	DIO_enuInitPin(&m1);
	DIO_enuInitPin(&m2);

	while(1){
	m1.val_t=1;
	m2.val_t=0;
	DIO_enuSetPin(&m1);
	DIO_enuSetPin(&m2);
	_delay_ms(3000);
    DIO_enuClearPin(&m1);
    m2.val_t=1;
    DIO_enuSetPin(&m2);
_delay_ms(3000);
DIO_enuClearPin(&m2);
	}


#endif
	return 0;
}

