/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM.h
 *
 * Description: Header file for the PWM driver
 *
 * Author: Abdelrahman gomaa
 *
 *******************************************************************************/
#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"
#include "GPIO.h"
#include <avr/io.h>

/*Description:
 *  Set timer0 with PWM mode and timer0 prescaler.
 * 	Set up pin 3 in port B.
 * 	set OCR0 value with the required duty cycle.
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
