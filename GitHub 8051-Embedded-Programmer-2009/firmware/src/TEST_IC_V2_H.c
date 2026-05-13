#include <at89c51ac2.h>
#include <i2c_keypad_h.h>
#include <lcd4bit_port3_h.h>
#include <sound_h.h>

#include<TEST7400.h>
#include<TEST7401.h>
#include<TEST7402.h>
#include<TEST7403.h>
#include<TEST7404.h>
#include<TEST7408.h>
#include<TEST7432.h>
#include<TEST7486.h>

void delay(unsigned long i);

int input_mode (void);
int input_number_ic (void);

void test_auto (void);
void test_manual (void);
void main_test (void);
void back_to_menu (void);
void print_lcd_back_to_menu (void);

int round_keypad=0,keypad_value=0,keypad_sum=0,keypad_sum_main=0,keypad_mode=0  ;
unsigned char keypad=0,keypad_display=0;

void main ()
{
	  main_test ();
}
	   
void main_test (void)
{
	round_keypad = 0;
	keypad_value = 0;
	keypad_sum = 0;
	keypad_sum_main=0;
	keypad_mode=0;
 	keypad = 0;
	keypad_display=0;
	delay(1000);

	intitial_lcd();
	lcd_line1 ();sprintf(lcd_buffer,"Bualoy & Nussra.");print_lcd ();
	lcd_line2 ();sprintf(lcd_buffer,"MACHINE IC TEST.");print_lcd ();
	lcd_line3 ();sprintf(lcd_buffer,"74XX 00 01 02 03");print_lcd ();
	lcd_line4 ();sprintf(lcd_buffer,"04 08 32 86.    ");print_lcd ();
	delay(50000);
	
	clear_lcd();
	lcd_line1 ();sprintf(lcd_buffer,"PLEASE PRESS 1,2");print_lcd (); 
	lcd_line2 ();sprintf(lcd_buffer," 1 = AUTO MODE  ");print_lcd ();
	lcd_line3 ();sprintf(lcd_buffer," 2 = MANUAL MODE");print_lcd ();
	lcd_line4 ();sprintf(lcd_buffer,"You Select Mode ");print_lcd ();
	delay(5000);
	
	keypad_mode = input_mode ();
		
		

	switch (keypad_mode)
	{
		case 1  :  	test_auto ();	break ; 
		case 2  :  	test_manual();	break ;
	  	default :	clear_lcd();
					lcd_line1 ();sprintf(lcd_buffer,"You Insert Value");print_lcd ();
					lcd_line2 ();sprintf(lcd_buffer,"    Invalid     ");print_lcd ();
					lcd_line3 ();sprintf(lcd_buffer,"Please Press 1,2");print_lcd ();
					lcd_line4 ();sprintf(lcd_buffer," * Back to Menu ");print_lcd ();
					back_to_menu();		
   	}
}

int input_mode (void)
{	
	round_keypad = 0;
	while(round_keypad<1) 
	{
	keypad_value = 0;	
	keypad  =  scankey();
		if (keypad != 15)
		{	
			keypad_display = keypad;
			keypad_value = keypad;							  	
			while (keypad !=15)
			{
				keypad  =  scankey(); 
			}
			sound_test_step();
			write_cmd_lcd (0xDF);sprintf(lcd_buffer,"%c",keypad_display);print_lcd ();
			keypad_value = keypad_value - 48;
			delay(50000);
			round_keypad++;
	 	 }
	}
	return keypad_value;
}

void test_auto (void)
{
	clear_lcd();
	lcd_line1 ();sprintf(lcd_buffer,"PLEASE INSERT IC");print_lcd (); 
	lcd_line2 ();sprintf(lcd_buffer," PLEASE  INSERT ");print_lcd ();
	lcd_line3 ();sprintf(lcd_buffer," SERIES  NUMBER ");print_lcd ();
	lcd_line4 ();sprintf(lcd_buffer," OF 74xx        ");print_lcd ();
	
	keypad_sum_main = input_number_ic ();

	delay(50000);

	switch (keypad_sum_main)
	{
		case 0  :  test_ic7400_all_auto();back_to_menu();break ;
		case 1  :  test_ic7401_all_auto();back_to_menu();break ; 
		case 2  :  test_ic7402_all_auto();back_to_menu();break ;
		case 3  :  test_ic7403_all_auto();back_to_menu();break ;
		case 4  :  test_ic7404_all_auto();back_to_menu();break ;
		case 8  :  test_ic7408_all_auto();back_to_menu();break ;
		case 32 :  test_ic7432_all_auto();back_to_menu();break ;
		case 86 :  test_ic7486_all_auto();back_to_menu();break ;
	
	  default :	clear_lcd();
				lcd_line1 ();sprintf(lcd_buffer," THE MACHINE IC ");print_lcd ();
				lcd_line2 ();sprintf(lcd_buffer," TESTER  Cann't ");print_lcd ();
				lcd_line3 ();sprintf(lcd_buffer," TEST IC 74XX%d ",keypad_sum_main);print_lcd ();
				lcd_line4 ();sprintf(lcd_buffer," * Back to Menu ");print_lcd ();
				back_to_menu();
									
	}									  
}

void test_manual (void)
{
	clear_lcd();
	lcd_line1 ();sprintf(lcd_buffer,"PLEASE INSERT IC");print_lcd (); 
	lcd_line2 ();sprintf(lcd_buffer," PLEASE  INSERT ");print_lcd ();
	lcd_line3 ();sprintf(lcd_buffer," SERIES  NUMBER ");print_lcd ();
	lcd_line4 ();sprintf(lcd_buffer," OF 74xx        ");print_lcd ();
	
	keypad_sum_main = input_number_ic ();

	delay(50000);

	switch (keypad_sum_main)
	{
		case 0  :  test_ic7400_all();print_lcd_back_to_menu ();back_to_menu();break ;
		case 1  :  test_ic7401_all();print_lcd_back_to_menu ();back_to_menu();break ; 
		case 2  :  test_ic7402_all();print_lcd_back_to_menu ();back_to_menu();break ;
		case 3  :  test_ic7403_all();print_lcd_back_to_menu ();back_to_menu();break ;
		case 4  :  test_ic7404_all();print_lcd_back_to_menu ();back_to_menu();break ;
		case 8  :  test_ic7408_all();print_lcd_back_to_menu ();back_to_menu();break ;
		case 32 :  test_ic7432_all();print_lcd_back_to_menu ();back_to_menu();break ;
		case 86 :  test_ic7486_all();print_lcd_back_to_menu ();back_to_menu();break ;
	
	  default :	clear_lcd();
				lcd_line1 ();sprintf(lcd_buffer," THE MACHINE IC ");print_lcd ();
				lcd_line2 ();sprintf(lcd_buffer," TESTER  Cann't ");print_lcd ();
				lcd_line3 ();sprintf(lcd_buffer," TEST IC 74XX%d ",keypad_sum_main);print_lcd ();
				lcd_line4 ();sprintf(lcd_buffer," * Back to Menu ");print_lcd ();
				back_to_menu();
									
	}																		  
}

int input_number_ic (void)
{
	round_keypad = 0;
 	while(round_keypad<2) 
	{
	keypad_value = 0;
	keypad  =  scankey();
		if (keypad != 15)
		{	
			keypad_display = keypad;
			keypad_value = keypad;							  	
			while (keypad !=15)
			{
				keypad  =  scankey(); 
			}
			sound_test_step();
		write_cmd_lcd (0xD8+round_keypad);sprintf(lcd_buffer,"%c",keypad_display);print_lcd ();//keypad_display = number cann't opration but can display * # to lcd 
		keypad_value = keypad_value - 48; //keypad_value = number can opration but cann't display * # to lcd 	
			if(round_keypad==0)
			{
			keypad_sum = keypad_value * 10;
			}
			if(round_keypad==1)
			{
			keypad_sum = keypad_sum + keypad_value ;
			}
			round_keypad++;	
	   	}
   	}
	return keypad_sum ; 
}

void back_to_menu (void)
{
	round_keypad = 0;
	while(round_keypad<1) 
	{
	keypad_value = 0;	
	keypad  =  scankey();
		if (keypad != 15)
		{	
			keypad_value = keypad;							  	
			while (keypad !=15)
			{
				keypad  =  scankey(); 
			}
			sound_test_step();
			while(keypad_value==42)
			{
			main_test ();
			}
		 }
	}
	
}
void print_lcd_back_to_menu (void)
{
	clear_lcd();
	lcd_line1 ();sprintf(lcd_buffer," Please Press * ");print_lcd ();
	lcd_line2 ();sprintf(lcd_buffer," Back  to  Menu ");print_lcd ();
	lcd_line3 ();sprintf(lcd_buffer," /////   /^^^/ ");print_lcd ();
	lcd_line4 ();sprintf(lcd_buffer,"(@^_^@)  |*_*| ");print_lcd ();
}

void delay(unsigned long i)
{
  while(i > 0) {i--;}									// Loop Decrease Counter	
  return;
}



