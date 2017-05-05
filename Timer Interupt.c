#include<reg51.h>

//C Code to use a timer

static unsigned long int coun; //to keep a count of the number of times the timer overflows

void timer0_isr (void) interrupt 1
{
	coun++;
}

void main()
{
	TMOD = 0x01; //to select 16bit timer 0
	ET0 = 1; //enable timer 0
	EA = 1; //enable all interrupts
	while(1)
	{
		TR0 = 1; //start timer 0
	}
}
