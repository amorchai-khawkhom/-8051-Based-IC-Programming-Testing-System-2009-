/********************************************************
* File Name : AT89LP4052.H           
* Purpose   : SFR For MCU AT89LPx052 ON KEIL C-Compiler
* Write By  : Eakachai Makarn (ETT CO.,LTD.)
*********************************************************/

#ifndef _AT89LP4052_H_
#define _AT89LP4052_H_

#define Sfr(x, y)	sfr x = y
#define Sbit(x, y, z)   sbit x = y^z
#define Sfr16(x,y)	sfr16 x = y

/*----------------------------------------*/
/* Include file for 8051 SFR Definitions  */
/*----------------------------------------*/

/*  SFR Byte & Bit Accress */

/* TCON */
Sfr  (TCON , 0x88);
Sbit (TF1 , 0x88, 7);
Sbit (TR1 , 0x88, 6);
Sbit (TF0 , 0x88, 5);
Sbit (TR0 , 0x88, 4);
Sbit (IE1 , 0x88, 3);
Sbit (IT1 , 0x88, 2);
Sbit (IE0 , 0x88, 1);
Sbit (IT0 , 0x88, 0);

/* P1 */
Sfr (P1 , 0x90);        
Sbit (P1_7 , 0x90, 7);
Sbit (P1_6 , 0x90, 6);
Sbit (P1_5 , 0x90, 5);
Sbit (P1_4 , 0x90, 4);
Sbit (P1_3 , 0x90, 3);
Sbit (P1_2 , 0x90, 2);
Sbit (P1_1 , 0x90, 1);
Sbit (P1_0 , 0x90, 0);

Sbit (SCLK , 0x90, 7);
Sbit (MISO , 0x90, 6);
Sbit (MOSI , 0x90, 5);
Sbit (SS , 0x90, 4);
Sbit (AIN1 , 0x90, 1);
Sbit (AIN0 , 0x90, 0);

/* SCON */
Sfr  (SCON , 0x98);      
Sbit (SM0  , 0x98, 7);
Sbit (FE   , 0x98, 7);
Sbit (SM1  , 0x98, 6);
Sbit (SM2  , 0x98, 5);
Sbit (REN  , 0x98, 4);
Sbit (TB8  , 0x98, 3);
Sbit (RB8  , 0x98, 2);
Sbit (TI   , 0x98, 1);
Sbit (RI   , 0x98, 0);

/* IE */
Sfr  (IE , 0xA8);
Sbit (EA   , 0xA8, 7);
Sbit (EC   , 0xA8, 6);
Sbit (ES   , 0xA8, 4);
Sbit (ET1  , 0xA8, 3);
Sbit (EX1  , 0xA8, 2);
Sbit (ET0  , 0xA8, 1);
Sbit (EX0  , 0xA8, 0);
       
/* P3 */
Sfr (P3 , 0xB0);        
Sbit (P3_7 , 0xB0, 7);
Sbit (P3_6 , 0xB0, 6);
Sbit (P3_5 , 0xB0, 5);
Sbit (P3_4 , 0xB0, 4);
Sbit (P3_3 , 0xB0, 3);
Sbit (P3_2 , 0xB0, 2);
Sbit (P3_1 , 0xB0, 1);
Sbit (P3_0 , 0xB0, 0);

Sbit (SYSCLK , 0xB0, 7);
Sbit (T1 , 0xB0, 5);
Sbit (T0 , 0xB0, 4);
Sbit (INT1 , 0xB0, 3);
Sbit (INT0 , 0xB0, 2);
Sbit (TXD , 0xB0, 1);
Sbit (RXD , 0xB0, 0);

/* IP */
Sfr  (IP , 0xB8);
Sbit (PC ,0xB8 , 6);
Sbit (PS ,0xB8 , 4);
Sbit (PT1 ,0xB8 , 3);
Sbit (PX1 ,0xB8 , 2);
Sbit (PT0 ,0xB8 , 1);
Sbit (PX0 ,0xB8 , 0);

/* PSW */
Sfr (PSW , 0xD0);       
Sbit (CY  , 0xD0  , 7);
Sbit (AC  , 0xD0  , 6);
Sbit (F0  , 0xD0  , 5);
Sbit (RS1 , 0xD0  , 4);
Sbit (RS0 , 0xD0  , 3);
Sbit (OV  , 0xD0  , 2);
Sbit (P   , 0xD0  , 0);

/* SFR Byte Accress Only */
Sfr (ACC , 0xE0);       
Sfr (B , 0xF0); 

Sfr (SP , 0x81);        
Sfr (DPL , 0x82);       
Sfr (DPH , 0x83);       
Sfr (SPDR , 0x86);
Sfr (PCON , 0x87);      
        
Sfr (TMOD , 0x89);       
Sfr (TL0 , 0x8A);       
Sfr (TL1 , 0x8B);       
Sfr (TH0 , 0x8C);       
Sfr (TH1 , 0x8D);       
 
Sfr (TCONB , 0x91);
Sfr (RL0 , 0x92);
Sfr (RL1 , 0x93);
Sfr (RH0 , 0x94);
Sfr (RH1 , 0x95);
Sfr (ACSR , 0x97);

Sfr (SBUF , 0x99);      
Sfr (WDTRST , 0xA6);
Sfr (WDTCON , 0xA7);

Sfr (SADDR , 0xA9);     
Sfr (SPSR , 0xAA);

Sfr (IPH , 0xB7);
Sfr (SADEN , 0xB9);

Sfr (P1M0 , 0xC2);
Sfr (P1M1 , 0xC3);
Sfr (P3M0 , 0xC6);
Sfr (P3M1 , 0xC7);
Sfr (SPCR , 0xD5);

#endif

















