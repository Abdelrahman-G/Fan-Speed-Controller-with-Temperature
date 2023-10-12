 /******************************************************************************
 *
 * Module: LM35
 *
 * File Name: lm35.c
 *
 * Description: Source file for the LM35 driver
 *
 * Author: Abdelrahman gomaa
 *
 *******************************************************************************/

#include "lm35.h"
#include "adc.h"
#include <avr/delay.h>
uint16 adc_value;
/*Description:
 *  Read ADC channel 2.
 *  Calculate the temperature and return its value.
 */
uint8 LM35_getTemperature(void){
	uint8 temp_value = 0;
	uint16 adc_value = ADC_readChannel(TEMP_SENSOR_CHANNEL_ID);

	temp_value = (uint8)
		(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(TEMP_SENSOR_MAX_VOLT*ADC_MAXIMUM_VALUE));

	return temp_value;
}
