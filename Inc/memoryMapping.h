#pragma once

#ifndef MEMORY_MAPPING
#define MEMORY_MAPPING

void ADC_Init();
int ADC_Read();
void LED_Init();
void LED_State(int);

#endif