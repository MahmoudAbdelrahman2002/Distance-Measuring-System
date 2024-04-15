/******************************************************************************
 *
 * Module: LM35
 *
 * File Name: lm35.h
 *
 * Description:lm35,h file for the AVR lm35 driver
 *
 * Author: Mahmoud Abdelrahman
 *
 *******************************************************************************/
#ifndef LM35_H_
#define LM35_H_
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * calculate the temperature
 * this functoin return with temperature
 */
uint8 LM35_getTemerature();
#endif /* LM35_H_ */
