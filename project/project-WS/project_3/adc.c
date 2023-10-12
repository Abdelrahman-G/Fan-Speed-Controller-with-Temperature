/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ADC driver
 *
 * Author: Abdelrahman gomaa
 *
 *******************************************************************************/
#include "adc.h"
#include "common_macros.h"
#include <avr/io.h>

/* making this function configurable for any ADC initializations.
 * Set the ADC configurations.
 * Set refrence volt in REF bits in ADMUX register.
 * Enable the ADC and set the precaler through ADCSRA register.
 */
void ADC_init(const ADC_ConfigType *Config_Ptr) {
	ADMUX = (ADMUX & 0x3F) | (((Config_Ptr->ref_volt) & 0x03) << 6);
	ADCSRA = (1 << ADEN) | ((Config_Ptr->prescaler) & 0x07);
}

/*Description:
 *  Read ADC channel from pin 2.
 *  Set ADSC bit to start conversion.
 *  USe polling after starting conversion to wait for stoing the value in ADC register.
 *  clear ADC interrupt flag bit for further channel readings.
 *  Return ADC register value.
 */
uint16 ADC_readChannel(uint8 ch_num) {
	ADMUX = (ADMUX & 0xE0) | (ch_num & 0x07);
	SET_BIT(ADCSRA, ADSC);

	while (!(GET_BIT(ADCSRA, ADIF)));

	SET_BIT(ADCSRA, ADIF);
	return ADC;

}

