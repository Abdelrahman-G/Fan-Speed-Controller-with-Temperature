/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Header file for the ADC driver
 *
 * Author: Abdelrahman gomaa
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"
#define ADC_REF_VOLT_VALUE 2.56
#define ADC_MAXIMUM_VALUE 1023

/*ADC refrence voltage values in ADMUX register*/
typedef enum {
	AREF, AVCC, RESERVED, INTERNAL_REF

} ADC_ReferenceVolatge;

/*ADC prescaler values*/
typedef enum {
	prescaler_2 = 1,
	prescaler_4,
	prescaler_8,
	prescaler_16,
	prescaler_32,
	prescaler_64,
	prescaler_128

} ADC_Prescaler;

/*ADC configurations types */
typedef struct {
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
} ADC_ConfigType;

/* making this function configurable for any ADC initializations.
 * Set the ADC configurations.
 * Set refrence volt in REF bits in ADMUX register.
 * Enable the ADC and set the precaler through ADCSRA register.
 */
void ADC_init(const ADC_ConfigType *Config_Ptr);

/*Description:
 *  Read ADC channel from pin 2.
 *  Set ADSC bit to start conversion.
 *  USe polling after starting conversion to wait for stoing the value in ADC register.
 *  clear ADC interrupt flag bit for further channel readings.
 *  Return ADC register value.
 */
uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */
