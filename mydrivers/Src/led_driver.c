/*
 * led_driver.c
 *
 *  Created on: Sep 14, 2023
 *      Author: Asus
 */

#include "stm32f072xb.h"
#include "led_driver.h"


void led_Init(){
	//ENABLING PERIPHERAL CLOCK FOR PORT A
	RCC->AHBENR |= ( 1<<17 );

	//OUTOUT MODE FOR PIN 0, 1 AND 4
	GPIOA->MODER |= ( 1<<0 );
	GPIOA->MODER |= ( 1<<2 );
	GPIOA->MODER |= ( 1<<8 );

	//PUSH-PULL
	GPIOA->OTYPER &= ~( 1<<0 );
	GPIOA->OTYPER &= ~( 1<<1 );
	GPIOA->OTYPER &= ~( 1<<4 );

	//SPEED HIGH
	GPIOA->OSPEEDR |= ( 0X3<<0 );
	GPIOA->OSPEEDR |= ( 0X3<<2 );
	GPIOA->OSPEEDR |= ( 0X3<<8 );

	//NO PULL UP-PULL DOWN
	GPIOA->PUPDR &= ~( 0X3<<0 );
	GPIOA->PUPDR &= ~( 0X3<<2 );
	GPIOA->PUPDR &= ~( 0X3<<8 );

}


// A0
void yellow_led_on(){

	GPIOA->ODR |= ( 1<<0 );

}

void yellow_led_off(){

	GPIOA->ODR &= ~( 1<<0 );

}


//A1
void red_led_on(){

	GPIOA->ODR |= ( 1<<1 );

}

void red_led_off(){

	GPIOA->ODR &= ~( 1<<1 );
}


//A4
void green_led_on(){

	GPIOA->ODR |= ( 1<<4 );

}

void green_led_off(){

	GPIOA->ODR &= ~( 1<<4 );

}
