#include <intrins.h>
sbit scl = P4^0;
sbit sda = P4^1;

void i2c_delay (void)	 //57.50us
{
	unsigned char i;
	for (i=0;i<20;i++)
	_nop_ ();
}

void i2c_clk (void)
{
	i2c_delay();	  //57.50us
	scl = 1;
	i2c_delay();	  //57.50us
	scl = 0;
}

void i2c_start (void)
{
	if(scl)
 	sda = 1;
	scl = 1;
	i2c_delay ();  //57.50us	
	sda = 0;
	i2c_delay ();  //57.50us
	scl = 0;
	
}

void i2c_stop (void)
{
	scl = 0;
	sda = 0;
	i2c_delay();  	//57.50us
	scl = 1;
	i2c_delay();  	//57.50us
	sda = 1;
	i2c_delay();	//57.50us
}

void i2c_wrdata (unsigned char dat)
{
	bit databit;
	unsigned char i;
	for(i=0;i<8;i++)
	{
		databit = dat & 0x80;
		sda = databit;
		i2c_clk();
		dat = dat << 1;
		_nop_();
		_nop_();
		_nop_();
		_nop_();
	}
	sda = 1;
	i2c_clk();
	i2c_delay();

}

char i2c_rddata (void)
{
	bit rdbit;
	char i ,dat;
	dat = 0x00;
	for(i=0;i<8;i++)
	{
		rdbit = sda;
		dat = dat << 1;
		dat = dat | rdbit;
		i2c_clk();
		
	}
	
	return dat;
	i2c_clk();
}

