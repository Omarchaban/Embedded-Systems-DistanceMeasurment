
#ifndef _ULTRASONIC_H
#define _ULTRASONIC_H
#include "STD_TYPES.h"
#include "DIO.h"

#define Division_Factor 58
#define ULTRASONIC_PORT	DIO_PORTA
#define ULTRASONIC_PIN	PIN0

u16 Ultrasonic_DistanceMeasured();

void Ultrasonic_CallBackFunction();

void Ultrasonic_Trigger();










#endif
