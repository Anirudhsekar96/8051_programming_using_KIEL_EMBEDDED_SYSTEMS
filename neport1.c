#include<reg51.h>

//unequal delay 70% on in port 1

main()
{
	int i,j;
	while(1)
	{
		P1=0x00;
		for(i=0;i<300;i++)
		{
		}
		P1=0xFF;
		for(i=0;i<700;i++)
		{
		}
	}
}