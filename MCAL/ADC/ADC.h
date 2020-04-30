/*
 * ADC.h
 *
 *  Created on: Apr 6, 2020
 *      Author: CR0LL0
 */

#ifndef ADC_H_
#define ADC_H_


void inti_ADC(void );
void Start_Conversion(void);
u8 check_Flag(void);
u16 ADC_READ(void);

#endif /* ADC_H_ */
