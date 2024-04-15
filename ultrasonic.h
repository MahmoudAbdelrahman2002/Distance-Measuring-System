/*
 * ultrasonic.h
 *
 *  Created on: 16 Oct 2022
 *      Author: Hp
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "std_types.h"

void Ultrasonic_init(void);/*inital the ultrasonic*/
void Ultrasonic_Trigger(void);/* send trigger to ultra sonic */
uint16 Ultrasonic_readDistance(void);/*this function resbosable for read distance*/
 void Ultrasonic_edgeProcessing(void);/*this call back function resbonsable to calculate time*/


#endif /* ULTRASONIC_H_ */
