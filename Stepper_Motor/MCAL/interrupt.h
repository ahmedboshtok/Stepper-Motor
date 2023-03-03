/*
 * interrupt.h
 *
 *  Created on: Oct 16, 2021
 *      Author: Ahmed Boshtok
 */

#ifndef MCAL_INTERRUPT_H_
#define MCAL_INTERRUPT_H_

#define ISR(vect_num) 		void vect_num (void)__attribute__((signal));\
							void vect_num (void)

#define VECT_INT0		__vector_1
#define VECT_INT1		__vector_2
#define VECT_INT2		__vector_3
#define TIMER0_OVF_VECT				__vector_11
#define TIMER0_COMP_VECT			__vector_10


#define VECT_ADC		__vector_16
#endif /* MCAL_INTERRUPT_H_ */
