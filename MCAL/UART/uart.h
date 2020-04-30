/*
 * uart.h
 *
 *  Created on: Apr 22, 2020
 *      Author: CR0LL0
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

void Uart_init(long BaudRate);

void UART_send_byte( char byte);

void UART_recieve_byte(void);


#endif /* MCAL_UART_UART_H_ */
