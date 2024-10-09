/*
 * flame_sensor.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Muhamed Ahmed
 */

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_
#include"std_types.h"
#include"gpio.h"


#define FLAME_SENSOR_PORT        PORTD_ID
#define FLAME_SENSOR_PIN         PIN2_ID

void FlameSensor_init(void);
uint8 FlameSensor_getValue(void);

#endif /* FLAME_SENSOR_H_ */
