/*
 * adc.c
 *
 *  Created on: Apr 6, 2020
 *      Author: CR0LL0
 */
#include "../../LIB/HW_types.h"
#include "../../MCAL/ADC/hw_ADC.h"
#include"../../MCAL/GPIO/Inc/gpio.h"
#include "../../MCAL/ADC/ADC_config.h"


void inti_ADC(void) {

#ifdef ADC_Enabled
	HW_WR_PIN(ADCSRA, 7, HIGH);
#ifdef AREF
	HW_WR_PIN(ADMUX,7,LOW);
	HW_WR_PIN(ADMUX,6,LOW);

#elif AVCC
	HW_WR_PIN(ADMUX, 7, LOW);
	HW_WR_PIN(ADMUX, 6, HIGH);
#else
	HW_WR_PIN(ADMUX,7,HIGH);
	HW_WR_PIN(ADMUX,6,HIGH);
#endif

#ifdef RightAdj
	HW_WR_PIN(ADMUX, 5, LOW);
#else
	HW_WR_PIN(ADMUX, 5, HIGH);
#endif

#ifdef ADC_CHANNEL
	HW_WR_port(ADMUX, (HW_RD_port(ADMUX)) | ADC_CHANNEL);
#endif

#ifdef ADC_INTERRUPT_ENABLED
	HW_WR_PIN(ADCSRA, 3, HIGH);

	#else
	HW_WR_PIN(ADCSRA, 3, LOW);
#endif

	//PRESCALLER SET

	HW_WR_port(ADCSRA, (HW_RD_port(ADCSRA)) | ADC_PRESCALER);

#else
	HW_WR_PIN(ADCSRA, 7, LOW);
#endif

}
void Start_Conversion(void) {

	HW_WR_PIN(ADCSRA, 6, HIGH);

}
u16 ADC_READ(void) {
	u16 read = 0;
	//read = HW_RD_port(ADCL);
	read = (HW_RD_port(ADCL) >>6 );
	read = (read | (HW_RD_port(ADCH) <<2 ));

	return read;

}
u8 check_Flag(void) {

	return HW_RD_PIN(ADCSRA, 4);
}
