/*
 * Interrupt.h
 *
 *  Created on: Apr 5, 2020
 *      Author: CR0LL0
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_


typedef enum interrupt_Type {

	EXIT_INT0 = 0, EXIT_INT1, EXIT_INT2
} Interrupt_Type;

typedef enum interrupt_SenceMode {

	LOW_LEVEL = 0, ANY_LOGICAL_CHANGE, FALLING_EDAGE, RISING_EDAGE

} Interrupt_SenceMode;

typedef struct interrupt {

	Interrupt_Type INT_Type;
	Interrupt_SenceMode INT_SenceMode;
	void (*INT_PF_CallBack)(void*);
	void *INT_PvoidCallBack;

} Interrupt;

DIO_errorState_t INT_enuInit(Interrupt*);
DIO_errorState_t INT_enuSelectSenceLevel(Interrupt*);
DIO_errorState_t INT_enuCallBackFunction(Interrupt*);


#endif /* INTERRUPT_H_ */
