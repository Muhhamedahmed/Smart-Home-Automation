/*
 * flame_sensor.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Muhamed Ahmed
 */
#include"flame_sensor.h"


void FlameSensor_init(void){

	GPIO_setupPinDirection(FLAME_SENSOR_PORT,FLAME_SENSOR_PIN,PIN_INPUT);

}
uint8 FlameSensor_getValue(void){

	 return GPIO_readPin(FLAME_SENSOR_PORT,FLAME_SENSOR_PIN);

}

