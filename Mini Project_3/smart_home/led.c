/*
 * led.c
 *
 *  Created on: Oct 3, 2024
 *      Author: Muhamed Ahmed
 */



#include"led.h"

void LEDS_init(void){
	GPIO_setupPinDirection(REDLED_PORT ,REDLED_PIN  ,PIN_OUTPUT);
	GPIO_setupPinDirection(GREENLED_PORT ,GREENLED_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(BLUELED_PORT ,BLUELED_PIN,PIN_OUTPUT);

	LED_off(LED_RED);
	LED_off(LED_GREEN);
	LED_off(LED_BLUE);
}
void LED_on(LED_ID id){
#if (LED_LOGIC == 0)
	switch(id){
	case LED_RED:
		GPIO_writePin(REDLED_PORT,REDLED_PIN,LOGIC_HIGH);
		break;
	case LED_GREEN:
		GPIO_writePin(GREENLED_PORT,GREENLED_PIN,LOGIC_HIGH);
		break;
	case LED_BLUE:
		GPIO_writePin(BLUELED_PORT,BLUELED_PIN,LOGIC_HIGH);
		break;
	default:
		return;
	}
#elif (LED_LOGIC == 1)
	switch(id){
		case LED_RED:
			GPIO_writePin(REDLED_PORT,REDLED_PIN,LOGIC_LOW);
			break;
		case LED_GREEN:
			GPIO_writePin(GREENLED_PORT,GREENLED_PIN,LOGIC_LOW);
			break;
		case LED_BLUE:
			GPIO_writePin(BLUELED_PORT,BLUELED_PIN,LOGIC_LOW);
			break;
		default:
			return;
		}
#endif
}
void LED_off(LED_ID id){
#if (LED_LOGIC == 0)
	switch(id){
	case LED_RED:
		GPIO_writePin(REDLED_PORT,REDLED_PIN,LOGIC_LOW);
		break;
	case LED_GREEN:
		GPIO_writePin(GREENLED_PORT,GREENLED_PIN,LOGIC_LOW);
		break;
	case LED_BLUE:
		GPIO_writePin(BLUELED_PORT,BLUELED_PIN,LOGIC_LOW);
		break;
	default:
		return;
	}
#elif (LED_LOGIC == 1)
	switch(id){
		case LED_RED:
			GPIO_writePin(REDLED_PORT,REDLED_PIN,LOGIC_HIGH);
			break;
		case LED_GREEN:
			GPIO_writePin(GREENLED_PORT,GREENLED_PIN,LOGIC_HIGH);
			break;
		case LED_BLUE:
			GPIO_writePin(BLUELED_PORT,BLUELED_PIN,LOGIC_HIGH);
			break;
		default:
			return;
		}
#endif
}
