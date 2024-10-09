/*
 * led.h
 *
 *  Created on: Oct 3, 2024
 *      Author: Muhamed Ahmed
 */

#ifndef LED_H_
#define LED_H_

#include "std_types.h"
#include "avr/io.h" /* To use the IO Ports Registers */
#include "gpio.h"
#define LED_LOGIC  0        /* '0' is a positive logic, '1' is a negative logic*/
typedef enum {
    LED_RED,
    LED_GREEN,
    LED_BLUE
} LED_ID;

#define REDLED_PORT        PORTB_ID
#define REDLED_PIN         PIN5_ID

#define GREENLED_PORT      PORTB_ID
#define GREENLED_PIN       PIN6_ID

#define BLUELED_PORT       PORTB_ID
#define BLUELED_PIN        PIN7_ID




void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);

#endif /* LED_H_ */
