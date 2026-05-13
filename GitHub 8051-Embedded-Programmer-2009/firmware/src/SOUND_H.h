
sbit sound = P3^0;

void delay_sound (unsigned long i);
void delay_sound_ms (unsigned int ms);
void sound_freq (int freq,int time);
void sound_test_pass (void);
void sound_test_fail (void);
void sound_test_step (void);

void delay_sound(unsigned long i)
{
  while(i > 0) {i--;}					// Loop Decrease Counter	
  return;
}

void delay_sound_ms (unsigned int ms)
{
	unsigned int x,a;
	for(x=0;x<ms;x++)
	{
		for(a=0;a<44;a++);
	}
}

void sound_freq (int freq,int time)
{
	int dt=0,m=0;
	dt=5000/freq;
	time = (5*time)/dt;
	for(m=0;m<time;m++)
	{
		sound=1;
		delay_sound_ms(dt);
		sound=0;
		delay_sound_ms(dt);
	}
}

void sound_test_pass (void)
{
		sound_freq(1200,100);
		delay_sound (8000);
		sound_freq(1200,100);
		delay_sound (8000);
}

void sound_test_fail (void)
{
	  	sound_freq(1400,500);
}

void sound_test_step (void)
{
		sound_freq(1800,50);
}