/*
 * MiniProject4.c
 *
 *  Created on: Oct 13, 2022
 *      Author: PC
 */

#include "lcd.h"
#include "icu.h"
#include "gpio.h"
#include "ultrasonic.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	LCD_init();
	Ultrasonic_init();
	SREG |= (1<<7);
	uint16 dis = 0;
	LCD_displayString("Distance=     cm");
	while(1)
	{
		dis = Ultrasonic_readDistance();
		if(dis >= 410 || dis < 10)
		{
			dis = 0;
			LCD_moveCursor(0,10);
			LCD_intgerToString(dis);
			LCD_moveCursor(0,0);
			LCD_displayStringRowColumn(0,11,"  ");
		}
		else if(dis < 100)
		{
			LCD_moveCursor(0,10);
			LCD_intgerToString(dis);
			LCD_moveCursor(0,0);
			LCD_displayStringRowColumn(0,12,"  ");
		}
		else
		{
			LCD_moveCursor(0,10);
			LCD_intgerToString(dis);
			LCD_moveCursor(0,0);
		}

		_delay_ms(2);

	}

}
