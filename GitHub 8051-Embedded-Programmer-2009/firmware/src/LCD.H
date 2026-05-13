#include<stdio.h>

sbit rs = P4^0;
sbit e  = P4^1;

char lcdbuf[16+1];

void delay_lcd(unsigned long i);
void intitial_lcd (void);
void enable_lcd (void);
void write_cmd_lcd (unsigned char cmd_lcd);
void write_data_lcd (unsigned char data_lcd);
void printlcd(void);
void lcd_line1 (void);
void lcd_line2 (void);
void lcd_line3 (void);
void lcd_line4 (void);
void clear_lcd (void);

void enable_lcd (void)
  {
  	e=0;
	delay_lcd (10);
	e=1;
   }
void delay_lcd(unsigned long i)
{
  while(i > 0) {i--;}					// Loop Decrease Counter	
  return;
}
void write_cmd_lcd (unsigned char cmd_lcd)
{
 	rs = 0;
	P1 = cmd_lcd;
	enable_lcd ();

}
void write_data_lcd (unsigned char data_lcd)
{
   	rs = 1;
	P1 = data_lcd;
	enable_lcd ();

}

void intitial_lcd (void)
{
 	e = 0;
	delay_lcd (100);
	
	write_cmd_lcd (0x33);
	write_cmd_lcd (0x32);
	write_cmd_lcd (0x38);
	write_cmd_lcd (0x0E);
	write_cmd_lcd (0x06);
	write_cmd_lcd (0x01);	

	delay_lcd(50);

}
void printlcd(void)
{
  char *p;
 
  p = lcdbuf;
 
  do 								// Get ASCII & Write to LCD Until null
  {
    write_data_lcd(*p); 					// Write ASCII to LCD
    p++;							// Next ASCII
  }
  while(*p != '\0');				// End of ASCII (null)
 
  return;
}

void lcd_line1 (void)
{
write_cmd_lcd (0x80);
}

void lcd_line2 (void)
{
write_cmd_lcd (0xC0);
}

void lcd_line3 (void)
{
write_cmd_lcd (0x90);
}

void lcd_line4 (void)
{
write_cmd_lcd (0xD0);
}

void clear_lcd (void)
{
write_cmd_lcd (0x01);
}