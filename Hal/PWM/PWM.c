/*
 * PWM.c
 *
 * Created: 05/09/2020 04:15:13 م
 *  Author: user
 */ 

#include "PWM.h"


void PWM_Init(void){
	
	DIO_u8Init_PIN(DIO_PIN_NO_16,DIO_OUTPUT);
	DIO_u8SetPinValue(DIO_PIN_NO_16,DIO_LOW);
}
	
void PWM_Call(volatile uint8_t currentValue){
	
	OCR_HIGH=currentValue+1;
	OCR_LOW=101-currentValue;
	if(currentValue==0) DIO_u8SetPinValue(DIO_PIN_NO_19,DIO_LOW);
	else DIO_u8SetPinValue(DIO_PIN_NO_19,DIO_HIGH);
	if(togglFlag==0){
		togglFlag=1;
		TIMER0_OUTPUT_COMPARE_MATCH=OCR_LOW;
		DIO_u8SetPinValue(DIO_PIN_NO_16,DIO_LOW);
		 
		}
	else if(togglFlag==1){
		togglFlag=0;
		TIMER0_OUTPUT_COMPARE_MATCH=OCR_HIGH;
		DIO_u8SetPinValue(DIO_PIN_NO_16,DIO_HIGH); 
				
		}
	
	
}