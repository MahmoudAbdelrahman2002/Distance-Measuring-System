/******************************************************************************
 *
 * Module: ultrasonic sensor
 *
 * File Name: app.c
 *
 * Description:ultra sonic for the AVR GPIO driver
 *
 * Author: Mahmoud Abdelrahman
 *
 *******************************************************************************/

#include "lcd.h"/* to use the functions of lcd */
#include "dc_motor.h"/* to use the functions of motor */
#include "lm35.h"/* to use the functions of lm35 */
#include "adc.h" /* to use the functions of ADC */
#include "ultrasonic.h"
#include "avr/io.h"
void main()
{
	SREG|=(1<<7);
	uint16 Distance=0;
	LCD_init();
	Ultrasonic_init();
	LCD_displayStringRowColumn(0,0,"Distance =");

	while(1)
	{
		LCD_displayStringRowColumn(0,0,"Distance =");
		LCD_moveCursor(0, 10);
		Distance= Ultrasonic_readDistance();
			if(Distance>=100)
			{
				LCD_intgerToString(Distance);
			}
			else if(Distance<100)
			{
				LCD_intgerToString(Distance);
				LCD_displayCharacter(' ');
				LCD_displayCharacter(' ');
			}


	}

}

