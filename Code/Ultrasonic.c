#include "STD_TYPES.h"
#include "Ultrasonic.h"
#include "icu.h"
#include "DIO.h"
#include <util/delay.h>

/*a variable to store the timer taken from a rising edge to falling edge*/
u16 FallingEdgeTime=0;
/*a variable to store the number of edges he ultrasonic sends*/
u8 EdgeCounter=0;

u16 Distance=0;


u16 Ultrasonic_DistanceMeasured()
{
	/*if the Ultrasonic sends two pulses then we are ready to read the distance */
	if(EdgeCounter ==2)
	{
		Distance=1+(FallingEdgeTime /58);
		EdgeCounter=0;
		return Distance;
	}
}
void Ultrasonic_CallBackFunction()
{
	EdgeCounter++;
	if(EdgeCounter ==1)
	{
		/*clearing the timer*/
		TCNT1 =0;
		/*make the icu trigger at falling edge*/
		ICU_EdgeSelect(FALLING_EDGE);

	}

	if(EdgeCounter ==2)
	{
		/*read the ICU register*/
		FallingEdgeTime =ICU_Reading();
		/*make the ICU trigger at falling edge*/
		ICU_EdgeSelect(RISING_EDGE);

	}
}
void Ultrasonic_Trigger()
{
	/*create a pulse with 10 us width*/
	SetPinValue(ULTRASONIC_PORT,ULTRASONIC_PIN,HIGH);
	_delay_us(10);
	SetPinValue(ULTRASONIC_PORT,ULTRASONIC_PIN,LOW);


}
