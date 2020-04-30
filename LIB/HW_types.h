/*
 * HW_types.h
 *
 *  Created on: Mar 28, 2020
 *      Author: CR0LL0
 */

#ifndef HW_TYPES_H_
#define HW_TYPES_H_


#include"../LIB/STD_types.h"

static inline u8  HW_RD_PIN(u8 reg, u8 pin )
{

   return  (*(volatile u8*)(reg) & (1 <<pin)) >> pin;

}

static inline void HW_WR_PIN(u8 reg, u8 pin, u8 val) {

	if (1 == val)
	{
		*(volatile u8 *) (reg) |= 1 << pin; //or
	}
	else
	{
		*(volatile u8 *) (reg) &= ~(1 << pin);
	}
}

/*=====================================================================================================================================================*/
static inline void HW_toggle_PIN(u8 reg, u8 pin)
{
       *(volatile u8 *) (reg) ^= 1 << pin ;
}
/*=====================================================================================================================================================*/
static inline void HW_WR_port(u8 reg ,u8 val )
{
	*(volatile u8 *)(reg)=val;
}


static inline u8 HW_RD_port(u8 reg  )
{
	return (*(volatile u8 *)(reg));
}





#endif /* HW_TYPES_H_ */
