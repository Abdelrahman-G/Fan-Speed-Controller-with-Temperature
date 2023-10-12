 /******************************************************************************
 *
 * Module: LM35
 *
 * File Name: lm35.c
 *
 * Description: Header file for the LM35 driver
 *
 * Author: Abdelrahman gomaa
 *
 *******************************************************************************/
#ifndef LM35_H_
#define LM35_H_
#include "std_types.h"

/*Definetions for LM35 temperature sensor device*/
#define TEMP_SENSOR_CHANNEL_ID 2
#define TEMP_SENSOR_MAX_VOLT 1.5
#define SENSOR_MAX_TEMPERATURE 150

/*Description:
 *  Read ADC channel 2.
 *  Calculate the temperature and return its value.
 */
uint8 LM35_getTemperature(void);


#endif /* LM35_H_ */
