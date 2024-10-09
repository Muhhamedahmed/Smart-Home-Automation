/*
 * smart_home.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Muhamed Ahmed
 */
#include"led.h"
#include"lm35_sensor.h"
#include"lcd.h"
#include"motor.h"
#include"ldr.h"
#include"buzzer.h"
#include "flame_sensor.h"
#include <util/delay.h>
#include"adc.h"


int main(void){

	uint16 Intensity = 0;
	uint8 Temp= 0;

	/* ---Function prototypes---
	 * Initialize the LCD display
	 * Initialize the ADC for reading analog sensor data
	 * Initialize the LEDs (Red, Green, Blue)
	 * Initialize the DC motor (for fan control)
	 * Initialize the buzzer for fire or alert notifications
	 * Initialize the flame sensor for fire detection
	 * Display the string "Fan is OFF" on the LCD at row 0, column 3
	 */
	LCD_init();
	ADC_init();
	LEDS_init();
	DcMotor_Init();
	Buzzer_init();
	FlameSensor_init();

	LCD_displayStringRowColumn(0,3,"Fan is OFF");
	while(1){
		/*
		 * Get the current temperature from the LM35 sensor
		 * Get the current light intensity from the LDR sensor
		 * Move the LCD cursor to the second row, first column
		 * Display "Temp=" on the LCD
		 * Display the temperature value on the LCD
		 * Display " LDR=" on the LCD (indicating the LDR value will be displayed next)
		 * Display the LDR light intensity percentage on the LCD
		 * Display the "%" sign after the LDR intensity value
		 */
		Temp = LM35_getTemperature();
		Intensity =  LDR_getLightIntensity();
		LCD_moveCursor(1,0);
		LCD_displayString("Temp=");
		LCD_intgerToString(Temp);
		LCD_displayString(" LDR=");
		LCD_intgerToString(Intensity);
		LCD_displayString("%  ");
		/* Check if the temperature is greater than or equal to 40°C*/
		if(Temp >= 40){
			/*
			 * Display "Fan is ON" on the LCD at row 0, column 3
			 * Rotate the DC motor (fan) in the clockwise direction with 100% speed
			 */
			LCD_displayStringRowColumn(0,3,"Fan is ON ");
			DcMotor_Rotate(CW,100);
		}

		/* Check if the temperature is between 35°C and 39°C (inclusive)*/
		else if((Temp>=35) && (Temp<40)){
			/*
			 * Display "Fan is ON" on the LCD at row 0, column 3
			 * Rotate the DC motor (fan) in the clockwise direction with 255 (likely a scaling for high speed)
			 */
			LCD_displayStringRowColumn(0,3,"Fan is ON ");
			DcMotor_Rotate(CW,75);
		}

		/* Check if the temperature is between 30°C and 34°C (inclusive)*/

		else if((Temp>=30) && (Temp<35)){
			/*
			 * Display "Fan is ON" on the LCD at row 0, column 3
			 * Rotate the DC motor (fan) in the clockwise direction with 50% speed
			 */
			LCD_displayStringRowColumn(0,3,"Fan is ON ");
			DcMotor_Rotate(CW,50);
		}
		/* Check if the temperature is between 25°C and 29°C (inclusive) */
		else if((Temp>=25) && (Temp<30)){
			/*
			 * Display "Fan is ON" on the LCD at row 0, column 3
			 * Rotate the DC motor (fan) in the clockwise direction with 25% speed
			 */
			LCD_displayStringRowColumn(0,3,"Fan is ON ");
			DcMotor_Rotate(CW,25);
		}
		/* If the temperature is less than 25°C */
		else {
			/*
			 * Display "Fan is OFF" on the LCD at row 0, column 3
			 * Stop the DC motor (fan) by setting the speed to 0
			 */
			LCD_displayStringRowColumn(0,3,"Fan is OFF");
			DcMotor_Rotate(stop,0);
		}

		/*
		 * Check if the light intensity is less than or equal to 15%
		 * Turn on the red LED
		 * Turn on the green LED
		 * Turn on the blue LED
		 */

		if(Intensity <= 15){
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_on(LED_BLUE);
		}
		/*
		 * Check if the light intensity is between 16% and 50% (inclusive)
		 * Turn on the red LED
		 * Turn on the green LED
		 * Turn off the blue LED
		 */
		else if((Intensity>=16) && (Intensity<=50)){
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_off(LED_BLUE);
		}
		/*
		 * Check if the light intensity is between 51% and 70% (inclusive)
		 * Turn on the red LED
		 * Turn off the green LED
		 * Turn off the blue LED
		 */
		else if((Intensity>=51) && (Intensity<=70)){//WORKING

			LED_on(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
		}
		/*
		 * Check if the light intensity is greater than 70%
		 * Turn off the red LED
		 * Turn off the green LED
		 * Turn off the blue LED
		 */
		else if(Intensity>70){//WORKING

			LED_off(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
		}
		/*
		 * Fallback condition
		 * Turn off the red LED
		 * Turn on the green LED
		 * Turn on the blue LED
		 */
		else{
			LED_off(LED_RED);
			LED_on(LED_GREEN);
			LED_on(LED_BLUE);
		}
		/* Check if the flame sensor detects a fire (FlameSensor_getValue() returns 1) */
		if(FlameSensor_getValue() == 1){
			/*
			 * First: Clear the LCD screen
			 * Then: Display "Critical alert!" on the LCD at row 0, column 0
			 * Then: Move the cursor to the next line on the LCD (row 1, column 0)
			 * Then: Turn on the buzzer to signal the fire alarm
			 *
			 */
			LCD_clearScreen();
			LCD_displayStringRowColumn(0,0,"Critical alert!");
			LCD_moveCursor(1,0);
			Buzzer_on();
			/* Wait until the flame sensor no longer detects the fire (FlameSensor_getValue() becomes 0) */
			while(FlameSensor_getValue() == 1);
			/* Turn off the buzzer after the fire is no longer detected
			 * Clear the LCD screen
			 * Wait for 2 seconds to allow for the screen update delay
			 * Display "Fire Is Cleared" on the LCD at row 0, column 0
			 * Wait for 3 seconds to keep the message on the screen
			 * Clear the LCD screen after the message has been displayed
			 */
			Buzzer_off();
			LCD_clearScreen();
			_delay_ms(2000);
			LCD_displayStringRowColumn(0,0,"Fire Is Cleared");
			_delay_ms(3000);
			LCD_clearScreen();

		}
	}
	return 0;
}

