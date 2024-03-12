#include <stdint.h>
#include <stdio.h> // Para poder usar printf()
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"

#define GPIOAEN				(1U<<0)
#define PIN5				(1U<<5)//Poner un uno en la posicion 5
#define LED_PIN			    PIN5
int main(void){


	//1. Habilitar el acceso a reloj al GPIOA
	RCC->AHB1ENR |= GPIOAEN;
	//2. Configurar el PIN 5 como salida
	GPIOA-> MODER |=  (1U<<10);//poner un uno en la posicion dies |= es or igual
	GPIOA-> MODER &=~ (1U<<11);//poner un cero en la posicion once &=~ es and igual negado

	uart2_rx_tx_init();


	while(1){

		printf("Retardo de un segundo!! \n\r");
		GPIOA->ODR ^= LED_PIN;//Donde ^=, es alternancia (XOR)
		SystickDelayMS(10);

	}
}

