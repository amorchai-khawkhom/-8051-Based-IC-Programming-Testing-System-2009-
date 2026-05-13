sbit IC7400_IC1_PIN1=P0^0;				sbit IC7400_IC2_PIN1=P1^4;
sbit IC7400_IC1_PIN2=P0^1;				sbit IC7400_IC2_PIN2=P1^5;
sbit IC7400_IC1_PIN3=P0^2;				sbit IC7400_IC2_PIN3=P1^6;
sbit IC7400_IC1_PIN4=P0^3;				sbit IC7400_IC2_PIN4=P1^7;
sbit IC7400_IC1_PIN5=P0^4;				sbit IC7400_IC2_PIN5=P2^0;
sbit IC7400_IC1_PIN6=P0^5;				sbit IC7400_IC2_PIN6=P2^1;
sbit IC7400_IC1_PIN8=P0^6;				sbit IC7400_IC2_PIN8=P2^2;
sbit IC7400_IC1_PIN9=P0^7;				sbit IC7400_IC2_PIN9=P2^3;
sbit IC7400_IC1_PIN10=P1^0;				sbit IC7400_IC2_PIN10=P2^4;
sbit IC7400_IC1_PIN11=P1^1;				sbit IC7400_IC2_PIN11=P2^5;
sbit IC7400_IC1_PIN12=P1^2;				sbit IC7400_IC2_PIN12=P2^6;
sbit IC7400_IC1_PIN13=P1^3;				sbit IC7400_IC2_PIN13=P2^7;

void delay_test_7400(unsigned long i);
/*-------------------------Auto_Prototype--------------------------------------*/
void test_7400_ic1_condition_00_auto (void);	   void test_7400_ic2_condition_00_auto (void);
void test_7400_ic1_condition_01_auto (void);	   void test_7400_ic2_condition_01_auto (void);
void test_7400_ic1_condition_10_auto (void);	   void test_7400_ic2_condition_10_auto (void);
void test_7400_ic1_condition_11_auto (void);	   void test_7400_ic2_condition_11_auto (void);
void test_ic7400_ic1_auto (void);				   void test_ic7400_ic2_auto (void);

void test_ic7400_all_auto (void);
/*---------------------End--Auto_Prototype--------------------------------------*/


/*------------------------Manual_Prototype--------------------------------------*/
void test_7400_ic1_condition_00 (void);			   void test_7400_ic2_condition_00 (void);
void test_7400_ic1_condition_01 (void);			   void test_7400_ic2_condition_01 (void);
void test_7400_ic1_condition_10 (void);			   void test_7400_ic2_condition_10 (void);
void test_7400_ic1_condition_11 (void);			   void test_7400_ic2_condition_11 (void);
void test_ic7400_ic1 (void);					   void test_ic7400_ic2 (void);

void test_ic7400_all (void);
/*---------------------End--Manual_Prototype--------------------------------------*/


int IC7400_IC1_G1=0,IC7400_IC1_G2=0,IC7400_IC1_G3=0,IC7400_IC1_G4=0;
int IC7400_IC2_G1=0,IC7400_IC2_G2=0,IC7400_IC2_G3=0,IC7400_IC2_G4=0;
int IC7400_IC2_SUM=0,IC7400_IC1_SUM=0;

/*-----------------------------------------------------Start-Auto_Check---------------------------------------------------------------------*/

/*-----------------------------------------------------Main-Auto_Check---------------------------------------------------------------------*/
void test_ic7400_ic1_auto (void)
{ 
	test_7400_ic1_condition_00_auto ();
	test_7400_ic1_condition_01_auto ();
	test_7400_ic1_condition_10_auto ();
	test_7400_ic1_condition_11_auto ();
	IC7400_IC1_SUM = IC7400_IC1_G4 + IC7400_IC1_G3 + IC7400_IC1_G2 + IC7400_IC1_G1;	
}

void test_ic7400_ic2_auto (void)
{ 
	test_7400_ic2_condition_00_auto ();
	test_7400_ic2_condition_01_auto ();
	test_7400_ic2_condition_10_auto ();
	test_7400_ic2_condition_11_auto ();
	IC7400_IC2_SUM = IC7400_IC2_G4 + IC7400_IC2_G3 + IC7400_IC2_G2 + IC7400_IC2_G1;	
}

void test_ic7400_all_auto (void)
{
 	IC7400_IC1_G1=0;IC7400_IC1_G2=0;IC7400_IC1_G3=0;IC7400_IC1_G4=0;
 	IC7400_IC2_G1=0;IC7400_IC2_G2=0;IC7400_IC2_G3=0;IC7400_IC2_G4=0;
	IC7400_IC2_SUM=0;IC7400_IC1_SUM=0;

 	 test_ic7400_ic1_auto ();
	 test_ic7400_ic2_auto ();
	 
	 clear_lcd();
	 lcd_line1 ();sprintf(lcd_buffer," TEST  COMPLETE ");print_lcd ();
	 lcd_line2 ();sprintf(lcd_buffer," IC1 =          ");print_lcd ();
	 lcd_line3 ();sprintf(lcd_buffer," IC2 =          ");print_lcd ();
	 lcd_line4 ();sprintf(lcd_buffer," * Back to Menu ");print_lcd ();

	 if (IC7400_IC1_SUM == 16)
		{
		write_cmd_lcd (0xC7);sprintf(lcd_buffer,"**PASS**");print_lcd ();
		sound_test_pass();
		}
	else
		{
		write_cmd_lcd (0xC7);sprintf(lcd_buffer,"**FAIL**");print_lcd ();
		sound_test_fail();
		}
	
	if (IC7400_IC2_SUM == 16)
		{
		write_cmd_lcd (0x97);sprintf(lcd_buffer,"**PASS**");print_lcd ();
		sound_test_pass();
		}
	else
		{
		write_cmd_lcd (0x97);sprintf(lcd_buffer,"**FAIL**");print_lcd ();
	   	sound_test_fail();
		}
		delay_test_7400 (5000);
}
/*----------------------------------------------------End-Main-Auto_Check---------------------------------------------------------------------*/


/*------------------------------------------AUTO-Prototype----------------------------------------------*/

void test_7400_ic1_condition_00_auto (void)					// 00
{
	IC7400_IC1_PIN1=0;IC7400_IC1_PIN2=0;	//IC1_PIN3=P0^2;  	OUTPUT
	IC7400_IC1_PIN4=0;IC7400_IC1_PIN5=0;	//IC1_PIN6=P0^5;	OUTPUT
	IC7400_IC1_PIN9=0;IC7400_IC1_PIN10=0;	//IC1_PIN8=P1^0; 	OUTPUT
	IC7400_IC1_PIN12=0;IC7400_IC1_PIN13=0;	//IC1_PIN11=P1^3;;	OUTPUT
//--------GATE1----------------------------
	if (IC7400_IC1_PIN3==1)	{IC7400_IC1_G1++;}
	else{}
				
//--------GATE2-------------------------------
	if (IC7400_IC1_PIN6==1){IC7400_IC1_G2++;}
	else{}	
				
//--------GATE3-------------------------------

	if (IC7400_IC1_PIN8==1){IC7400_IC1_G3++;}
	else{}	
			
//--------GATE4-------------------------------
	if (IC7400_IC1_PIN11==1){IC7400_IC1_G4++;}
	else{}	
	
//---------------------------------------------- 
}

void test_7400_ic1_condition_01_auto (void)	   			//01
{ 	
	IC7400_IC1_PIN1=0;IC7400_IC1_PIN2=1;	//IC1_PIN3=P0^2;  	OUTPUT
	IC7400_IC1_PIN4=0;IC7400_IC1_PIN5=1;	//IC1_PIN6=P0^5;	OUTPUT
	IC7400_IC1_PIN9=0;IC7400_IC1_PIN10=1;	//IC1_PIN8=P1^0; 	OUTPUT
	IC7400_IC1_PIN12=0;IC7400_IC1_PIN13=1;	//IC1_PIN11=P1^3;;	OUTPUT
//--------GATE1----------------------------
	if (IC7400_IC1_PIN3==1){IC7400_IC1_G1++;}
	else{}	
	
//--------GATE2-------------------------------
	if (IC7400_IC1_PIN6==1){IC7400_IC1_G2++;}
	else{}	
		
//--------GATE3-------------------------------
	if (IC7400_IC1_PIN8==1){IC7400_IC1_G3++;}
	else{}	
	
//--------GATE4-------------------------------
	if (IC7400_IC1_PIN11==1){IC7400_IC1_G4++;}
	else{}				
			
//---------------------------------------------- 
}

void test_7400_ic1_condition_10_auto (void)	  			//10
{
	IC7400_IC1_PIN1=1;IC7400_IC1_PIN2=0;	//IC1_PIN3=P0^2;  	OUTPUT
	IC7400_IC1_PIN4=1;IC7400_IC1_PIN5=0;	//IC1_PIN6=P0^5;	OUTPUT
	IC7400_IC1_PIN9=1;IC7400_IC1_PIN10=0;	//IC1_PIN8=P1^0; 	OUTPUT
	IC7400_IC1_PIN12=1;IC7400_IC1_PIN13=0;	//IC1_PIN11=P1^3;;	OUTPUT
//--------GATE1----------------------------
	if (IC7400_IC1_PIN3==1){IC7400_IC1_G1++;}
	else {}

//--------GATE2-------------------------------
	if (IC7400_IC1_PIN6==1){IC7400_IC1_G2++;}
	else{}		
	
//--------GATE3-------------------------------

	if (IC7400_IC1_PIN8==1){IC7400_IC1_G3++;}
	else{}	

//--------GATE4-------------------------------
	if (IC7400_IC1_PIN11==1){IC7400_IC1_G4++;}
	else{}	
		
//----------------------------------------------		 
}


void test_7400_ic1_condition_11_auto (void)			//11
{
	IC7400_IC1_PIN1=1;IC7400_IC1_PIN2=1;	//IC1_PIN3=P0^2;  	OUTPUT
	IC7400_IC1_PIN4=1;IC7400_IC1_PIN5=1;	//IC1_PIN6=P0^5;	OUTPUT
	IC7400_IC1_PIN9=1;IC7400_IC1_PIN10=1;	//IC1_PIN8=P1^0; 	OUTPUT
	IC7400_IC1_PIN12=1;IC7400_IC1_PIN13=1;	//IC1_PIN11=P1^3;;	OUTPUT
//--------GATE1----------------------------
	if (IC7400_IC1_PIN3==1){}
	else{IC7400_IC1_G1++;}
	
//--------GATE2-------------------------------
	if (IC7400_IC1_PIN6==1){}
	else{IC7400_IC1_G2++;}
		
//--------GATE3-------------------------------

	if (IC7400_IC1_PIN8==1){}	
	else{IC7400_IC1_G3++;}
		
//--------GATE4-------------------------------
	if (IC7400_IC1_PIN11==1){}	
	else{IC7400_IC1_G4++;}
	 
//----------------------------------------------	
}

/*------------------------------------------------------IC2--------------------------------------------*/

void test_7400_ic2_condition_00_auto (void)					// 00
{
	IC7400_IC2_PIN1=0;IC7400_IC2_PIN2=0;	//IC2_PIN3=P0^2;  	OUTPUT
	IC7400_IC2_PIN4=0;IC7400_IC2_PIN5=0;	//IC2_PIN6=P0^5;	OUTPUT
	IC7400_IC2_PIN9=0;IC7400_IC2_PIN10=0;	//IC2_PIN8=P1^0; 	OUTPUT
	IC7400_IC2_PIN12=0;IC7400_IC2_PIN13=0;	//IC2_PIN11=P1^3;;	OUTPUT
//--------GATE1----------------------------
	if (IC7400_IC2_PIN3==1)	{IC7400_IC2_G1++;}
	else{}
				
//--------GATE2-------------------------------
	if (IC7400_IC2_PIN6==1){IC7400_IC2_G2++;}
	else{}	
				
//--------GATE3-------------------------------

	if (IC7400_IC2_PIN8==1){IC7400_IC2_G3++;}
	else{}	
			
//--------GATE4-------------------------------
	if (IC7400_IC2_PIN11==1){IC7400_IC2_G4++;}
	else{}	
	
//---------------------------------------------- 
}

void test_7400_ic2_condition_01_auto (void)	   			//01
{ 	
	IC7400_IC2_PIN1=0;IC7400_IC2_PIN2=1;	//IC2_PIN3=P0^2;  	OUTPUT
	IC7400_IC2_PIN4=0;IC7400_IC2_PIN5=1;	//IC2_PIN6=P0^5;	OUTPUT
	IC7400_IC2_PIN9=0;IC7400_IC2_PIN10=1;	//IC2_PIN8=P1^0; 	OUTPUT
	IC7400_IC2_PIN12=0;IC7400_IC2_PIN13=1;	//IC2_PIN11=P1^3;;	OUTPUT
//--------GATE1----------------------------
	if (IC7400_IC2_PIN3==1){IC7400_IC2_G1++;}
	else{}	
	
//--------GATE2-------------------------------
	if (IC7400_IC2_PIN6==1){IC7400_IC2_G2++;}
	else{}	
		
//--------GATE3-------------------------------
	if (IC7400_IC2_PIN8==1){IC7400_IC2_G3++;}
	else{}	
	
//--------GATE4-------------------------------
	if (IC7400_IC2_PIN11==1){IC7400_IC2_G4++;}
	else{}				
			
//---------------------------------------------- 
}

void test_7400_ic2_condition_10_auto (void)	  			//10
{
	IC7400_IC2_PIN1=1;IC7400_IC2_PIN2=0;	//IC2_PIN3=P0^2;  	OUTPUT
	IC7400_IC2_PIN4=1;IC7400_IC2_PIN5=0;	//IC2_PIN6=P0^5;	OUTPUT
	IC7400_IC2_PIN9=1;IC7400_IC2_PIN10=0;	//IC2_PIN8=P1^0; 	OUTPUT
	IC7400_IC2_PIN12=1;IC7400_IC2_PIN13=0;	//IC2_PIN11=P1^3;;	OUTPUT
//--------GATE1----------------------------
	if (IC7400_IC2_PIN3==1){IC7400_IC2_G1++;}
	else {}

//--------GATE2-------------------------------
	if (IC7400_IC2_PIN6==1){IC7400_IC2_G2++;}
	else{}		
	
//--------GATE3-------------------------------

	if (IC7400_IC2_PIN8==1){IC7400_IC2_G3++;}
	else{}	

//--------GATE4-------------------------------
	if (IC7400_IC2_PIN11==1){IC7400_IC2_G4++;}
	else{}	
		
//----------------------------------------------		 
}


void test_7400_ic2_condition_11_auto (void)			//11
{
	IC7400_IC2_PIN1=1;IC7400_IC2_PIN2=1;	//IC2_PIN3=P0^2;  	OUTPUT
	IC7400_IC2_PIN4=1;IC7400_IC2_PIN5=1;	//IC2_PIN6=P0^5;	OUTPUT
	IC7400_IC2_PIN9=1;IC7400_IC2_PIN10=1;	//IC2_PIN8=P1^0; 	OUTPUT
	IC7400_IC2_PIN12=1;IC7400_IC2_PIN13=1;	//IC2_PIN11=P1^3;;	OUTPUT
//--------GATE1----------------------------
	if (IC7400_IC2_PIN3==1){}
	else{IC7400_IC2_G1++;}
	
//--------GATE2-------------------------------
	if (IC7400_IC2_PIN6==1){}
	else{IC7400_IC2_G2++;}
		
//--------GATE3-------------------------------

	if (IC7400_IC2_PIN8==1){}	
	else{IC7400_IC2_G3++;}
		
//--------GATE4-------------------------------
	if (IC7400_IC2_PIN11==1){}	
	else{IC7400_IC2_G4++;}
	 
//----------------------------------------------	
}

/*----------------------------------------------------End--Auto_Check---------------------------------------------------------------------*/


void test_ic7400_all (void)
{
	IC7400_IC1_G1=0;IC7400_IC1_G2=0;IC7400_IC1_G3=0;IC7400_IC1_G4=0;
 	IC7400_IC2_G1=0;IC7400_IC2_G2=0;IC7400_IC2_G3=0;IC7400_IC2_G4=0;
	IC7400_IC2_SUM=0;IC7400_IC1_SUM=0;	

 	test_ic7400_ic1 ();
	test_ic7400_ic2 ();
}

void test_ic7400_ic1 (void)
{ 	
	clear_lcd();
	lcd_line1 ();sprintf(lcd_buffer,"IC1 CONDITION   ");print_lcd ();
	lcd_line2 ();sprintf(lcd_buffer,"GATE1=  GATE2=  ");print_lcd ();
	lcd_line3 ();sprintf(lcd_buffer,"GATE3=  GATE4=  ");print_lcd ();

	delay_test_7400(50000);
	
	write_cmd_lcd (0x8E);sprintf(lcd_buffer,"00");print_lcd ();
	sound_test_step();test_7400_ic1_condition_00 ();
	
	delay_test_7400 (50000);
	
	write_cmd_lcd (0x8E);sprintf(lcd_buffer,"01");print_lcd ();
	sound_test_step();test_7400_ic1_condition_01 ();				   		   
	
	delay_test_7400 (50000);			   
	
	write_cmd_lcd (0x8E);sprintf(lcd_buffer,"10");print_lcd ();			   
	sound_test_step();test_7400_ic1_condition_10 ();			   
				  
	delay_test_7400 (50000);
				   
	write_cmd_lcd (0x8E);sprintf(lcd_buffer,"11");print_lcd ();			   
	sound_test_step();test_7400_ic1_condition_11 ();			   
				   
	delay_test_7400 (50000);			  	

	clear_lcd();
	lcd_line1 ();sprintf(lcd_buffer," TEST  COMPLETE ");print_lcd ();
	lcd_line2 ();sprintf(lcd_buffer,"      IC1       ");print_lcd ();
	IC7400_IC1_SUM = IC7400_IC1_G4 + IC7400_IC1_G3 + IC7400_IC1_G2 + IC7400_IC1_G1; 
	lcd_line4 ();sprintf(lcd_buffer,"%d %d %d %d %d",IC7400_IC1_G1,IC7400_IC1_G2,IC7400_IC1_G3,IC7400_IC1_G4,IC7400_IC1_SUM);print_lcd ();
	
	if (IC7400_IC1_SUM == 16)
		{
		lcd_line3 ();sprintf(lcd_buffer,"******PASS******");print_lcd ();
		sound_test_pass();delay_test_7400 (25000);
		}
	else
		{
		lcd_line3 ();sprintf(lcd_buffer,"******FAIL******");print_lcd ();
		sound_test_fail();delay_test_7400 (25000);
		}

}

void test_ic7400_ic2 (void)
{ 	
	clear_lcd();
	lcd_line1 ();sprintf(lcd_buffer,"IC2 CONDITION   ");print_lcd ();
	lcd_line2 ();sprintf(lcd_buffer,"GATE1=  GATE2=  ");print_lcd ();
	lcd_line3 ();sprintf(lcd_buffer,"GATE3=  GATE4=  ");print_lcd ();

	delay_test_7400(50000);
	
	write_cmd_lcd (0x8E);sprintf(lcd_buffer,"00");print_lcd ();
	sound_test_step();test_7400_ic2_condition_00 ();
	
	delay_test_7400 (50000);
	
	write_cmd_lcd (0x8E);sprintf(lcd_buffer,"01");print_lcd ();
	sound_test_step();test_7400_ic2_condition_01 ();				   		   
	
	delay_test_7400 (50000);			   
	
	write_cmd_lcd (0x8E);sprintf(lcd_buffer,"10");print_lcd ();			   
	sound_test_step();test_7400_ic2_condition_10 ();			   
				  
	delay_test_7400 (50000);
				   
	write_cmd_lcd (0x8E);sprintf(lcd_buffer,"11");print_lcd ();			   
	sound_test_step();test_7400_ic2_condition_11 ();			   
				   
	delay_test_7400 (50000);			  	
	
	IC7400_IC2_SUM = IC7400_IC2_G1 + IC7400_IC2_G2 + IC7400_IC2_G3 + IC7400_IC2_G4; 
	
	clear_lcd();
	lcd_line1 ();sprintf(lcd_buffer," TEST  COMPLETE ");print_lcd ();
	lcd_line2 ();sprintf(lcd_buffer,"      IC2       ");print_lcd ();
	lcd_line4 ();sprintf(lcd_buffer,"%d %d %d %d %d",IC7400_IC2_G1,IC7400_IC2_G2,IC7400_IC2_G3,IC7400_IC2_G4,IC7400_IC2_SUM);print_lcd ();
	
	if (IC7400_IC2_SUM	== 16)
		{
		lcd_line3 ();sprintf(lcd_buffer,"******PASS******");print_lcd ();
		sound_test_pass();delay_test_7400 (25000);
		}
	else
		{
		lcd_line3 ();sprintf(lcd_buffer,"******FAIL******");print_lcd ();
		sound_test_fail();delay_test_7400 (25000);
		}

}

void delay_TEST_7400 (unsigned long i)
{
  while(i > 0) {i--;}									// Loop Decrease Counter	
  return;
}


void test_7400_ic1_condition_00 (void)					// 00
{
	IC7400_IC1_PIN1=0;IC7400_IC1_PIN2=0;	//IC1_PIN3=P0^2;  	OUTPUT
	IC7400_IC1_PIN4=0;IC7400_IC1_PIN5=0;	//IC1_PIN6=P0^5;	OUTPUT
	IC7400_IC1_PIN9=0;IC7400_IC1_PIN10=0;	//IC1_PIN8=P1^0; 	OUTPUT
	IC7400_IC1_PIN12=0;IC7400_IC1_PIN13=0;	//IC1_PIN11=P1^3;;	OUTPUT
//--------GATE1----------------------------
	if (IC7400_IC1_PIN3==1)
		{
		write_cmd_lcd (0xC6);write_data_lcd ('T');IC7400_IC1_G1++;		
		}
	else
		{
		write_cmd_lcd (0xC6);write_data_lcd ('F');
		}
//--------GATE2-------------------------------
	if (IC7400_IC1_PIN6==1)
		{
		write_cmd_lcd (0xCE);write_data_lcd ('T');IC7400_IC1_G2++;	
		}
	else
		{
		write_cmd_lcd (0xCE);write_data_lcd ('F');
		}
//--------GATE3-------------------------------

	if (IC7400_IC1_PIN8==1)
		{
		write_cmd_lcd (0x96);write_data_lcd ('T');IC7400_IC1_G3++;
		}

	else
		{
		write_cmd_lcd (0x96);write_data_lcd ('F');
		}
//--------GATE4-------------------------------
	if (IC7400_IC1_PIN11==1)
		{
		write_cmd_lcd (0x9E);write_data_lcd ('T');IC7400_IC1_G4++;		
		}
	else
		{
		write_cmd_lcd (0x9E);write_data_lcd ('F');
		}
//---------------------------------------------- 
}

void test_7400_ic1_condition_01 (void)	   			//01
{ 	
	IC7400_IC1_PIN1=0;IC7400_IC1_PIN2=1;	//IC1_PIN3=P0^2;  	OUTPUT
	IC7400_IC1_PIN4=0;IC7400_IC1_PIN5=1;	//IC1_PIN6=P0^5;	OUTPUT
	IC7400_IC1_PIN9=0;IC7400_IC1_PIN10=1;	//IC1_PIN8=P1^0; 	OUTPUT
	IC7400_IC1_PIN12=0;IC7400_IC1_PIN13=1;	//IC1_PIN11=P1^3;;	OUTPUT
//--------GATE1----------------------------
	if (IC7400_IC1_PIN3==1)
		{
		write_cmd_lcd (0xC6);write_data_lcd ('T');IC7400_IC1_G1++;		
		}
	else
		{
		write_cmd_lcd (0xC6);write_data_lcd ('F');
		}
//--------GATE2-------------------------------
	if (IC7400_IC1_PIN6==1)
		{
		write_cmd_lcd (0xCE);write_data_lcd ('T');IC7400_IC1_G2++;	
		}
	else
		{
		write_cmd_lcd (0xCE);write_data_lcd ('F');
		}
//--------GATE3-------------------------------
	if (IC7400_IC1_PIN8==1)
		{
		write_cmd_lcd (0x96);write_data_lcd ('T');IC7400_IC1_G3++;
		}
	else
		{
		write_cmd_lcd (0x96);write_data_lcd ('F');
		}
//--------GATE4-------------------------------
	if (IC7400_IC1_PIN11==1)
		{
		write_cmd_lcd (0x9E);write_data_lcd ('T');IC7400_IC1_G4++;		
		}
	else
		{
		write_cmd_lcd (0x9E);write_data_lcd ('F');
		}
//---------------------------------------------- 
}

void test_7400_ic1_condition_10 (void)	  			//10
{
	IC7400_IC1_PIN1=1;IC7400_IC1_PIN2=0;	//IC1_PIN3=P0^2;  	OUTPUT
	IC7400_IC1_PIN4=1;IC7400_IC1_PIN5=0;	//IC1_PIN6=P0^5;	OUTPUT
	IC7400_IC1_PIN9=1;IC7400_IC1_PIN10=0;	//IC1_PIN8=P1^0; 	OUTPUT
	IC7400_IC1_PIN12=1;IC7400_IC1_PIN13=0;	//IC1_PIN11=P1^3;;	OUTPUT
//--------GATE1----------------------------
	if (IC7400_IC1_PIN3==1)
		{
		write_cmd_lcd (0xC6);write_data_lcd ('T');IC7400_IC1_G1++;		
		}
	else
		{
		write_cmd_lcd (0xC6);write_data_lcd ('F');
		}
//--------GATE2-------------------------------
	if (IC7400_IC1_PIN6==1)
		{
		write_cmd_lcd (0xCE);write_data_lcd ('T');IC7400_IC1_G2++;	
		}
	else
		{
		write_cmd_lcd (0xCE);write_data_lcd ('F');
		}
//--------GATE3-------------------------------

	if (IC7400_IC1_PIN8==1)
		{
		write_cmd_lcd (0x96);write_data_lcd ('T');IC7400_IC1_G3++;
		}

	else
		{
		write_cmd_lcd (0x96);write_data_lcd ('F');
		}
//--------GATE4-------------------------------
	if (IC7400_IC1_PIN11==1)
		{
		write_cmd_lcd (0x9E);write_data_lcd ('T');IC7400_IC1_G4++;		
		}
	else
		{
		write_cmd_lcd (0x9E);write_data_lcd ('F');
		}
//----------------------------------------------		 
}


void test_7400_ic1_condition_11 (void)			//11
{
	IC7400_IC1_PIN1=1;IC7400_IC1_PIN2=1;	//IC1_PIN3=P0^2;  	OUTPUT
	IC7400_IC1_PIN4=1;IC7400_IC1_PIN5=1;	//IC1_PIN6=P0^5;	OUTPUT
	IC7400_IC1_PIN9=1;IC7400_IC1_PIN10=1;	//IC1_PIN8=P1^0; 	OUTPUT
	IC7400_IC1_PIN12=1;IC7400_IC1_PIN13=1;	//IC1_PIN11=P1^3;;	OUTPUT
//--------GATE1----------------------------
	if (IC7400_IC1_PIN3==1)
		{
		write_cmd_lcd (0xC6);write_data_lcd ('T');		
		}
	else
		{
		write_cmd_lcd (0xC6);write_data_lcd ('F');IC7400_IC1_G1++;
		}
//--------GATE2-------------------------------
	if (IC7400_IC1_PIN6==1)
		{
		write_cmd_lcd (0xCE);write_data_lcd ('T');	
		}
	else
		{
		write_cmd_lcd (0xCE);write_data_lcd ('F');IC7400_IC1_G2++;
		}
//--------GATE3-------------------------------

	if (IC7400_IC1_PIN8==1)
		{
		write_cmd_lcd (0x96);write_data_lcd ('T');
		}

	else
		{
		write_cmd_lcd (0x96);write_data_lcd ('F');IC7400_IC1_G3++;
		}
//--------GATE4-------------------------------
	if (IC7400_IC1_PIN11==1)
		{
		write_cmd_lcd (0x9E);write_data_lcd ('T');	
		}
	else
		{
		write_cmd_lcd (0x9E);write_data_lcd ('F');IC7400_IC1_G4++;	
		} 
//----------------------------------------------	
}



/*--------------------------------------------IC2------------------------------------------------------*/

void test_7400_ic2_condition_00 (void)					// 00
{
	IC7400_IC2_PIN1=0;IC7400_IC2_PIN2=0;	//IC2_PIN3=P1^6;  	OUTPUT
	IC7400_IC2_PIN4=0;IC7400_IC2_PIN5=0;	//IC2_PIN6=P2^1;	OUTPUT
	IC7400_IC2_PIN9=0;IC7400_IC2_PIN10=0;	//IC2_PIN8=P2^2; 	OUTPUT
	IC7400_IC2_PIN12=0;IC7400_IC2_PIN13=0;	//IC2_PIN11=P2^5;	OUTPUT
	
//--------GATE1----------------------------
	if (IC7400_IC2_PIN3==1)
		{
		write_cmd_lcd (0xC6);write_data_lcd ('T');IC7400_IC2_G1++;		
		}
	else
		{
		write_cmd_lcd (0xC6);write_data_lcd ('F');
		}
//--------GATE2-------------------------------
	if (IC7400_IC2_PIN6==1)
		{
		write_cmd_lcd (0xCE);write_data_lcd ('T');IC7400_IC2_G2++;	
		}
	else
		{
		write_cmd_lcd (0xCE);write_data_lcd ('F');
		}
//--------GATE3-------------------------------

	if (IC7400_IC2_PIN8==1)
		{
		write_cmd_lcd (0x96);write_data_lcd ('T');IC7400_IC2_G3++;
		}

	else
		{
		write_cmd_lcd (0x96);write_data_lcd ('F');
		}
//--------GATE4-------------------------------
	if (IC7400_IC2_PIN11==1)
		{
		write_cmd_lcd (0x9E);write_data_lcd ('T');IC7400_IC2_G4++;		
		}
	else
		{
		write_cmd_lcd (0x9E);write_data_lcd ('F');
		}
//---------------------------------------------- 
}

void test_7400_ic2_condition_01 (void)	   			//01
{ 	
	IC7400_IC2_PIN1=0;IC7400_IC2_PIN2=1;	//IC2_PIN3=P1^6;  	OUTPUT
	IC7400_IC2_PIN4=0;IC7400_IC2_PIN5=1;	//IC2_PIN6=P2^1;	OUTPUT
	IC7400_IC2_PIN9=0;IC7400_IC2_PIN10=1;	//IC2_PIN8=P2^2; 	OUTPUT
	IC7400_IC2_PIN12=0;IC7400_IC2_PIN13=1;	//IC2_PIN11=P2^5;	OUTPUT
//--------GATE1----------------------------
	if (IC7400_IC2_PIN3==1)
		{
		write_cmd_lcd (0xC6);write_data_lcd ('T');IC7400_IC2_G1++;		
		}
	else
		{
		write_cmd_lcd (0xC6);write_data_lcd ('F');
		}
//--------GATE2-------------------------------
	if (IC7400_IC2_PIN6==1)
		{
		write_cmd_lcd (0xCE);write_data_lcd ('T');IC7400_IC2_G2++;	
		}
	else
		{
		write_cmd_lcd (0xCE);write_data_lcd ('F');
		}
//--------GATE3-------------------------------
	if (IC7400_IC2_PIN8==1)
		{
		write_cmd_lcd (0x96);write_data_lcd ('T');IC7400_IC2_G3++;
		}

	else
		{
		write_cmd_lcd (0x96);write_data_lcd ('F');
		}
//--------GATE4-------------------------------
	if (IC7400_IC2_PIN11==1)
		{
		write_cmd_lcd (0x9E);write_data_lcd ('T');IC7400_IC2_G4++;		
		}
	else
		{
		write_cmd_lcd (0x9E);write_data_lcd ('F');
		}
//---------------------------------------------- 
}

void test_7400_ic2_condition_10 (void)	  			//10
{
	IC7400_IC2_PIN1=1;IC7400_IC2_PIN2=0;	//IC2_PIN3=P1^6;  	OUTPUT
	IC7400_IC2_PIN4=1;IC7400_IC2_PIN5=0;	//IC2_PIN6=P2^1;	OUTPUT
	IC7400_IC2_PIN9=1;IC7400_IC2_PIN10=0;	//IC2_PIN8=P2^2; 	OUTPUT
	IC7400_IC2_PIN12=1;IC7400_IC2_PIN13=0;	//IC2_PIN11=P2^5;	OUTPUT
//--------GATE1----------------------------
	if (IC7400_IC2_PIN3==1)
		{
		write_cmd_lcd (0xC6);write_data_lcd ('T');IC7400_IC2_G1++;		
		}
	else
		{
		write_cmd_lcd (0xC6);write_data_lcd ('F');
		}
//--------GATE2-------------------------------
	if (IC7400_IC2_PIN6==1)
		{
		write_cmd_lcd (0xCE);write_data_lcd ('T');IC7400_IC2_G2++;	
		}
	else
		{
		write_cmd_lcd (0xCE);write_data_lcd ('F');
		}
//--------GATE3-------------------------------

	if (IC7400_IC2_PIN8==1)
		{
		write_cmd_lcd (0x96);write_data_lcd ('T');IC7400_IC2_G3++;
		}

	else
		{
		write_cmd_lcd (0x96);write_data_lcd ('F');
		}
//--------GATE4-------------------------------
	if (IC7400_IC2_PIN11==1)
		{
		write_cmd_lcd (0x9E);write_data_lcd ('T');IC7400_IC2_G4++;		
		}
	else
		{
		write_cmd_lcd (0x9E);write_data_lcd ('F');
		}
//----------------------------------------------		 
}


void test_7400_ic2_condition_11 (void)			//11
{
	IC7400_IC2_PIN1=1;IC7400_IC2_PIN2=1;	//IC2_PIN3=P1^6;  	OUTPUT
	IC7400_IC2_PIN4=1;IC7400_IC2_PIN5=1;	//IC2_PIN6=P2^1;	OUTPUT
	IC7400_IC2_PIN9=1;IC7400_IC2_PIN10=1;	//IC2_PIN8=P2^2; 	OUTPUT
	IC7400_IC2_PIN12=1;IC7400_IC2_PIN13=1;	//IC2_PIN11=P2^5;	OUTPUT
//--------GATE1----------------------------
	if (IC7400_IC2_PIN3==1)
		{
		write_cmd_lcd (0xC6);write_data_lcd ('T');	
		}
	else
		{
		write_cmd_lcd (0xC6);write_data_lcd ('F');IC7400_IC2_G1++;	
		}										  
//--------GATE2-------------------------------
	if (IC7400_IC2_PIN6==1)
		{
		write_cmd_lcd (0xCE);write_data_lcd ('T');
		}
	else
		{
		write_cmd_lcd (0xCE);write_data_lcd ('F');IC7400_IC2_G2++;	
		}
//--------GATE3-------------------------------

	if (IC7400_IC2_PIN8==1)
		{
		write_cmd_lcd (0x96);write_data_lcd ('T');
		}

	else
		{
		write_cmd_lcd (0x96);write_data_lcd ('F');IC7400_IC2_G3++;
		}
//--------GATE4-------------------------------
	if (IC7400_IC2_PIN11==1)
		{
		write_cmd_lcd (0x9E);write_data_lcd ('T');	
		}
	else
		{
		write_cmd_lcd (0x9E);write_data_lcd ('F');IC7400_IC2_G4++;	
		} 
//----------------------------------------------	

} 

	
	
