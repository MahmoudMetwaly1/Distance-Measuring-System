/*============================================================================================
 * FILE NAME:            UltraSonic.c
 * AUTHER :              MAHMOUD METWALY
 * DATE CREATED :        12/10/2022
 * DESCRIPTION :         UltraSonic Driver

 ===========================================================================================*/
#include "icu.h"
#include "gpio.h"
#include "common_macros.h"
#include <util/delay.h>
#include "ultrasonic.h"
#include <avr/io.h>

uint16 g_timer_value = 0; // Global Variable to store the number of tick
uint8 g_edgeCount = 0;   // Global Variables to store number of edges

void Ultrasonic_init(void)
{
	Icu_ConfigType icu_config = {F_CPU_8,RISING};   // configuration of icu
	Icu_init(&icu_config);                          // initialize icu
	Icu_setCallBack(Ultrasonic_edgeProcessing);     // setup the call back function
	GPIO_setupPinDirection(TRIG_PORT_ID,TRIG_PIN_ID,PIN_OUTPUT);  // setup the trigger pin as output pin
	GPIO_writePin(TRIG_PORT_ID,TRIG_PIN_ID,LOGIC_LOW);           // intial value in trigger pin = 0
}
void Ultrasonic_Trigger(void)
{

		TOGGLE_BIT(PORTB,TRIG_PIN_ID); // toggle the  trigger pin from 0 to 1
		_delay_us(10);                 // delay 10 micro sec
		TOGGLE_BIT(PORTB,TRIG_PIN_ID); // toggle the  trigger pin from 1 to 0



}
uint16 Ultrasonic_readDistance(void)
{
	Ultrasonic_Trigger();  // Aplay pulse in the trigger pin
	_delay_ms(1);
	return g_timer_value / (58) ;  // return the distance in cm

}
void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;    // increment the counter if the call back function is called
	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge to falling edge
		 */
		Icu_clearTimerValue();
		Icu_setEdgeDetectionType(FALLING);

	}
	else if(g_edgeCount == 2)
	{
		g_timer_value = Icu_getInputCaptureValue();  // store the icu value
		ICR1 = 0;                                   // clear the value of icu
		Icu_setEdgeDetectionType(RISING);          // detect rising edge
		g_edgeCount = 0;                           // clear the counter

	}

}

