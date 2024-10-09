#include "ldr.h"
#include "adc.h"



uint16  LDR_getLightIntensity(void)
{
	uint16 Light_intensity=0;
	uint16 adc_value = 0;
	/*  Read the ADC value from the LDR sensor channel */
	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	 float voltage = (adc_value* 5.0) / 1023.0;

	    // Calculate light intensity based on voltage
	Light_intensity = (voltage / LDR_SENSOR_MAX_VOLT_VALUE) * LDR_SENSOR_MAX_LIGHT_INTENSITY;

	    // Ensure the value does not exceed 100%
	    if (Light_intensity > LDR_SENSOR_MAX_LIGHT_INTENSITY) {
	    	Light_intensity = LDR_SENSOR_MAX_LIGHT_INTENSITY;
	    }
	return Light_intensity;
}
