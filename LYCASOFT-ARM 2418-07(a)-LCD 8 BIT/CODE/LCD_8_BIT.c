#include <lpc214x.h>
#include "LPC2148_delay.h"

#define RS 0x00000100;
#define EN 0x00000200;

void Lcd_Command(char cmd)                          
{
	IOCLR0 =0XFF;
	IOSET0 = cmd;
	IOCLR0 = RS;
	IOSET0 =  EN;
	delay(10);
	IOCLR0 = EN;
}

void Lcd_Data(char Data)
{
	IOCLR0 = 0XFF;
	IOSET0 = Data;
	IOSET0 = RS;
	IOSET0 =  EN;
	delay(10);
	IOCLR0 = EN;
}

void Lcd_String(const unsigned char *Str)
{
	while(*Str)
	{
		Lcd_Data(*Str++);
	}
}

void Lcd_Intialization()
{
	Lcd_Command(0x38);
	Lcd_Command(0x06);
	Lcd_Command(0x0c);
}

int main()
{
	PINSEL0 = 0x00000000;
	IODIR0 = 0x3FF;
	
	Lcd_Intialization();
	
	while(1)
	{
		Lcd_Command(0x80);
		Lcd_String("LYCASOFT");
	}
}