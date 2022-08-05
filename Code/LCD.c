

#include "DIO.h"
#include "LCD.h"
#include"util/delay.h"

void LCD_Init()
{
#if MODE == 8
	_delay_ms(50);

	/*function set command */
	LCD_SendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
	_delay_ms(1);

	/*function display command*/
	LCD_SendCommand(LCD_CURSOR_OFF);
	_delay_ms(1);

	/*display clear*/
	LCD_SendCommand(LCD_CLEAR_COMMAND);
	_delay_ms(2);
#elif MODE ==4
	_delay_ms(40);
	LCD_SendCommand(LCD_GO_TO_HOME);
	LCD_SendCommand(LCD_TWO_LINES_FOUR_BITS_MODE); /* use 2-line lcd + 4-bit Data Mode + 5*7 dot display Mode */

	_delay_ms(1);
	LCD_SendCommand(LCD_CURSOR_OFF);
	_delay_ms(1);
	LCD_SendCommand(LCD_CLEAR_COMMAND);
	_delay_ms(2);

#endif

}
void LCD_SendCommand(u8 command)
{    /* setting RS to low*/
	SetPinValue(LCD_CTRL_PORT,RS_PIN,LOW);

	/*setting RW to low for writing */
	SetPinValue(LCD_CTRL_PORT,RW_PIN,LOW);

#if MODE ==8
	/* for sending command */
	SetPortValue(LCD_DATA_PORT,command);

	/*setting E to high*/
	SetPinValue(LCD_CTRL_PORT,E_PIN,HIGH);

	_delay_ms(2);
	/*Setting E to low*/
	SetPinValue(LCD_CTRL_PORT,E_PIN,LOW);

#elif MODE ==4
	/* for sending command and clearing the first 4 bits */
	SetPortValue(LCD_DATA_PORT,(command & 0xf0));

	/*setting E to high*/
	SetPinValue(LCD_CTRL_PORT,E_PIN,HIGH);

	_delay_ms(2);
	/*Setting E to low*/
	SetPinValue(LCD_CTRL_PORT,E_PIN,LOW);

#endif

}
void LCD_SendData(u16 data)
{    	/* setting RS to high*/
	SetPinValue(LCD_CTRL_PORT,RS_PIN,HIGH);

	/*setting RW to low for writing */
	SetPinValue(LCD_CTRL_PORT,RW_PIN,LOW);
#if MODE ==8
	/* for sending data */
	SetPortValue(LCD_DATA_PORT,data);

	/*setting E to high*/
	SetPinValue(LCD_CTRL_PORT,E_PIN,HIGH);

	_delay_ms(2);
	SetPinValue(LCD_CTRL_PORT,E_PIN,LOW);
#elif MODE ==4
	/* for sending command and clearing the first 4 bits */
	SetPortValue(LCD_DATA_PORT,(command & 0xf0));

	/*setting E to high*/
	SetPinValue(LCD_CTRL_PORT,E_PIN,HIGH);

	_delay_ms(2);
	/*Setting E to low*/
	SetPinValue(LCD_CTRL_PORT,E_PIN,LOW);

#endif
}
void LCD_SendString(const char  *string)
{
	u8 Counter=0;
	while(string[Counter] != '\0')
	{
		LCD_SendData(string[Counter]);
		Counter++;
	}



}

void LCD_Clear()
{
	LCD_SendCommand(LCD_CLEAR_COMMAND);


}
void LCD_IntToString(u16 integer)
{
	u8 buffer[20];
	itoa(integer,buffer,10);
	LCD_SendString(buffer);

}


void LCD_moveCursor(u8 row,u8 col)
{
	u8 lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
	case 0:
		lcd_memory_address=col;
		break;
	case 1:
		lcd_memory_address=col+0x40;
		break;

	}
	/* Move the LCD cursor to this specific address */
	LCD_SendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}



