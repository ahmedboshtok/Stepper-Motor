/*
 * Stepper_priv.h
 *
 *  Created on: ???/???/????
 *      Author: abosh
 */

#ifndef HALL_STEPPER_MOTOR_STEPPER_PRIV_H_
#define HALL_STEPPER_MOTOR_STEPPER_PRIV_H_

#define STEPPER_PORTA		DIO_u8GROUP_A
#define STEPPER_PORTB		DIO_u8GROUP_B
#define STEPPER_PORTC		DIO_u8GROUP_C
#define STEPPER_PORTD		DIO_u8GROUP_D

#define STEPPER_PIN0		DIO_u8PIN0
#define STEPPER_PIN1		DIO_u8PIN1
#define STEPPER_PIN2		DIO_u8PIN2
#define STEPPER_PIN3		DIO_u8PIN3
#define STEPPER_PIN4		DIO_u8PIN4
#define STEPPER_PIN5		DIO_u8PIN5
#define STEPPER_PIN6		DIO_u8PIN6
#define STEPPER_PIN7		DIO_u8PIN7

#define COIL_A				0x08
#define COIL_B				0x04
#define COIL_C				0x02
#define COIL_D				0x01

#define COIL_A_D			0x09
#define COIL_A_B			0x0C
#define COIL_B_C			0x06
#define COIL_C_D			0x03

#define STEPS				64
#define ZERO			0
#endif /* HALL_STEPPER_MOTOR_STEPPER_PRIV_H_ */
