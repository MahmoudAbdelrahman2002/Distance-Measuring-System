/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description:adc,c file for the AVR ADC driver
 *
 * Author: Mahmoud Abdelrahman
 *
 *******************************************************************************/

#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "avr/io.h" /* To use the IO Ports Registers */
/*
 * Description :
 * Setup the ADC setting

 */
void ADC_init(const ADC_ConfigType * Config_Ptr)
{

	ADMUX=(ADMUX&0x3f)|((Config_Ptr->ref_volt)<<6);/* choose the reference volt*/
	ADCSRA=(ADCSRA&0xf8)|(Config_Ptr->prescaler); /* choose the prescaler*/
	CLEAR_BIT(ADCSRA, ADIE);/* dissable interrupt */
	SET_BIT(ADCSRA,ADEN);/*enable adc*/
}
/*
 * Description :
 * call it to read the channel

 */
uint16 ADC_readChannel(uint8 channel)
{

	ADMUX=(ADMUX&0xe0)|(channel&0x07);// get the channel in adc mux
	SET_BIT(ADCSRA, ADSC); /*start ADC conversion*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF))/* using polling*/
	{

	}
	SET_BIT(ADCSRA,ADIF);/* clerar flag bit*/
	return ADC; /* return digital value*/
}
