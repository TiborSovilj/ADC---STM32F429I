#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "../Inc/stm32f746xx.h"
#include "../Inc/memoryMapping.h"

GPIO_TypeDef* gpio_d = GPIOD;


void LED_Init(){
	SET_BIT(gpio_d->MODER, 0x00000555);
}


void LED_State(int reading){
	CLEAR_BIT(gpio_d->ODR, 0x003F);

	int mask = 1;
	for (int i = 0; i < reading/170; i++){
		mask = (mask << 1) | 1;
	}
	SET_BIT(gpio_d->ODR, mask);
}

// izvedba promjena stanja
// zbroji ili oduzmi s binarnog mjesta ODR-a ovinso o povećanju ili smanjenju napona
// 