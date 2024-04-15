/******************************************************************************
 *
 * Module: DC_motor
 *
 * File Name: dc_motor.c
 *
 * Description:dc_motor.c file for the AVR DC_motor driver
 *
 * Author: Mahmoud Abdelrahman
 *
 *******************************************************************************/
#include "dc_motor.h"
#include "gpio.h"/*setup direction of pins*/
#include "pwm.h"/* to  use pwm funcion to control speed*/
/*
 * Description :
 *this funcion set the direction of pins connected to motors
 *to be o/P
 */
void DcMotor_Init(void)
{
	DcMotor_Rotate(STOP, 0);
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);/* out put pins for motors*/
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);/* out put pins for motors*/

}
/*
 *this function to set the directon of rotation and speed
 *
 * */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{

	if(state ==CW)
	{
		PWM_Timer0_Start(speed);
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);

	}
	else if(state ==A_CW)
	{
		PWM_Timer0_Start(speed);

		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_HIGH);
	}
	else if(state==STOP)
	{
		PWM_Timer0_Start(0);
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
	}

}










