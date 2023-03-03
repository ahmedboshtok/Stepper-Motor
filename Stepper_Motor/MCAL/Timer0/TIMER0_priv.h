/*
 * TIMER0_priv.h
 *
 *  Created on: Feb 23, 2022
 *      Author: Ahmed Boshtok
 */

#ifndef TIMER0_PRIV_H_
#define TIMER0_PRIV_H_



#define  TCCR0 	(*(volatile u8 *) 0x53 )
#define  TCNT0 	(*(volatile u8 *) 0x52 )
#define  OCR0	(*(volatile u8 *) 0x5C )
#define  TIMSK	(*(volatile u8 *) 0x59 )
#define  TIFR	(*(volatile u8 *) 0x58 )





#define FOC0 7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02 2
#define CS01 1
#define CS00 0




#define OCIE0 1
#define TOIE0 0



#define OCF0 1
#define TOV0 0

#define NORMAL_MODE         0
#define CTC                 1
#define FAST_PWM            2
#define PWM                 3


#define T0_INT_OVF								0
//#define T0_INT_COMP								1


#define NO_CLOCK 			0//T0_STOP
#define NO_PRESCALER		1
#define PRESCALER_8			2
#define PRESCALER_64		3
#define PRESCALER_256		4
#define PRESCALER_1024		5
#define EC_FALLING_EDGE		6
#define EC_RISING_EDGE		7


#define TIMER0_FREQ				(16000UL)

#define  INIT_VALUE 6

#define PRESCALER64				64

#define COUNTS					256

#define TIMER0_INT_OVF								0
#define TIMER0_INT_COMP								1




#endif /* TIMER0_PRIV_H_ */
