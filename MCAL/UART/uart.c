/*
 * uart.c
 *
 *  Created on: Apr 22, 2020
 *      Author: CR0LL0
 */
#include"../../MCAL/GPIO/Inc/gpio.h"
#include "../../MCAL/GPIO/Inc/hw_gpio.h"
#include "../../LIB/HW_types.h"
#include "../../MCAL/UART/hw_UART.h"


void Uart_init(u32 BaudRate)
	{
        //u16 BaudRateVal=(((F_CPU)/(16*BaudRate))-1);
	//	HW_WR_port(UBRRL,BaudRateVal);
		//HW_WR_port(UBRRH,(BaudRateVal>>8));
	  //UBRRL = 51;
      HW_WR_port(UBRRL,51);
		HW_WR_port(UCSRC,134);   //8 bit mode

	}

void UART_send_byte( char byte)
 {

	HW_WR_PIN(UCSRB,3,1);
    while(!HW_RD_PIN(UCSRA,5));
    HW_WR_port(UDR,byte);

 }

void  UART_recieve_byte(void)
{

	HW_WR_PIN(UCSRB,4,1);

}


