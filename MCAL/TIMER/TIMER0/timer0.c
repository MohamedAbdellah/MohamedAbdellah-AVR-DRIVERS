/*
 * timer0.c
 *
 *  Created on: Apr 15, 2020
 *      Author: CR0LL0
 */

#include"../../../MCAL/GPIO/Inc/gpio.h"
#include "../../../MCAL/GPIO/Inc/hw_gpio.h"
#include "../../../MCAL/INTERRUPT/HW_Interrupt.h"
#include "../../../LIB/HW_types.h"
#include "../../../MCAL/TIMER/TIMER0/timer0.h"
#include "../../../MCAL/TIMER/TIMER0/HW_timer0.h"

void (*TMR0_PF_CallBack)(void*) = NULL
;
void *TMR0_PvoidCallBack = NULL
;

DIO_errorState_t Timer0_enumTIMERinit(timer0 *tmr) {
	DIO_errorState_t err = NOT_OK;

	HW_WR_PIN(SREG, 7, 1);

	HW_WR_PIN(TCCR0, 6, ((tmr->timer0Mode) >> 0) & 1);
	HW_WR_PIN(TCCR0, 3, ((tmr->timer0Mode) >> 1) & 1);

	HW_WR_PIN(TCCR0, 4, ((tmr->timer0compMode) >> 0) & 1);
	HW_WR_PIN(TCCR0, 5, ((tmr->timer0compMode) >> 1) & 1);

	HW_WR_PIN(TCCR0, 0, ((tmr->timer0Prescaler) >> 0) & 1);
	HW_WR_PIN(TCCR0, 1, ((tmr->timer0Prescaler) >> 1) & 1);
	HW_WR_PIN(TCCR0, 2, ((tmr->timer0Prescaler) >> 2) & 1);

	if (tmr->timer0Prescaler >= 6) {
		HW_WR_PIN(((DIO_OFFSET_B + DIO_DDR)), 0, 1);
		HW_WR_PIN(((DIO_OFFSET_B + DIO_PORT)), 0, 1);
	} else if (tmr->timer0compMode == Toggle_OC0CompareMatch) {
		HW_WR_PIN(((DIO_OFFSET_B + DIO_DDR)), 3, 1);
	} else {

	}
	err = OK;
	return err;
}

DIO_errorState_t Timer0_enumTIMERPreload(u8 val) {
	DIO_errorState_t err = NOT_OK;
	HW_WR_port(TCNT0, val);
	err = OK;
	return err;
}
DIO_errorState_t Timer0_enumOCRPreload(u8 val) {
	DIO_errorState_t err = NOT_OK;
	HW_WR_port(OCR0, val);
	err = OK;
	return err;
}

DIO_errorState_t Timer0_enumTOIE0Interrupt(void) {
	DIO_errorState_t err = NOT_OK;
	HW_WR_PIN(TIMSK, 0, 1);
	err = OK;
	return err;
}

DIO_errorState_t Timer0_enumOCIE0Interrupt(void) {
	DIO_errorState_t err = NOT_OK;
	HW_WR_PIN(TIMSK, 1, 1);
	err = OK;
	return err;
}

DIO_errorState_t Timer0_enuCallBackFunction(timer0 *tmr) {

	DIO_errorState_t error_enuState = NOT_OK;

	TMR0_PvoidCallBack = tmr->TMR0_PvoidCallBack;

	TMR0_PF_CallBack = tmr->TMR0_PF_CallBack;

	return error_enuState;
}

DIO_errorState_t Timer0_enumGETTIMER(u8* val) {

	DIO_errorState_t error_enuState = NOT_OK;

	*val = HW_RD_port(TCNT0);

	return error_enuState;
}

/* ===============================Timer/Counter0 Overflow========================== */
void __vector_11() __attribute__((signal, used));
void __vector_11() {

	//HW_WR_PIN((DIO_OFFSET_A+DIO_PORT),0,1);

	TMR0_PF_CallBack(TMR0_PvoidCallBack);

}

/* =========================Timer/Counter0 Compare Match=========================== */
void __vector_10() __attribute__((signal, used));
void __vector_10() {

	TMR0_PF_CallBack(TMR0_PvoidCallBack);

}
