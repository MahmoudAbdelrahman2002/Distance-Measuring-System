#include <util/delay.h>/* to use delay in trigger*/
#include "ultrasonic.h"
#include "icu.h"/*for echo*/
#include "gpio.h"
/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
uint8 g_edge=0;
uint16 g_time=0;

/*******************************************************************************
                    Functions Definitions                                  *
 *******************************************************************************/
/**/
/*inital the ultrasonic*/
void Ultrasonic_init(void)

{
	Icu_ConfigType icuConfg={F_CPU_8,RISING};
		Icu_init(&icuConfg);
	Icu_setCallBack(Ultrasonic_edgeProcessing);/*set call back function*/

	GPIO_setupPinDirection(PORTB_ID, PIN5_ID, PIN_OUTPUT);/*make trigger pin o/p*/


}
/* send trigger to ultra sonic */
void Ultrasonic_Trigger(void)
{
/*send trigger*/
	GPIO_writePin(PORTB_ID, PIN5_ID,LOGIC_HIGH);
_delay_us(10);
GPIO_writePin(PORTB_ID, PIN5_ID,LOGIC_LOW);
}
/*this function resbosable for read distance*/
uint16 Ultrasonic_readDistance(void)
{
g_edge=0;
g_time=0;
	Ultrasonic_Trigger();
g_edge=0;
while(g_edge!=2);/*to ensure that calculated time high for echo*/
	return  g_time/58.8;

}
/*this call back function resbonsable to calculate time*/
 void Ultrasonic_edgeProcessing(void)
 {
	 g_edge++;
	 	if(g_edge == 1)
	 	{
	 		/*
	 		 * Clear the timer counter register to start measurements from the
	 		 * first detected rising edge
	 		 */
	 		Icu_clearTimerValue();
	 		/* Detect falling edge */
	 		Icu_setEdgeDetectionType(FALLING);
	 	}
	 	else if(g_edge == 2)
	 	{
	 		/* Store the High time value */
	 		g_time = Icu_getInputCaptureValue();
	 		/* Detect rising edge */
	 		Icu_clearTimerValue();
	 		Icu_setEdgeDetectionType(RISING);

	 	}

 }
