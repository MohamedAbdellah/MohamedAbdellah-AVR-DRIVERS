/*
 * timer0.h
 *
 *  Created on: Apr 15, 2020
 *      Author: CR0LL0
 */

#ifndef TIMER0_H_
#define TIMER0_H_
#include "../../../MCAL/GPIO/Inc/gpio.h"

typedef enum timer0_mode{

	Normal=0,
	PWM_PHASE_CORRECT,
	CTC,
	FAST_PWM

}timer0WGMode;

typedef enum timer0_CompareOutput_Mode{

	NormalPortOperation=0,
	Toggle_OC0CompareMatch,
	Clear_OC0CompareMatch,
	SET_OC0CompareMatch

}timer0CompareOutputMode;

typedef enum timer0_timer0PreScaler{

	prescaler_0=0,
	prescaler_1,
	prescaler_8,
	prescaler_64,
	prescaler_256,
	prescaler_1024,
	CunterFalling,
	CunterRaising

}timer0PreScaler;

typedef struct Timer0{

	timer0WGMode timer0Mode;
	timer0CompareOutputMode timer0compMode;
	timer0PreScaler timer0Prescaler;
	void (*TMR0_PF_CallBack)(void*);
	void *TMR0_PvoidCallBack;
}timer0;

DIO_errorState_t Timer0_enumTIMERinit(timer0 *tmr); // set mode ,compmode ,prescaler

DIO_errorState_t Timer0_enumTIMERPreload(u8 val);

DIO_errorState_t Timer0_enumGETTIMER(u8* val);

DIO_errorState_t Timer0_enumOCRPreload(u8 val);

DIO_errorState_t Timer0_enumTOIE0Interrupt(void);

DIO_errorState_t Timer0_enumOCIE0Interrupt(void);

DIO_errorState_t Timer0_enuCallBackFunction(timer0 *tmr);





#endif /* TIMER0_H_ */
