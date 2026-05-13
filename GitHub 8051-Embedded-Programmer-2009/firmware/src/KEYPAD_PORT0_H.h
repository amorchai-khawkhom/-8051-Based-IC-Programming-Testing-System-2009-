sbit row1 = P0^0;
sbit row2 = P0^1;
sbit row3 = P0^2;
sbit row4 = P0^3;
sbit col1 = P0^4;
sbit col2 = P0^5;
sbit col3 = P0^6;

void delay_keypad(unsigned long i);
char scankey (void);

char scankey (void)
{
 	char ret = 15 ;
col1 = 0;
	if (row1==0)
		{
		 delay_keypad (500);
		 ret = 1;
		}
	if (row2==0)
		{
		 delay_keypad (500);
		 ret = 4;
		}
	if (row3==0)
		{
		 delay_keypad (500);
		 ret = 7;
		}
	if (row4==0)
		{
		 delay_keypad (500);
		 ret = 10;
		}
col1 = 1;

col2 = 0;
	if (row1==0)
		{
		 delay_keypad (500);
		 ret = 2;
		}
	if (row2==0)
		{
		 delay_keypad (500);
		 ret = 5;
		}
	if (row3==0)
		{
		 delay_keypad (500);
		 ret = 8;
		}
	if (row4==0)
		{
		 delay_keypad (500);
		 ret = 0;
		}
col2 = 1;

col3 = 0;
	if (row1==0)
		{
		 delay_keypad (500);
		 ret = 3;
		}
	if (row2==0)
		{
		 delay_keypad (500);
		 ret = 6;
		}
	if (row3==0)
		{
		 delay_keypad (500);
		 ret = 9;
		}
	if (row4==0)
		{
		 delay_keypad (500);
		 ret = 11;
		}
col3 = 1;

	return (ret);
}

void delay_keypad(unsigned long i)
{
  while(i > 0) {i--;}									// Loop Decrease Counter	
  return;
}

