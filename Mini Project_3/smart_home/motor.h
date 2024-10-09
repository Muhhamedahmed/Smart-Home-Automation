/*
 * motor.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Muhamed Ahmed
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "gpio.h"
#include "pwm.h"
#include "std_types.h"

typedef enum {
	stop,  CW,  A_CW
}DcMotor_State;

void DcMotor_Init(void) ; /* Motor init function */

void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* MOTOR_H_ */
