 /******************************************************************************
 * File Name: main.h
 *
 * Description: Source file for the main project
 *
 * Author: Abdelrahman gomaa
 *
 *******************************************************************************/
#include "lm35.h"
#include "adc.h"
#include "dc-motor.h"
#include "lcd.h"
#include <avr/delay.h>

/*Fan state on LCD*/
#define FAN_OFF "OFF"
#define FAN_ON "ON "

/*Rows and columns of fan and temperature on LCD*/
#define FAN_COLUMN 11
#define FAN_ROW 0
#define TEMPERATURE_COLUMN 11
#define TEMPERATURE_ROW 1

/*
 * Description :
 * Modify the screen when the number of digigts changes
 */
void ClearInLCD(const uint8 *temp) {
	if (*temp<10)
		LCD_displayStringRowColumn(TEMPERATURE_ROW, TEMPERATURE_COLUMN+1, "  ");

	else if (*temp<100)
		LCD_displayStringRowColumn(TEMPERATURE_ROW, TEMPERATURE_COLUMN+2, " ");
}


int main(void) {
	uint8 speed_percentage = 0;
	uint8 temp = 25;

	/*Defining the ADC with prescaler F_CPU/8 and internal refrence voltage = 2.56*/
	ADC_ConfigType Config_Ptr = { INTERNAL_REF, prescaler_8 };

	ADC_init(&Config_Ptr);
	LCD_init();
	DcMotor_Init();

	LCD_moveCursor(FAN_ROW, 4);
	LCD_displayString("FAN is");
	LCD_moveCursor(TEMPERATURE_ROW, 4);
	LCD_displayString("TEMP =    C");

	while (1) {
		temp = LM35_getTemperature();

		LCD_moveCursor(TEMPERATURE_ROW, TEMPERATURE_COLUMN);
		LCD_intgerToString(temp);
		ClearInLCD(&temp);

		/*Displaying the state of the FAN based on the temperature*/
		LCD_displayStringRowColumn(FAN_ROW, FAN_COLUMN, temp < 30 ? FAN_OFF : FAN_ON);

		/* Calculating the duty cycle for the PWM
		 * temp/30*25 is a percentage of maximum speed
		 */
		speed_percentage = (temp > 120 ? 120 : temp) / 30 * 25;

		DcMotor_Rotate(temp < 30 ? OFF : CW, speed_percentage);
	}
}
