/*
 * main.c
 *
 *  Created on: Mar 26, 2020
 *      Author: CR0LL01
 */
#include"../LIB/STD_types.h"
#include"../MCAL/GPIO/Inc/hw_gpio.h"
#include"../MCAL/GPIO/Inc/gpio_error.h"
#include"../MCAL/GPIO/Inc/gpio.h"
#include<util/delay.h>
#include "../HAL/7SEGMENTS/Seven_seg.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/KEYPAD/keypad.h"
#include "../MCAL/INTERRUPT/Interrupt.h"
#include "../LIB/HW_types.h"
#include"../MCAL/ADC/ADC.h"
#include "../MCAL/INTERRUPT/interrupt_Config.h"
#include "../MCAL/TIMER/TIMER0/timer0.h"
#include"../MCAL/UART/uart.h"

#define F_CPU 8000000

//DIO_str_pin_t swit;

void fun(void*);

void toggleLed(void);

LCD_str_t lcd1;

volatile u16 ADC_VAL = 0;

u8 tmrcunt = 0;

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
	 swit.input_res=1;

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
	/*
	 DIO_str_pin_t led2;

	 led2.pin_t = 7;
	 led2.port_t = DIO_OFFSET_A;
	 led2.state_t = OUTPUT;
	 led2.val_t = 1;
	 DIO_enuInitPin(&led2);
	 while(1){
	 DIO_enuTogglePin(&led2);
	 _delay_ms(1000);
	 }

	 */
	LCD_str_t lcd1;
	lcd1.row = 0;
	lcd1.col = 10;

	//lcd1.value ='A';
	lcd1.bit_mode = LCD_8BitMode;

	//data
	//////////////////////////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < 8; i++) {
		lcd1.lcd_data_pin_struct[i].port_t = DIO_OFFSET_C;
		lcd1.lcd_data_pin_struct[i].pin_t = i;
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < 3; i++) {
		lcd1.lcd_cmd_pin_struct[i].port_t = DIO_OFFSET_D;
		lcd1.lcd_cmd_pin_struct[i].pin_t = i;
	}

	LCD_enuInitLcd(&lcd1);
	//LCD_enuWriteDataLcd(&lcd1);
	/*
	 LCD_GOTO(&lcd1);
	 LCD_enuWriteDataLcd(&lcd1);

	 _delay_ms(1000);

	 lcd1.lcd_cmd=lcd_Clear;
	 LCD_enuWriteCMDLcd(&lcd1);

	 lcd1.str="Mohamed";
	 LCD_enuWriteStringLcd(&lcd1);
	 */

	/*
	 u8 M[8] = { 0b00000, 0b00000, 0b11111, 0b00101, 0b00111, 0b00000, 0b00000,
	 0b00000 };
	 u8 O[8] = { 0b01000, 0b00100, 0b11111, 0b00000, 0b00000, 0b00000, 0b00000,
	 0b00000 };

	 u8 D[8] = { 0b00100, 0b00100, 0b11111, 0b00000, 0b00000, 0b00000, 0b00000,
	 0b00000 };

	 lcd1.lcd_cmd = lcd_CGRAM;
	 LCD_enuWriteCMDLcd(&lcd1);

	 for (int i = 0; i < 8; i++) {
	 lcd1.value = M[i];
	 LCD_enuWriteDataLcd(&lcd1);
	 }

	 for (int i = 0; i < 8; i++) {
	 lcd1.value = O[i];
	 LCD_enuWriteDataLcd(&lcd1);
	 }

	 for (int i = 0; i < 8; i++) {
	 lcd1.value = M[i];
	 LCD_enuWriteDataLcd(&lcd1);
	 }

	 for (int i = 0; i < 8; i++) {
	 lcd1.value = D[i];
	 LCD_enuWriteDataLcd(&lcd1);
	 }

	 lcd1.lcd_cmd = lcd_SetCursor;
	 LCD_enuWriteCMDLcd(&lcd1);

	 for (int i = 3; i >= 0; i--) {
	 lcd1.value = i;
	 LCD_enuWriteDataLcd(&lcd1);
	 }

	 _delay_ms(1000);
	 */
	lcd1.lcd_cmd = lcd_Clear;
	LCD_enuWriteCMDLcd(&lcd1);

	u8 PerUp[8] = {0b01110, 0b01010, 0b10101, 0b01110, 0b10101, 0b01110,
		0b00100, 0b00100};

	u8 PerDown[8] = {0b01110, 0b01010, 0b00100, 0b01110, 0b10101, 0b01110,
		0b10101, 0b00100};

	int cunt = 5;
	while (cunt--) {

		lcd1.lcd_cmd = lcd_CGRAM;
		LCD_enuWriteCMDLcd(&lcd1);

		for (int i = 0; i < 8; i++) {
			lcd1.value = PerUp[i];
			LCD_enuWriteDataLcd(&lcd1);
		}

		lcd1.lcd_cmd = lcd_SetCursor;
		LCD_enuWriteCMDLcd(&lcd1);

		lcd1.value = 0;
		LCD_enuWriteDataLcd(&lcd1);

		_delay_ms(750);

		lcd1.lcd_cmd = lcd_CGRAM;
		LCD_enuWriteCMDLcd(&lcd1);

		for (int i = 0; i < 8; i++) {
			lcd1.value = PerDown[i];
			LCD_enuWriteDataLcd(&lcd1);
		}

		lcd1.lcd_cmd = lcd_SetCursor;
		LCD_enuWriteCMDLcd(&lcd1);

		lcd1.value = 0;
		LCD_enuWriteDataLcd(&lcd1);

		_delay_ms(750);
	}
	//lcd1.value=3;
	//LCD_enuWriteDataLcd(&lcd1);
	/*
	 _delay_ms(1000);

	 lcd1.lcd_cmd=lcd_Clear;
	 LCD_enuWriteCMDLcd(&lcd1);
	 LCD_enuWriteSineString(&lcd1);
	 */
#endif

//#define KEYPAD
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
			{	10,0,11}
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

	while(1) {
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

//#define INTERRUPT
#ifdef INTERRUPT
	DIO_str_pin_t led1;
	DIO_str_pin_t led2;

	led1.pin_t = 1;
	led1.port_t = DIO_OFFSET_A;
	led1.state_t = OUTPUT;
	led1.val_t = 1;

	led2.pin_t = 7;
	led2.port_t = DIO_OFFSET_D;
	led2.state_t = OUTPUT;
	led2.val_t = 1;

	swit.pin_t = 3;
	swit.port_t = DIO_OFFSET_D;
	swit.state_t = INPUT;
	swit.input_res = 1;

	DIO_enuInitPin(&led1);

	DIO_enuInitPin(&led2);

	DIO_enuInitPin(&swit);

	init_interrupt();

	set_callback(toggleLed);

	while (1) {
		DIO_enuTogglePin(&led2);
		_delay_ms(1000);
	}
	return 0;
}

void toggleLed(void) {
	HW_toggle_PIN( DIO_PORT + DIO_OFFSET_A, 1);
	_delay_ms(1000);
	HW_toggle_PIN( DIO_PORT + DIO_OFFSET_A, 1);

	_delay_ms(1000);
}

/*
 ISR(INT1_vect){
 HW_toggle_PIN( DIO_PORT + DIO_OFFSET_A, 1);
 _delay_ms(1000);
 HW_toggle_PIN( DIO_PORT + DIO_OFFSET_A, 1);
 _delay_ms(1000);
 }
 */

#endif

//#define ADCDRIVER
#ifdef ADCDRIVER

	DIO_str_pin_t ADCPIN;
	ADCPIN.port_t = DIO_OFFSET_A;
	ADCPIN.pin_t = 0;
	ADCPIN.state_t = INPUT;

	DIO_str_pin_t led1;

	led1.port_t = DIO_OFFSET_D;
	led1.pin_t = 7;
	led1.state_t = OUTPUT;

	HW_WR_port((DIO_OFFSET_C+DIO_DDR),0xFF);

	DIO_enuInitPin(&ADCPIN);
	DIO_enuInitPin(&led1);

	lcd1.bit_mode = LCD_8BitMode;

	init_interrupt();

	//data
	//////////////////////////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < 8; i++) {
		lcd1.lcd_data_pin_struct[i].port_t = DIO_OFFSET_C;
		lcd1.lcd_data_pin_struct[i].pin_t = i;
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < 3; i++) {
		lcd1.lcd_cmd_pin_struct[i].port_t = DIO_OFFSET_D;
		lcd1.lcd_cmd_pin_struct[i].pin_t = i;
	}

	LCD_enuInitLcd(&lcd1);
	inti_ADC();
	while (1) {
		/**	 ADC START CONVENTION	**/
		Start_Conversion();
		HW_WR_port((DIO_OFFSET_C+DIO_PORT), ADC_VAL);
	}
	return 0;
}

ISR(ADC_vect) {
	ADC_VAL = ADC_READ();
}

#endif

//#define PWM
#ifdef PWM

	DIO_str_pin_t pin1;
// DIO_str_pin_t swit;

	pin1.pin_t = 0;
	pin1.port_t = DIO_OFFSET_B;
	pin1.state_t = OUTPUT;
	pin1.val_t = 1;

	DIO_enuInitPin(&pin1);

	DIO_str_pin_t pin2;
// DIO_str_pin_t swit;

	pin2.pin_t = 1;
	pin2.port_t = DIO_OFFSET_B;
	pin2.state_t = OUTPUT;
	pin2.val_t = 1;

	DIO_enuInitPin(&pin2);

	DIO_str_pin_t pin3;
// DIO_str_pin_t swit;

	pin3.pin_t = 3;
	pin3.port_t = DIO_OFFSET_B;
	pin3.state_t = OUTPUT;
	pin3.val_t = 1;

	DIO_enuInitPin(&pin3);

	DIO_str_pin_t pin4;
// DIO_str_pin_t swit;

	pin4.pin_t = 5;
	pin4.port_t = DIO_OFFSET_B;
	pin4.state_t = OUTPUT;
	pin4.val_t = 1;

	DIO_enuInitPin(&pin4);

	while(1) {
		pin1.val_t=1;
		pin2.val_t=1;
		pin3.val_t=1;
		pin4.val_t=1;

		DIO_enuSetPin(&pin1);
		DIO_enuSetPin(&pin2);
		DIO_enuSetPin(&pin3);
		DIO_enuSetPin(&pin4);
		_delay_ms(1000);

		pin1.val_t=0;
		pin2.val_t=0;
		pin3.val_t=0;
		pin4.val_t=0;

		DIO_enuSetPin(&pin1);
		DIO_enuSetPin(&pin2);
		DIO_enuSetPin(&pin3);
		DIO_enuSetPin(&pin4);
		_delay_ms(1000);
	}

	while(1) {

		pin1.val_t=1;
		pin2.val_t=0;
		pin3.val_t=0;
		pin4.val_t=0;
		DIO_enuSetPin(&pin1);
		DIO_enuSetPin(&pin2);
		DIO_enuSetPin(&pin3);
		DIO_enuSetPin(&pin4);
		_delay_ms(10);

		pin1.val_t=0;
		pin2.val_t=1;
		pin3.val_t=0;
		pin4.val_t=0;
		DIO_enuSetPin(&pin1);
		DIO_enuSetPin(&pin2);
		DIO_enuSetPin(&pin3);
		DIO_enuSetPin(&pin4);
		_delay_ms(10);

		pin1.val_t=0;
		pin2.val_t=0;
		pin3.val_t=1;
		pin4.val_t=0;
		DIO_enuSetPin(&pin1);
		DIO_enuSetPin(&pin2);
		DIO_enuSetPin(&pin3);
		DIO_enuSetPin(&pin4);
		_delay_ms(10);

		pin1.val_t=0;
		pin2.val_t=0;
		pin3.val_t=0;
		pin4.val_t=1;
		DIO_enuSetPin(&pin1);
		DIO_enuSetPin(&pin2);
		DIO_enuSetPin(&pin3);
		DIO_enuSetPin(&pin4);
		_delay_ms(10);

//_delay_ms(1000);

	}

}

#endif
//#define EXT_INT
#ifdef EXT_INT

	DIO_str_pin_t swit1;
	swit1.port_t = DIO_OFFSET_D;
	swit1.pin_t = 2;
	swit1.state_t = INPUT;
	swit1.input_res = 1;

	DIO_str_pin_t led;
	led.port_t = DIO_OFFSET_A;
	led.pin_t = 0;
	led.state_t = OUTPUT;

	//DIO_enuInitPin(&led);

	DIO_enuInitPin(&swit1);

	HW_WR_port((DIO_DDR+DIO_OFFSET_A), 0xFF);

	u8 k = 255;
	void *ptr = &k;

	Interrupt ex_int0;

	ex_int0.INT_Type = EXIT_INT0;
	ex_int0.INT_SenceMode = RISING_EDAGE;
	ex_int0.INT_PF_CallBack = fun;
	ex_int0.INT_PvoidCallBack = ptr;

	INT_enuInit(&ex_int0);
	INT_enuSelectSenceLevel(&ex_int0);
	INT_enuCallBackFunction(&ex_int0);

	HW_WR_PIN(0x5F, 7, 1);
	while(1) {}

}

void fun(void* para) {

	HW_WR_port((DIO_PORT+DIO_OFFSET_A),*(u8*)para);
	_delay_ms(500);
	HW_WR_port((DIO_PORT+DIO_OFFSET_A),0);


	//HW_WR_PIN((DIO_PORT+DIO_OFFSET_A),1,1);
}
#endif

//#define TIMER0
#ifdef TIMER0

HW_WR_port((DIO_OFFSET_D + DIO_DDR), 0xFF);
HW_WR_port((DIO_OFFSET_D + DIO_PORT), 0xFF);
_delay_ms(1000);
HW_WR_port((DIO_OFFSET_D + DIO_PORT), 0);


	u8 val = 0;
	void * k = &val;
	HW_WR_port((DIO_OFFSET_A + DIO_DDR), 0xFF);
	HW_WR_PIN((DIO_OFFSET_B + DIO_PORT), 3, 1);

	timer0 tmr0;

	tmr0.timer0Mode =NormalPortOperation;
	tmr0.timer0compMode = NormalPortOperation;
	tmr0.timer0Prescaler = prescaler_1024;
	tmr0.TMR0_PF_CallBack = fun;
	tmr0.TMR0_PvoidCallBack = k;

	Timer0_enumTIMERinit(&tmr0);
	Timer0_enumTOIE0Interrupt();

	/*
	 * ============ Counter Mode ==================
	 Timer0_enumTIMERPreload(0);
	 while(1){
	 Timer0_enumGETTIMER(&val);
	 HW_WR_port((DIO_OFFSET_A+DIO_PORT),val);
	 }
	 =========================================== */
	/* Timer */

	/* OCR */

	Timer0_enuCallBackFunction(&tmr0);
	Timer0_enumOCRPreload(10);
	//Timer0_enumOCIE0Interrupt();

	while (1) {
	}
}

void fun(void* para) {
	if (tmrcunt == 20) {
		HW_toggle_PIN((DIO_OFFSET_A + DIO_PORT), 0);
		tmrcunt = 0;
	} else {
		tmrcunt++;
	}
}
#endif

Uart_init(9600);
UART_send_byte('A');
while(1)
	;
//_delay_ms(1000);

}
