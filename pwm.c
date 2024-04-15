


/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description:pwm.c file for the AVR PWM driver
 *
 * Author: Mahmoud Abdelrahman
 *
 *******************************************************************************/
#include "pwm.h"
#include <avr/io.h>/* to use commen register*/
#include "gpio.h"/* to use GPIO driver*/
/*
 * Description :
 * Setup the setting of pwm
 *  and choose the duty cycle
 */
void PWM_Timer0_Start(uint8 duty_cycle)
{
	/*
	 * chose the mode fast pwm
	 * non inverting mode
	 * with prescaler 8
	 * */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID,PIN_OUTPUT);/* make Pin3 in PORTB OUTPUT*/
	if(duty_cycle==0)
	{
		/*set the compare valeo*/
		OCR0=0;
	}
	else if(duty_cycle==25)
	{
		/*set the compare valeo*/
		OCR0=64;
	}
	else if(duty_cycle==50)
	{
		/*set the compare valeo*/
		OCR0=128;
	}
	else if(duty_cycle==75)
	{
		/*set the compare valeo*/
		OCR0=191;
	}
	else if(duty_cycle==100)
	{
		/*set the compare valeo*/
		OCR0=255;
	}

}
