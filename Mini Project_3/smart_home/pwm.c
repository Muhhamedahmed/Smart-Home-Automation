/*
 * pwm.c
 *
 *  Created on: Oct 3, 2024
 *      Author: Muhamed Ahmed
 */


#include"pwm.h"

void PWM_Timer0_start(uint8 duty_cycle){


	if(duty_cycle > 100){
		duty_cycle = 100;  // Ensure duty cycle does not exceed 100%
	}

	TCNT0 = 0;  // Set Timer Initial value

	// Set Compare Value for 0-100% duty cycle.
	OCR0  = (uint8)(duty_cycle * 2.55); // Set Compare Value


	DDRB |= (1<<PB3);  // Set PB3/OC0 as output pin

	/* Configure timer control register
	 * 1. Fast PWM mode (WGM01=1 & WGM00=1)
	 * 2. Non-inverting mode (COM01=1, COM00=0)
	 * 3. Clock prescaler = F_CPU/1024 (CS00=1, CS01=0, CS02=1)
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00) | (1<<CS02);

}


