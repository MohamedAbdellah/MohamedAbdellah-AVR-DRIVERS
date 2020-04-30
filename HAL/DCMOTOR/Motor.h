/*
 * Motor.h
 *
 *  Created on: Apr 5, 2020
 *      Author: CR0LL0
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include"../../LIB/STD_types.h"
#include"../../MCAL/GPIO/Inc/hw_gpio.h"
#include"../../MCAL/GPIO/Inc/gpio_error.h"
#include"../../MCAL/GPIO/Inc/gpio.h"

typedef struct Motor_str_pin_t{
	DIO_str_pin_t m1;
	DIO_str_pin_t m2;
}motor_str_pin_t;

DIO_errorState_t DIO_enuInitmotor(motor_str_pin_t *);
DIO_errorState_t DIO_enuMoveForward(motor_str_pin_t *);
DIO_errorState_t DIO_enuMoveBackward(motor_str_pin_t *);





#endif /* MOTOR_H_ */
