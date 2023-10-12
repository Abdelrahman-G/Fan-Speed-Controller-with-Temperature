/******************************************************************************
 *
 * Module: DC-motor
 *
 * File Name: dc-motor.c
 *
 * Description: Header file for the DC-motor driver
 *
 * Author: Abdelrahman gomaa
 *
 *******************************************************************************/
#include "dc-motor.h"
/*Description:
 *  Set up DC motor input pins (output pins for the microcontroller).
 *  Make the DC motor OFF initially.
 */
void DcMotor_Init(void) {
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);

	/*DC motor initial state is OFF*/
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
}

/*Description:
 *  Configure DC motor state.
 *  Call PWM function with the required duty cycle.
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed) {
	GPIO_writePin(PORTB_ID, PIN0_ID, state & 0x01);
	GPIO_writePin(PORTB_ID, PIN1_ID, state & 0x02);

	/*call function PWM_Timer0_Start(uint8 duty_cycle) with the required duty cycle*/
	PWM_Timer0_Start(speed * 255 / 100);
}
