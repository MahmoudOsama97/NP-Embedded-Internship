/*
 * PWM.h
 *
 * Created: 05/09/2020 04:15:24 م
 *  Author: user
 */ 


#ifndef PWM_H_
#define PWM_H_



#include "../../Infrastructure/AVR_Reg.h"
#include "../../Infrastructure/Common_Macros.h"
#include "../../Infrastructure/std_Types.h"
#include "../../Mcal/Dio/Dio.h"
#include "../../Mcal/timer/timer.h"


volatile uint8_t togglFlag;
volatile uint8_t OCR_LOW;
volatile uint8_t OCR_HIGH;

void PWM_Init(void);
	
void PWM_Call(volatile uint8_t currentValue);


#endif /* PWM_H_ */