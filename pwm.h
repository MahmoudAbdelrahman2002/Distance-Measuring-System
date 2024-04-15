/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description:pwm.h file for the AVR PWM driver
 *
 * Author: Mahmoud Abdelrahman
 *
 *******************************************************************************/
#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Setup the setting of pwm
 *  and choose the duty cycle
 */
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */
