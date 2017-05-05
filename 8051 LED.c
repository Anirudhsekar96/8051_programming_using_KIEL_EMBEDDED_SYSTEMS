#include<reg51.h>
#include<stdio.h>

//xdata char *LED;
//xdata char *SWITCH;
xdata char *SEGCONTROL;
xdata char *SEVENSEG;
unsigned char arr[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int j=0;

void delay()
{	
	int i,j;
	for(i=0;i<400;i++)
	for(j=0;j<600;j++);



}



main()
{
	//LED = 0xffc0;
	//SWITCH = 0xffc1;
	
	SEGCONTROL = 0xffc3;
	SEVENSEG = 0xffc2;
	
	
	while(1){
	
		//LED = 0xffc0;
		while(1){
		
		
			//*LED = 0xff;
			//*SWITCH = 0xff;
			//delay();
			//*LED = 0x00;
			//*SWITCH = 0x00;
			//delay();
			
			//SEGCONTROL = 0x04;
			if(j<10)
			{
				*SEGCONTROL = 0x04;
				*SEVENSEG = arr[j];
				j++;
				delay();
			}
			else if(j<20)
			{
				*SEGCONTROL = 0x08;
				*SEVENSEG = arr[j-10];
				j++;
				delay();
			
			
			
			}
			else{
			
				j=0;
			}
			
			
			
			
			
		
		}
	
	
	
	}



} 
