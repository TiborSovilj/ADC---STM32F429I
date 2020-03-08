#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "../Inc/stm32f746xx.h"
#include "../Inc/memoryMapping.h"

ADC_TypeDef* adc1 = ADC1;		// PA0
GPIO_TypeDef* gpioa = GPIOA;	// PA0

void ADC_Init(){
        
    SET_BIT(gpioa->MODER, 0x00000003);
  
  	
  	CLEAR_BIT (adc1->SQR1, ADC_SQR1_L); 		//	stevilo pretvorb = 1
  	CLEAR_BIT (adc1->CR2, ADC_CR2_CONT); 		//	single conversion mode --> CONT = 0
  	CLEAR_BIT (adc1-> CR1, ADC_CR1_AWDCH_0); 	//	channel (PA)0
  	SET_BIT (adc1-> CR1, ADC_CR1_RES_0); 		//	10 bit resolution
  	SET_BIT (adc1->CR2, ADC_CR2_ADON); 			//	start AD pretvornika
}


int ADC_Read(){
  	SET_BIT (adc1->CR2, ADC_CR2_SWSTART); 			// ADC start
  	while (!(READ_BIT(adc1->SR, ADC_SR_EOC))); 		// while EOC = 0
  	CLEAR_BIT (adc1->SR, ADC_SR_EOC); 				// EOC = 1
        
  	return adc1->DR & 0x3FF;
}
