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
//#include "LCD.h"

int main() {

	/*
	 #ifdef LED
	 DIO_str_pin_t led1;
	 DIO_str_pin_t swit;

	 led1.pin_t = 1;
	 led1.port_t = PORTA;
	 led1.state_t = OUTPUT;
	 led1.val_t = 1;

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

	int seg[10] = { 0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110,
			0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111 };
	SevenSeg_str_t seven1;

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

	DIO_enuInitSevenSeg(&seven1);
	while (1) {
		for (int i = 0; i < 10; i++) {

			seven1.value = seg[i];
			DIO_enuSetSevenSegValue(&seven1);
			_delay_ms(500);
			DIO_enuClearSevenSeg(&seven1);

		}
	}
//#define LCD
#ifdef LCD

	LCD_str_t lcd1;

	for (int i = 0; i < 8; i++) {
		lcd1.lcd_port[i] = PORTA;
		lcd1.pin_t[i] = i;
	}

	for (int i = 0; i < 2; i++) {
		lcd1.lcd_port[i] = PORTB;
		lcd1.pin_t[i] = i;
	}

	//LCD_enuInitLcd(&lcd1);

#endif

	return 0;
}

