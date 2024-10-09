/*
 * motor.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Muhamed Ahmed
 */
#include "motor.h"


void DcMotor_Init(void){

	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);
    GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);  // PB3 is OC0


	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed){

	if (state == stop){

		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);

		PWM_Timer0_start(speed);

	}

	else if(state == CW){

		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);

		PWM_Timer0_start(speed);
	}
	else if(state == A_CW){

		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_HIGH);

		PWM_Timer0_start(speed);
	}

}

