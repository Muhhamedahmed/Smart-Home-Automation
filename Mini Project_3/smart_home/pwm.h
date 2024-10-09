/*
 * pwm.h
 *
 *  Created on: Oct 3, 2024
 *      Author: Muhamed Ahmed
 */

#ifndef PWM_H_
#define PWM_H_
#include "common_macros.h" /* For GET_BIT Macro */
#include "avr/io.h" /* To use the PWM Registers */
#include "std_types.h"

void PWM_Timer0_start(uint8 duty_cycle);


#endif /* PWM_H_ */
