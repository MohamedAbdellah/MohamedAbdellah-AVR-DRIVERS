/*
 * gpio.h
 *
 *  Created on: Mar 26, 2020
 *      Author: CR0LL0
 */

#ifndef GPIO_H_
#define GPIO_H_
#include"../../../LIB/STD_types.h"
/*
typedef enum DIO_enm_PORT {
	PORTA = 9, PORTB = 6, PORTC = 3, PORTD = 0
} DIO_enm_port_t;
*/
typedef enum DIO_enm_State {
	INPUT = 0, OUTPUT = 1
} DIO_enm_state_t;

typedef enum DIO_enm_Vlue {
	LOW = 0, HIGH = 1
} DIO_enm_val_t;


typedef struct DIO_str_PIN {
	u8 port_t;
	u8 pin_t;
	DIO_enm_state_t state_t;
	u8 val_t :1;
	u8 input_res :1;

} DIO_str_pin_t;

typedef enum Error {
	PORT_NOT_EXIST, PIN_NOT_EXIST, NOT_OK, OK, NULL_POINTER
} DIO_errorState_t;

DIO_errorState_t DIO_enuInitPin(DIO_str_pin_t *);
DIO_errorState_t DIO_enuClearPin(DIO_str_pin_t *);
DIO_errorState_t DIO_enuSetPin(DIO_str_pin_t *);
DIO_errorState_t DIO_enuGetPin(DIO_str_pin_t *);
DIO_errorState_t DIO_enuTogglePin(DIO_str_pin_t *);

#endif /* GPIO_H_ */
