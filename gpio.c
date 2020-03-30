/*
 * gpio.c
 *
 *  Created on: Mar 26, 2020
 *      Author: CR0LL0
 */
#include"STD_types.h"
#include"hw_gpio.h"
#include"gpio.h"
#include"gpio_error.h"
#include "BIT_MATH.h"
#include "HW_types.h"

DIO_errorState_t DIO_enuInitPin(DIO_str_pin_t *pin) {
	DIO_errorState_t err = NOT_OK;

	if ((pin->pin_t >= 8) || (pin->val_t >= 2))
		return err = NOT_OK;

	switch (pin->state_t) {
	case OUTPUT:

		HW_WR_PIN(pin->port_t + DIO_DDR, pin->pin_t, 1);
		break;

	case INPUT:
		if (pin->input_res == 1) {
			HW_WR_PIN(DIO_PORT + pin->port_t, pin->pin_t, 1);
		}
		break;

	default:
		err = NOT_OK;
		return err;
		break;
	}

	return err;
}

DIO_errorState_t DIO_enuGetPin(DIO_str_pin_t *pin) {

	DIO_errorState_t err = NOT_OK;
	if ((pin->pin_t >= 8) || (pin->val_t >= 2))
		return err = NOT_OK;

	pin->val_t = HW_RD_PIN(DIO_PIN + pin->port_t, pin->pin_t);

	return err;

}

DIO_errorState_t DIO_enuSetPin(DIO_str_pin_t * pin) {
	int temp = 0;
	DIO_errorState_t err = NOT_OK;
	if ((pin->pin_t >= 8) || (pin->val_t >= 2))
		return err = NOT_OK;
	//switch (pin->port_t) {
	//case PORTA: {
	switch (pin->state_t) {
	case INPUT:
		err = NOT_OK;
		break;

	case OUTPUT:
			HW_WR_PIN(DIO_PORT + pin->port_t, pin->pin_t, 1);
		break;

	default:
		err = NOT_OK;
		return err;
		break;
	}
	return err;
}

DIO_errorState_t DIO_enuClearPin(DIO_str_pin_t *pin) {

	DIO_errorState_t err = NOT_OK;
	if ((pin->pin_t >= 8) || (pin->val_t >= 2))
		return err = NOT_OK;

	switch (pin->state_t) {
	case INPUT:
		err = NOT_OK;
		break;

	case OUTPUT:

		HW_WR_PIN(DIO_PORT + pin->port_t, pin->pin_t, 0);
		break;

	default:
		err = NOT_OK;
		return err;
		break;

	}

	return err;

}

DIO_errorState_t DIO_enuTogglePin(DIO_str_pin_t *pin) {
	int temp = 0;
	DIO_errorState_t err = NOT_OK;
	if ((pin->pin_t >= 8) || (pin->val_t >= 2))
		return err = NOT_OK;

	switch (pin->state_t) {
	case INPUT:
		err = NOT_OK;
		break;

	case OUTPUT:
		HW_toggle_PIN( DIO_PORT + pin->port_t, pin->pin_t);
		break;

	default:
		err = NOT_OK;
		return err;
		break;

	}

	return err;

}


