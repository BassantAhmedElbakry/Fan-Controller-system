/***********************************************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the ATmega32 ADC driver
 *
 * Author: BASSANT AHMED
 *
 **********************************************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "common_macros.h"

/************************************************************************************************************
 *                                           Definitions                                                    *
 ***********************************************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

typedef enum{
	AREF_External,
	AVCC_Internal_5v,
	Reserved,
	AVCC_Internal_2_56v
}ADC_ReferenceVolatge;

typedef enum{
	Default,
	N2,
	N4,
	N8,
	N16,
	N32,
	N64,
	N128
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	 ADC_Prescaler prescaler;
}ADC_ConfigType;


void ADC_init(const ADC_ConfigType * Config_Ptr);
uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */
