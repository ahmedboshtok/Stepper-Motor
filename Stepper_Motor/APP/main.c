/*
 * main.c
 *
 *  Created on: Feb 23, 2022
 *      Author: Ahmed Boshtok
 */


#include "../HALL/Stepper_Motor/Stepper_int.h"

#define period	100
int main(){
	Stepper_voidInit();


	while (1){

		Stepper_voidHalfStep();
		Stepper_voidAntiClockwiseFullStep();
		Stepper_voidFullStep();
		Stepper_voidAntiClockwiseHalfStep();
		Stepper_voidStop();
	}

	return 0;
}

/*
void delay(void){
	for (int i=0;i<=220;i++){
		for (int j=0;j<=200;j++){
			__asm("NOP");
		}
	}
}
int main(){
	DIO_enuInit();
	while (1){
		DIO_enuSetPinValue(DIO_u8GROUP_A,DIO_u8PIN0,DIO_u8HIGH );
		delay();
		DIO_enuSetPinValue(DIO_u8GROUP_A,DIO_u8PIN0,DIO_u8LOW );
		delay();

	}

	return 0;
}*/

