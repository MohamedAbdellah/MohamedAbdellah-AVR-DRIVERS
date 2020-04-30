/*
 * Motor.c
 *
 *  Created on: Apr 5, 2020
 *      Author: CR0LL0
 */
/*
m1.pin_t = 0;
m1.port_t = DIO_OFFSET_C;
m1.state_t = OUTPUT;
m1.val_t = 1;

DIO_str_pin_t m2;
// DIO_str_pin_t swit;

m2.pin_t = 1;
m2.port_t = DIO_OFFSET_C;
m2.state_t = OUTPUT;
m2.val_t = 0;
DIO_enuInitPin(&m1);
DIO_enuInitPin(&m2);

while(1) {
	m1.val_t=1;
	m2.val_t=0;
	DIO_enuSetPin(&m1);
	DIO_enuSetPin(&m2);
	_delay_ms(3000);
	DIO_enuClearPin(&m1);
	m2.val_t=1;
	DIO_enuSetPin(&m2);
	_delay_ms(3000);
	DIO_enuClearPin(&m2);
}

DIO_errorState_t DIO_enuInitmotor(motor_str_pin_t *m) {
	DIO_errorState_t err = NOT_OK;
	DIO_enuInitPin(m->m1);
	DIO_enuInitPin(m->m2);
	err = OK;
	return err;
}
DIO_errorState_t DIO_enuMoveForward(motor_str_pin_t *m) {
	DIO_errorState_t err = NOT_OK;

	m->m1.val_t = 1;
	m->m2.val_t = 0;
	DIO_enuSetPin(m->m1);
	DIO_enuSetPin(m->m2);
	err = OK;
	return err;
}
DIO_errorState_t DIO_enuMoveBackward(motor_str_pin_t *m){

	DIO_errorState_t err = NOT_OK;

	m->m1.val_t = 0;
	m->m2.val_t = 1;
	DIO_enuSetPin(m->m1);
	DIO_enuSetPin(m->m2);
	err = OK;
	return err;

}
*/
