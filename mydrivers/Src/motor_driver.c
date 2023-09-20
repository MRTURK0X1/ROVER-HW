/*
 * motor_driver.h
 *
 *  Created on: Sep 14, 2023
 *      Author: Asus
 */
#include "stm32f072xb.h"
#include "motor_driver.h"



void motor_Init(){

	//ENABLING PERIPHERAL CLOCK FOR PORT C
	RCC->AHBENR |= ( 1<<19 );


	//OUTOUT MODE FOR PIN 0 AND 1
	GPIOC->MODER |= ( 1<<0 );
	GPIOC->MODER |= ( 1<<2 );

	//PUSH-PULL MODE FOR PIN 0 AND 1
	GPIOC->OTYPER &= ~( 1<<0 );
	GPIOC->OTYPER &= ~( 1<<1 );

	//HIGH SPEED FOR PIN 0 AND 1
	GPIOC->OSPEEDR |= ( 0X3<<0 );
	GPIOC->OSPEEDR |= ( 0X3<<2 );

	//NO PULL UP-PULL DOWN FOR PIN 0 AND 1
	GPIOC->PUPDR &= ~( 0X3<<0 );
	GPIOC->PUPDR &= ~( 0X3<<2 );

	//CLEARING PIN 0 AND 1
	GPIOC->ODR &= ~( 1<<0 ); //IN 1
	GPIOC->ODR &= ~( 1<<1 ); //IN 2




}

void motor_cw(){


	GPIOC->ODR &= ~( 1<<0 ); //IN 1
	GPIOC->ODR |= ( 1<<1 ); //IN 2

}

void motor_ccw(){

	GPIOC->ODR |= ( 1<<0 ); //IN 1
	GPIOC->ODR &= ~ ( 1<<1 ); //IN 2

}

void motor_stop(){

	GPIOC->ODR &= ~( 1<<0 ); //IN 1
	GPIOC->ODR &= ~( 1<<1 ); //IN 2



}
