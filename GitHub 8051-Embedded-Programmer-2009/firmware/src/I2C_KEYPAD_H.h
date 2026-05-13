#include <i2c_1.h>

unsigned char scankey(void);
void delay_keypad(unsigned long i);


unsigned char scankey(void)
{
unsigned char key=15;
unsigned char row;

	i2c_start();i2c_wrdata(0x70);i2c_wrdata(0xEF);i2c_stop();
	delay_keypad (30);
	i2c_start();i2c_wrdata(0x71);row=i2c_rddata();i2c_stop();
	if(row==0xEE){delay_keypad (5000);key=0x31;}
	if(row==0xED){delay_keypad (5000);key=0x34;}		
	if(row==0xEB){delay_keypad (5000);key=0x37;}
	if(row==0xE7){delay_keypad (5000);key='*';}
	
 	i2c_start();i2c_wrdata(0x70);i2c_wrdata(0xDF);i2c_stop();
	delay_keypad (30);
	i2c_start();i2c_wrdata(0x71);row=i2c_rddata();i2c_stop();

	if(row==0xDE) {delay_keypad (5000);key=0x32;}		
	if(row==0xDD) {delay_keypad (5000);key=0x35;}
	if(row==0xDB) {delay_keypad (5000);key=0x38;}		
	if(row==0xD7) {delay_keypad (5000);key=0x30;}

	i2c_start();i2c_wrdata(0x70);i2c_wrdata(0xBF);i2c_stop();
	delay_keypad (30);
	i2c_start();i2c_wrdata(0x71);row=i2c_rddata();i2c_stop();
	
	if(row==0xBE) {delay_keypad (5000);key=0x33;}
	if(row==0xBD) {delay_keypad (5000);key=0x36;}		
	if(row==0xBB) {delay_keypad (5000);key=0x39;}		
	if(row==0xB7) {delay_keypad (5000);key='#';}

	return (key);
	
} 						 		 	 

void delay_keypad(unsigned long i)
{
  while(i > 0) {i--;}									// Loop Decrease Counter	
  return;
}