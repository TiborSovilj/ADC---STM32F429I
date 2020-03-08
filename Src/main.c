#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "../Inc/stm32f746xx.h"
#include "../Inc/memoryMapping.h"

void RCC_Init();

void main(){

	RCC_Init();
	LED_Init();
	ADC_Init();
        
	while(1){
		LED_State(ADC_Read());
	}
}

void RCC_Init(){
	RCC_TypeDef* rcc = RCC;
	SET_BIT(rcc->AHB1ENR, RCC_AHB1ENR_GPIODEN);		// ura LED
    SET_BIT(rcc->AHB1ENR, RCC_AHB1ENR_GPIOAEN);		// ura potenciometar
	SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN);		// ura ADC
}

