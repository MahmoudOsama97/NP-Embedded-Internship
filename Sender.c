

#include "../Mcal/Dio/Dio.h"
#include "../Mcal/timer/timer.h"
#include "../Mcal/uart/UART.h"
#include "avr/interrupt.h"
#include "../Mcal/Interrupt/interrupt.h"

volatile uint8_t dutyCycle=40;
volatile uint8_t y=0;

void functionTx(void){
	DIO_u8Init_PORT(DIO_PORT_NO_1,DIO_ALL);
	y=UART_UDR;
	DIO_u8SetPortValue(DIO_PORT_NO_1,y);
}
void functionRx(void){
	DIO_u8Init_PORT(DIO_PORT_NO_2,DIO_ALL);
	DIO_u8SetPortValue(DIO_PORT_NO_2,DIO_ALL);
}

void INT0_callBack(void){
	if(dutyCycle<100)
	dutyCycle+=10;
}
void INT1_callBack(void){
	if(dutyCycle>0)
	dutyCycle-=10;
}

int main(void){  
	
	str_UartConfg_t uartConfig ={9600,8,0};
		
	DIO_u8Init_PORT(DIO_PORT_NO_0,DIO_ALL);
	DIO_u8Init_PIN(DIO_PIN_NO_24,DIO_INPUT);
	DIO_u8Init_PIN(DIO_PIN_NO_25,DIO_OUTPUT);
	
	UART_init(&uartConfig);
	
	interrupt0_init(FALLING,INT0_callBack);
	interrupt1_init(FALLING,INT1_callBack);
	
	UART_TX_SetCallBack(functionTx);
	UART_RX_SetCallBack(functionRx);
	
		
	while(1){
		
		UART_sendByte(x);
		DIO_u8SetPortValue(DIO_PORT_NO_0,dutyCycle);
	}
	

}