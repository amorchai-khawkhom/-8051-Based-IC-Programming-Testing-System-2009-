
#include <stdio.h>
// P3.4 = D4
// P3.5 = D5
// P3.6 = D6
// P3.7 = D7

sbit rs = P3^2;
sbit e  = P3^3;

char lcd_buffer[16+1]; 

void delay_lcd(unsigned long i);
void intitial_lcd (void);
void enable_lcd (void);
void write_cmd_lcd (unsigned char cmd_lcd);
void write_data_lcd (unsigned char data_lcd);
void print_lcd(void);
void lcd_line1 (void);
void lcd_line2 (void);
void lcd_line3 (void);
void lcd_line4 (void);
void clear_lcd (void);

void enable_lcd (void)
  {
  	e=1;
	delay_lcd (10);
	e=0;
   }
void delay_lcd(unsigned long i)
{
  while(i > 0) {i--;}					// Loop Decrease Counter	
  return;
}
void write_cmd_lcd (unsigned char cmd_lcd)
{
  rs = 0;				  				// Data Select

  P3 &= 0x0F;           				// Clear old LCD Data (Bit[7..4])
  P3 |= cmd_lcd & 0xF0;       			// Strobe High Nibble Data
  enable_lcd ();						// Enable 
  			
  P3 &= 0x0F;           				// Clear old LCD Data (Bit[7..4])
  P3 |= (cmd_lcd << 4) & 0xF0;  		// Strobe Low Nibble Data
  enable_lcd (); 						// Enable 
  delay_lcd(500);
  return;

}
void write_data_lcd (unsigned char data_lcd)
{
  rs  = 1;				  				// Data Select

  P3 &= 0x0F;           				// Clear old LCD Data (Bit[7..4])
  P3 |= data_lcd & 0xF0;       			// Strobe High Nibble Data
  enable_lcd ();						// Enable  
  			
  P3 &= 0x0F;           				// Clear old LCD Data (Bit[7..4])
  P3 |= (data_lcd << 4) & 0xF0;  		// Strobe Low Nibble Data
  enable_lcd (); 						// Enable 
  delay_lcd(500);
  return;
}

void intitial_lcd (void)
{
 	e = 0;
	delay_lcd (100);
	
	write_cmd_lcd (0x33);
	write_cmd_lcd (0x32);
	write_cmd_lcd (0x28);
	write_cmd_lcd (0x0E);
	write_cmd_lcd (0x06);
	write_cmd_lcd (0x01);	

	delay_lcd(500);

}
void print_lcd(void)
{
  char *p;
 
  p = lcd_buffer;
 
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