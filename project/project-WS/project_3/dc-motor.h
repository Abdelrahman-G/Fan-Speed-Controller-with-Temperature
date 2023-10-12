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

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"
#include "GPIO.h"
#include "PWM.h"

/*DC motor states, it is either OFF ,clockwise or anti-clockWise*/
typedef enum {
	OFF, CW, ACW
} DcMotor_State;

/*Description:
 *  Set up DC motor input pins (output pins for the microcontroller).
 *  Make the DC motor OFF initially.
 */
void DcMotor_Init(void);

/*Description:
 *  Configure DC motor state.
 *  Call PWM function with the required duty cycle.
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* DC_MOTOR_H_ */
