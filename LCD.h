/*
 * LCD.h
 *
 *  Created on: Mar 28, 2020
 *      Author: CR0LL0
 */

#ifndef LCD_H_
#define LCD_H_

#include"gpio.h"

typedef enum LCD_RW_State {
	READ = 0, WRITE = 1
} LCD_RW_state_t;

typedef enum LCD_RS_State {
	CMD = 0, CHAR = 1
} LCD_RS_state_t;

typedef enum LCD_BIT_MODE {
	LCD_8BitMode = 0,  LCD_4BitMode= 1
} LCD_Bit_Mode_t;

typedef enum LCD_cmd_State {

	lcd_Clear=1,                        //replace all characters with ASCII 'space'                    */
	lcd_Home=2,                        // return cursor to first position on first line               */
	lcd_EntryMode=6,                  // shift cursor from left to right on read/write
	lcd_DisplayOff=8,                // turn display off
    lcd_DisplayOn=12,               // display on, cursor off, don't blink character
	lcd_FunctionReset=48,          // reset the LCD
    lcd_Function8bitMode=0x38,    // 8-bit data, 2-line display, 5 x 7 font
    lcd_SetCursor=128

} LCD_cmd_state_t;

typedef struct lcd {

	DIO_str_pin_t lcd_data_pin_struct[8];
	DIO_str_pin_t lcd_cmd_pin_struct[3];       //0->RS, 1->RW, 2->E
	LCD_cmd_state_t lcd_cmd;
	u8 value;
	LCD_Bit_Mode_t bit_mode;
	u8 row;
	u8 col;
	char* str;

} LCD_str_t;

/*
typedef enum Error {
	PORT_NOT_EXIST, PIN_NOT_EXIST, NOT_OK, OK, NULL_POINTER
} LCD_errorState_t;
*/

DIO_errorState_t LCD_enuInitLcd(LCD_str_t *);
DIO_errorState_t LCD_enuWriteCMDLcd(LCD_str_t *);
DIO_errorState_t LCD_enuWriteDataLcd(LCD_str_t *);
DIO_errorState_t LCD_GOTO(LCD_str_t *);
DIO_errorState_t LCD_enuWriteStringLcd(LCD_str_t *);
DIO_errorState_t LCD_enuWriteSineString(LCD_str_t *);


//DIO_errorState_t LCD_enuClearLCDdata(LCD_str_t*) ;
//DIO_errorState_t LCD_enuClearLCDcmd(LCD_str_t*) ;


#endif /* LCD_H_ */



