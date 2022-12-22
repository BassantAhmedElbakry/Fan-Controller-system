/***********************************************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega32 ADC driver
 *
 * Author: BASSANT AHMED
 *
 **********************************************************************************************************/

#include "adc.h"
#include "gpio.h"
#include "lcd.h"
#include <avr/io.h>


void ADC_init(const ADC_ConfigType * Config_Ptr){

	SET_BIT(ADCSRA,ADEN);
	ADMUX  = (ADMUX & 0x3F)  | ((Config_Ptr ->ref_volt) << 6);
	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr ->prescaler );

}

/*return value is 10-Bits so its uint16 but the argument in a number from 0 to 7*/
uint16 ADC_readChannel(uint8 ch_num){

	ADMUX = (ADMUX & 0xE0) | (ch_num & 0x1F);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF)){

	};
	SET_BIT(ADCSRA,ADIF);
	return ADC;

}

