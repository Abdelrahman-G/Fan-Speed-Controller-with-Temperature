/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM.h
 *
 * Description: Source file for the PWM driver
 *
 * Author: Abdelrahman gomaa
 *
 *******************************************************************************/
#include "PWM.h"

/*Description:
 *  Set timer0 with PWM mode and timer0 prescaler.
 * 	Set up pin 3 in port B.
 * 	set OCR0 value with the required duty cycle.
 */
void PWM_Timer0_Start(uint8 duty_cycle) {
	GPIO_writePin(PORTB_ID, PIN3_ID, LOGIC_HIGH); // set up pin as output.
	TCNT0 = 0; // Reset timer0 counter register.
	OCR0 = duty_cycle; // Set the required duty cycle value.
	TCCR0 = (1 << WGM01) | (1 << WGM00) | (1 << COM01) | (1 << CS01); // Set up PWM mode and prescaler 8.
}
