/*
 * Motor.c
 *
 * Created: 05/09/2020 04:16:08 م
 *  Author: user
 */ 
#include "Motor.h"
void Motor_Init(void){
	
	
	DIO_u8Init_PIN(DIO_PIN_NO_17,DIO_OUTPUT);
	DIO_u8Init_PIN(DIO_PIN_NO_18,DIO_OUTPUT);
	DIO_u8SetPinValue(DIO_PIN_NO_18,DIO_HIGH);
	DIO_u8SetPinValue(DIO_PIN_NO_17,DIO_LOW); 
	DIO_u8Init_PIN(DIO_PIN_NO_19,DIO_OUTPUT);
	
	
}