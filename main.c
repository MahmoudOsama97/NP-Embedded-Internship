

#include "Dio.h"
#include "timer.h"
#include "avr/interrupt.h"
volatile uint32_t overFlowCount=0;
ISR(TIMER0_OVF_vect){
	
}
ISR(TIMER0_COMP_vect){
	//overFlowCount++;
	//TIMER0_COUNTER_REGISTER=0; 
}

int main(void){  
	
	Str_TimerConfiguration_t Timer0={TIMER0,F_CPU_CLOCK_1024_TIMER_0,COUNTER_MODE,POLLING};
	Timer_Init(&Timer0);
	DIO_u8Init_PIN(DIO_PIN_NO_1,DIO_OUTPUT);
	DIO_u8SetPinValue(DIO_PIN_NO_1,DIO_LOW);
	Timer_Start(TIMER0,0);
    while(1)
    {
		if((TIMER0_INTERRUPT_FLAG_REGISTER&0x01)==1){ 
		overFlowCount++; 
		CLEAR_BIT(TIMER0_INTERRUPT_FLAG_REGISTER,0);
		}
		if(overFlowCount==50000) DIO_u8SetPinValue(DIO_PIN_NO_1,DIO_HIGH);
    }
}