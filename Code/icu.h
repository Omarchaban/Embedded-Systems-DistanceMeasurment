
#ifndef ICU_H_
#define ICU_H_
#include "STD_TYPES.h"

#define FALLING_EDGE		1
#define RISING_EDGE			0

#define TIMSK				*((volatile u8 *)0x59)
#define TIMSK_OCIE1A		4
#define TIMSK_TICIE1		5

#define TCNT1 				*((volatile u16 *)0x4c)
#define ICR1  				*((volatile u16 *)0x46)

#define TCCR1B 				*((volatile u8 *)0x4e)
#define TCCR1B_ICES1		6 	//Input capture Edge select
#define TCCR1B_WGM13		4   //To Select the mode
#define TCCR1B_WGM12		3	//To select the mode
#define TCCR1B_CS12			2	//for Prescaling
#define TCCR1B_CS11			1   //for Prescaling
#define TCCR1B_CS10			0	//for Prescaling



#define SREG    			*((volatile u8*)0x5f)	//Global interrupt Register
#define SREG_I				7					    //Global interrupt Enable

void ICU_Init();
void ICU_EdgeSelect(u8 Edge);
u16  ICU_Reading(void);
void ICU_SetCallBack(void (*ptr)(void));

#endif /* ICU_H_ */
