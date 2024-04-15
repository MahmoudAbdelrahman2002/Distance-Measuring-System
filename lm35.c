/******************************************************************************
 *
 * Module: LM35
 *
 * File Name: lm35.c
 *
 * Description:lm35,c file for the AVR lm35 driver
 *
 * Author: Mahmoud Abdelrahman
 *
 *******************************************************************************/

#include "lm35.h"
#include "adc.h"/* to use function of read channel */

/*
 * Description :
 * calculate the temperature
 */
uint8 LM35_getTemerature()
{
	/* digital valuable store the value of ADC*/
	uint16 digital=0;
	digital=ADC_readChannel(SENSOR_CHANNEL_ID);
	uint8 temp=0;
	/* temp valuable store the temperature*/
	temp= (uint8)(((uint32)digital*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp;
}
