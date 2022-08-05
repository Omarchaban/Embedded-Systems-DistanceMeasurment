

#ifndef LCD_H_
#define LCD_H_

#include "STD_TYPES.h"

#define MODE						   8		/*Choose 4 for 4-bit mode or 8 for 8-bit mode*/


#define LCD_DATA_PORT 				   DIO_PORTC
#define LCD_CTRL_PORT 				   DIO_PORTD

#define RS_PIN PIN0
#define E_PIN PIN1
#define RW_PIN PIN2



#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80
#define LCD_ENTRY_MODE_SET			   0x04
void LCD_SendCommand(u8 command);



void LCD_SendData(u16 data);
void LCD_Init();
void LCD_SendString(const char *string);
void LCD_IntToString(u16 integer);

void LCD_moveCursor(u8 row,u8 col);

void LCD_Clear();





#endif /* LCD_H_ */
