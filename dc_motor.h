/******************************************************************************
 *
 * Module: DC_motor
 *
 * File Name: dc_motor.h
 *
 * Description:dc_motor.h file for the AVR DC_motor driver
 *
 * Author: Mahmoud Abdelrahman
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "std_types.h"

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
/*
 * set the direction of rotation
 */
typedef enum
{
	CW, A_CW,STOP
}DcMotor_State;
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 *this funcion set the direction of pins connected to motors
 *to be o/P
 */
void DcMotor_Init(void);
/*
 *this function to set the directon of rotation and speed
 *
 * */

void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H_ */
