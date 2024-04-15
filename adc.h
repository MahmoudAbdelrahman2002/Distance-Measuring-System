/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description:adc,h file for the AVR ADC driver
 *
 * Author: Mahmoud Abdelrahman
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023/* the maximam value of 10 bit adc*/
#define ADC_REF_VOLT_VALUE   2.56 /* choose the reference volt*/

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
/*
 * choose the reference volt
 *
 * */
typedef enum
{
	REF=0,VCC=1,INTERNAL=3
} ADC_ReferenceVolatge;
/*
 * choose the prescaler
 *
 * */
typedef enum
{
	Prescaler_2=0, Prescaler_4=2,  Prescaler_8=3, Prescaler_16=4, Prescaler_32=5, Prescaler_64=6,
	Prescaler_128=7

}ADC_Prescaler;
/*
 * choose the reference volt
 * choose the prescaler
 * */
typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Setup the ADC setting

 */
void ADC_init(const ADC_ConfigType * Config_Ptr);
/*
 * Description :
 * call it to read the channel

 */
uint16 ADC_readChannel(uint8 channel);


#endif /* ADC_H_ */
