/*
 * hw_gpio.h
 *
 *  Created on: Mar 26, 2020
 *      Author: CR0LL0
 */

#ifndef HW_GPIO_H_
#define HW_GPIO_H_


#define  PORT_D (*((volatile u8*) 0x32))
#define  PIN_D  (*((volatile u8*) 0x30))
#define  DDR_D  (*((volatile u8*) 0x31))

#define  PORT_A (*((volatile u8*) 0x3B))
#define  PIN_A  (*((volatile u8*) 0x39))
#define  DDR_A  (*((volatile u8*) 0x3A))

#define  PORT_C (*((volatile u8*) 0x35))
#define  PIN_C  (*((volatile u8*) 0x33))
#define  DDR_C  (*((volatile u8*) 0x34))

#define  PORT_B (*((volatile u8*) 0x38))
#define  PIN_B  (*((volatile u8*) 0x36))
#define  DDR_B  (*((volatile u8*) 0x37))



//#define DIO_PORT (*((volatile u8*) 0x32))
//#define DIO_DDR (*((volatile u8*) 0x31))
//#define DIO_PIN (*((volatile u8*) 0x30))

#define DIO_PORT 0x32
#define DIO_DDR  0x31
#define DIO_PIN  0x30

#define DIO_OFFSET_A 0x9
#define DIO_OFFSET_B 0x6
#define DIO_OFFSET_C 0x3
#define DIO_OFFSET_D 0x0



#endif /* HW_GPIO_H_ */
