/*
 * TIMER0_int.h
 *
 *  Created on: Feb 23, 2022
 *      Author: Ahmed Boshtok
 */

#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_



#define TIMER0_uint8INT_OVF                     0
#define TIMER0_uint8INT_COMP                    1


ES_t TIMER0_enuInit(void);
ES_t TIMER0_enuSetDelay(u32 Copy_uint32TimeMs);
ES_t TIMER0_enuEnableOVFInterrupt(void);
ES_t TIMER0_enuDisableOVFInterrupt(void);

#endif /* TIMER0_INT_H_ */
