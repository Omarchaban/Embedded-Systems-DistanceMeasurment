#include "STD_TYPES.h"
#include "icu.h"
#include "BIT_MATH.h"
static void (*pvIcuCallBack)(void)=NULL_PTR;

void ICU_Init()
{
		/*Setting Prescaler to 8 */
		SET_BIT(TCCR1B,TCCR1B_CS11);
		CLR_BIT(TCCR1B,TCCR1B_CS12);
		CLR_BIT(TCCR1B,TCCR1B_CS10);


		/*Choosing OverFlow mode*/
		CLR_BIT(TCCR1B,TCCR1B_WGM12);
		CLR_BIT(TCCR1B,TCCR1B_WGM13);

		/*Enabling ICU interrupt*/
		SET_BIT(TIMSK,TIMSK_TICIE1);
		/*Clearing Registers*/
		TCNT1=0;
		ICR1=0;

}
void ICU_EdgeSelect(u8 Edge)
{
	switch(Edge)
	{
	case(FALLING_EDGE):	CLR_BIT(TCCR1B,TCCR1B_ICES1); break;
	case(RISING_EDGE) : SET_BIT(TCCR1B,TCCR1B_ICES1); break;
	default:break;
	}
}
u16  ICU_Reading(void)
{
	return ICR1;
}
void ICU_SetCallBack(void (*ptr)(void))
{

	pvIcuCallBack=ptr;
}

void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	if(pvIcuCallBack !=NULL_PTR)
	{
		pvIcuCallBack();
	}
	else
	{

	}
}
