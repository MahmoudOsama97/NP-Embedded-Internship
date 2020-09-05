

#include "../Mcal/Dio/Dio.h"
#include "../Mcal/timer/timer.h"
#include "../Mcal/uart/UART.h"
#include "avr/interrupt.h"
#include "../Mcal/Interrupt/interrupt.h"
#include "../Hal/LCD/lcd.h"
#include "../Hal/PWM/PWM.h"
#include "../Hal/Motor/Motor.h"
#include "../Infrastructure/AVR_Reg.h"
volatile uint8_t newValue=0;
volatile uint8_t currentValue=0;



ISR(TIMER0_OVF_vect){	
}
ISR(TIMER0_COMP_vect){	
	PWM_Call(currentValue);
}

void functionTx(void){
}

void functionRx(void){
	newValue=UART_UDR;
}


int main(void){  
	
	str_UartConfg_t uartConfig ={9600,8,0};
	Str_TimerConfiguration_t timerConfig={TIMER0,F_CPU_CLOCK_1024_TIMER_0,COUNTER_MODE,INTERRUPT};
	UART_init(&uartConfig);
	DIO_u8Init_PIN(DIO_PIN_NO_24,DIO_INPUT);
	DIO_u8Init_PIN(DIO_PIN_NO_25,DIO_OUTPUT);
	PWM_Init();
	Motor_Init();
	DIO_u8Init_PORT(DIO_PORT_NO_1,DIO_ALL); 
	 
	
	
	LCD_init();
	
	Timer_Init(&timerConfig);
	Timer_Start(TIMER0,6);
	
	UART_TX_SetCallBack(functionTx);
	UART_RX_SetCallBack(functionRx);
	
	while(1){
		UART_recieveByte(&newValue);
		if(currentValue!=newValue){
			LCD_clearScreen();
			LCD_displayString("The speed is ");
			LCD_integerToString(newValue);
			LCD_displayString("%");
			DIO_u8SetPortValue(DIO_PORT_NO_1,newValue);
			currentValue=newValue;
		}		
	}
}