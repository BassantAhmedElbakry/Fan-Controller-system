/*************************************************************************************************************
 *
 * File name : main.c
 *
 * Application : Fan Controller system
 *
 *  Created on: ٠٥‏/١٠‏/٢٠٢٢
 *
 * Author: BASSANT AHMED
 *
 ************************************************************************************************************/

#include <avr/io.h>
#include"common_macros.h"
#include"adc.h"
#include"lcd.h"
#include"lm35_sensor.h"
#include"dc.h"

int main(void){

	uint8 temperature;

	/* Create configuration structure for ADC driver */
	ADC_ConfigType ADC_Configure = {AVCC_Internal_2_56v,N8};

	/*Initializations*/
	ADC_init(&ADC_Configure);
	LCD_init();
	DcMotor_init();

	LCD_displayStringRowColumn(0, 3, "FAN is ");
	LCD_displayStringRowColumn(1, 3, "Temp =     C");

	while(1){

		/*Display the temperature on the screen*/
		temperature = LM35_getTemperature();
		LCD_moveCursor(1, 10);

		if(temperature >= 100)
			LCD_sendNumbers(temperature);
		else{

			LCD_sendNumbers(temperature);
			LCD_displayCharacter(' ');

		}

		/*Control the fan speed according to the temperature*/
		if(temperature < 30){
			LCD_displayStringRowColumn(0, 10, "OFF");
			DcMotor_Rotate(Stop, 0); /*The fan is off*/
		}
		else if(temperature >= 30 && temperature < 60){
			LCD_displayStringRowColumn(0, 10, "ON ");
			DcMotor_Rotate(Clockwise, 25); /*The fan with 25% of its maximum speed*/
		}
		else if(temperature >= 60 && temperature < 90){
			LCD_displayStringRowColumn(0, 10, "ON ");
			DcMotor_Rotate(Clockwise, 50); /*The fan with 50% of its maximum speed*/
		}
		else if(temperature >= 90 && temperature < 120){
			LCD_displayStringRowColumn(0, 10, "ON ");
			DcMotor_Rotate(Clockwise, 75); /*The fan with 75% of its maximum speed*/
		}
		else if(temperature >= 120){
			LCD_displayStringRowColumn(0, 10, "ON ");
			DcMotor_Rotate(Clockwise, 100); /*The fan with 100% of its maximum speed*/
		}
	}
}
