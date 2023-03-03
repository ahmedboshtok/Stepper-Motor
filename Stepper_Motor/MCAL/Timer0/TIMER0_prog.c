/*
 * TIMER0_prog.c
 *
 *  Created on: Feb 23, 2022
 *      Author: Ahmed Boshtok
 */


#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/BIT_MASK.h"
#include "../../LIBRARIES/errorStates.h"

#include "../DIO/DIO_int.h"
#include "../interrupt.h"

#include "TIMER0_config.h"
#include "TIMER0_priv.h"




static u32 TIMER0_uint32NumOVF;
static u8 TIMER0_uint32Preload;

static void (*TIMER0_ApfuncCalledFuncs[2])(void*) = {NULL, NULL};
static void* TIMER0_ApvoidParameters[2] = {NULL, NULL};

ES_t TIMER0_enuInit(void){
	ES_t Local_enuErrorState = ES_NOK;

	TCCR0 &= ~(7 << 0);
	TCCR0 |= (3 << 0);
	TCCR0 &= ~(3 << 4);
	TCCR0 |= (0 << 4);
	TIMSK &= ~(1 << TOIE0);
	TIMSK &= ~(1 << OCIE0);

#if TIMER0_MODE == NORMAL_MODE
	TCCR0 &= ~(1 << WGM00);
	TCCR0 &= ~(1 << WGM01);

	Local_enuErrorState = ES_OK;
#elif TIMER0_MODE == PWM
	TCCR0 &= ~(1 << WGM00);
	TCCR0 &= ~(1 << WGM01);
	TCCR0 |= (1 << WGM00);
	Local_enuErrorState = ES_OK;
#elif TIMER0_MODE == CTC
	TCCR0 &= ~(1 << WGM00);
	TCCR0 &= ~(1 <<WGM01);
	TCCR0 |= (1 << WGM01);
	Local_enuErrorState = ES_OK;
#elif TIMER0_MODE == FAST_PWM
	TCCR0 &= ~(1 << WGM00);
	TCCR0 &= ~(1 << WGM01);
	TCCR0 |= (1 << WGM00);
	TCCR0 |= (1 << WGM01);
	Local_enuErrorState = ES_OK;
#else
#error "Error!"
#endif

	return Local_enuErrorState;
}


ES_t TIMER0_enuSetDelay(u32 Copy_u32TimeMS){
	ES_t  Local_enuErrorState= ES_NOK;
	f32 Local_f32Tick_Time = (f32)PRESCALER64 / TIMER0_FREQ;
	f32 Local_f32TOV = COUNTS * Local_f32Tick_Time;
	f32 Local_f32NumOVF = Copy_u32TimeMS /Local_f32TOV;
	u32 Local_u32_NumOVF = (u32)Local_f32NumOVF +1;
	f32 Local_f32Fraction = Local_f32NumOVF - (u32)Local_f32NumOVF;


	if(Local_f32Fraction != 0.0){
		u32 Local_Count_of_fraction = COUNTS *Local_f32Fraction;
		f32 Local_f32Preload = COUNTS - Local_Count_of_fraction ;
		if((Local_f32Preload - (u32)Local_f32Preload) >= 0.5 && (Local_f32Preload - (u32)Local_f32Preload) < 1){
			TCNT0 = (u8)Local_f32Preload + 1;
		}
		else{
			TCNT0 = (u8)Local_f32Preload;
		}
	}
	else{
		TIMER0_uint32NumOVF = (u32)Local_f32NumOVF;
			TCNT0 = 0;
		}

		while(Local_u32_NumOVF){
			while(!((TIFR >> TOV0) & 1));
			TIFR |= (1 << TOV0);
			Local_u32_NumOVF--;
		}
		return Local_enuErrorState = ES_OK;
	}

ES_t TIMER0_enuEnableOVFInterrupt(void){
	ES_t Local_enuErrorStates = ES_NOK;
	TIMSK |= (1 << TOIE0);
	Local_enuErrorStates = ES_OK;
	return Local_enuErrorStates;
}

ES_t TIMER0_enuDisableOVFInterrupt(void){
	ES_t Local_enuErrorStates = ES_NOK;
	TIMSK &= ~(1 << TOIE0);
	Local_enuErrorStates = ES_OK;
	return Local_enuErrorStates ;
}


ISR(TIMER0_OVF_VECT){

	static u32 counts = 0;
	if(TIMER0_ApfuncCalledFuncs[TIMER0_INT_OVF] != NULL){
		counts++;
		if(counts == TIMER0_uint32NumOVF){
			counts = 0;
			TCNT0 = TIMER0_uint32Preload;
			TIMER0_ApfuncCalledFuncs[TIMER0_INT_OVF](TIMER0_ApvoidParameters[TIMER0_INT_OVF]);
		}
	}
}
