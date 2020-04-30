/*
 * Interrupt.c
 *
 *  Created on: Apr 5, 2020
 *      Author: CR0LL0
 */

#include"../../MCAL/GPIO/Inc/gpio.h"
#include "../../MCAL/GPIO/Inc/hw_gpio.h"
#include "../../MCAL/INTERRUPT/HW_Interrupt.h"
#include "../../LIB/HW_types.h"
#include "../../MCAL/INTERRUPT/Interrupt.h"
#include "../../MCAL/INTERRUPT/interrupt_Config.h"



static volatile void (*INT_PF_CallBack)(void*) = NULL;
static volatile void *INT_PvoidCallBack = NULL;

DIO_errorState_t INT_enuInit(Interrupt* INT) {
	DIO_errorState_t error_enuState = NOT_OK;

	//HW_WR_PIN(SREG, 7, 1);

	if (INT->INT_Type == EXIT_INT0) {
		HW_WR_PIN(GICR, 6, 1);
		error_enuState = OK;
	} else if (INT->INT_Type == EXIT_INT1) {
		HW_WR_PIN(GICR, 7, 1);
		error_enuState = OK;
	} else if (INT->INT_Type == EXIT_INT2) {
		HW_WR_PIN(GICR, 5, 1);
		error_enuState = OK;
	} else {
		error_enuState = NOT_OK;
	}
	return error_enuState;
}

DIO_errorState_t INT_enuSelectSenceLevel(Interrupt* INT) {
	DIO_errorState_t error_enuState = NOT_OK;

	switch (INT->INT_SenceMode) {
	case LOW_LEVEL:
		switch (INT->INT_Type) {
		case EXIT_INT0:

			HW_WR_PIN(MCUCR, 0, 0);
			HW_WR_PIN(MCUCR, 1, 0);
			error_enuState = OK;
			break;

		case EXIT_INT1:
			HW_WR_PIN(MCUCR, 2, 0);
			HW_WR_PIN(MCUCR, 3, 0);
			error_enuState = OK;
			break;

		case EXIT_INT2:
			return error_enuState = NOT_OK;
			break;

		default:
			return error_enuState = NOT_OK;
			break;
		}
		break;

	case ANY_LOGICAL_CHANGE:

		switch (INT->INT_Type) {
		case EXIT_INT0:
			HW_WR_PIN(MCUCR, 0, 1);
			HW_WR_PIN(MCUCR, 1, 0);
			error_enuState = OK;
			break;

		case EXIT_INT1:
			HW_WR_PIN(MCUCR, 2, 1);
			HW_WR_PIN(MCUCR, 3, 0);
			error_enuState = OK;
			break;

		case EXIT_INT2:
			return error_enuState = NOT_OK;
			break;

		default:
			return error_enuState = NOT_OK;
			break;
		}
		break;

	case FALLING_EDAGE:

		switch (INT->INT_Type) {
		case EXIT_INT0:
			HW_WR_PIN(MCUCR, 0, 0);
			HW_WR_PIN(MCUCR, 1, 1);
			error_enuState = OK;
			break;

		case EXIT_INT1:
			HW_WR_PIN(MCUCR, 2, 0);
			HW_WR_PIN(MCUCR, 3, 1);
			error_enuState = OK;
			break;

		case EXIT_INT2:
			HW_WR_PIN(MCUCSR, 6, 0);
			error_enuState = OK;
			break;
		}
		break;

	case RISING_EDAGE:

		switch (INT->INT_Type) {
		case EXIT_INT0:
			HW_WR_PIN(MCUCR, 0, 1);
			HW_WR_PIN(MCUCR, 1, 1);
			error_enuState = OK;
			break;

		case EXIT_INT1:
			HW_WR_PIN(MCUCR, 2, 1);
			HW_WR_PIN(MCUCR, 3, 1);
			error_enuState = OK;
			break;

		case EXIT_INT2:
			HW_WR_PIN(MCUCSR, 6, 1);
			error_enuState = OK;
			break;

		default:
			return error_enuState = NOT_OK;
			break;
		}
		break;

	default:
		return error_enuState = NOT_OK;
		break;

	}

	return error_enuState;
}

void __vector_1() __attribute__((signal, used));
void __vector_1() {

	INT_PF_CallBack(INT_PvoidCallBack);

}

DIO_errorState_t INT_enuCallBackFunction(Interrupt* INT) {

	DIO_errorState_t error_enuState = NOT_OK;

	INT_PvoidCallBack = INT->INT_PvoidCallBack;

	INT_PF_CallBack = INT->INT_PF_CallBack;

	return error_enuState;
}

