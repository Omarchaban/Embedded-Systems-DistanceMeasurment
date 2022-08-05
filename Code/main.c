
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "Ultrasonic.h"
#include "LCD.h"
#include "icu.h"
#include <util/delay.h>




void main()
{
	u16 Distance=0;
	/*Setting the directions of LCD and ICU pins*/
	SetPortDirection(LCD_DATA_PORT,0xff);
	SetPinDirection(LCD_CTRL_PORT,E_PIN,OUTPUT);
	SetPinDirection(LCD_CTRL_PORT,RS_PIN,OUTPUT);
	SetPinDirection(DIO_PORTD,PIN6,INPUT);
	SetPinDirection(ULTRASONIC_PORT,ULTRASONIC_PIN,OUTPUT);
	/*Enabling global interrupt*/
	SET_BIT(SREG,SREG_I);

	/*Initializing LCD and ICU*/
	ICU_Init();
	LCD_Init();

	ICU_SetCallBack(&Ultrasonic_CallBackFunction);
	ICU_EdgeSelect(RISING_EDGE);


	while(1)
	{	/*Sending the pulse to he ultrasonic*/
		Ultrasonic_Trigger();

		Distance =Ultrasonic_DistanceMeasured();
		LCD_SendString(" Distance =");
		LCD_IntToString(Distance);
		LCD_SendString(" Cm");
		_delay_ms(1000);
		LCD_Clear();
	}
}


