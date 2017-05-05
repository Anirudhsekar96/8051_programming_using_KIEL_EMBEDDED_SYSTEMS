#include<reg51.h>

//to use ports and delay

main()
{
	int i,j;
	while(1)
	{
		P0=0x00;
		for(i=0;i<100;i++)
		{
			for(j=0;j<1000;j++)
			{
			}
		}
		P0=0xFF;
		for(i=0;i<100;i++)
		{
			for(j=0;j<1000;j++)
			{
			}
		}
	}
}