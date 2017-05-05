#include<stdio.h>
#include<reg51.h>								// Specific to Embedded systems for 8051 microcontroller

sbit PWPIN = P1^3;  // To assign a variable location to a specific pin in a  port ( We can also use P1.3 in this case )
bit Flag =0;				// To check the flag during the interupt

void main()
{
	EA=1;
	EX1 = 1;					// To enable External Interupts
	IT1 = 1;					// A pin of Timer Module which can provide External Interupts (Interupt Timer 1)
	
		while(1){}
		
}
void External_func() interrupt 2
{

	
	{	
		TMOD = 0x10;			// Setting up the timer ( For Timer 1 is 10 else for timer 0 is 01)
		EA = 1;						// Setting all the Interupts as valid (Enable all Interupts)
		TH1 = 0xff;				// Setting the maximum value as FF
		TL1 = 0x00;				// setting the maximum value 
		ET1 =1;						// Settting up the timer	
		TR1 = 1;					// Starting the Timer
		
		
	}


}
void func() interrupt 3
{																//Interrupt 3 is for Timer 1 and Interrupt 1 is for Timer 0
	
	if(Flag){
		Flag =0;										// Clearing the Flag 
		PWPIN =1;										// Setting the Port 1.3 as High for 75% effective cycle (Since the name is for a bit we can asign the value as 1 or 0 only )
		TH1 = 0xff;									// Setting high value as 255
		TL1 = 0x40;									// Setting Low Value as 40 so taht the counter will count till 191
	}
	else{
		Flag=1;											// Setting the Flag for next cylce
		PWPIN = 0;									// Setting the Port1.3's value as low 
		TH1 = 0xff;									// Setting the Hgih value as 255
		TL1 = 0xbf;									// Setting the Low value as 191 so it counts for 40H values
	}	
	
	TF1 =0;												//For clearing the Interupt Flag
	TR1=1;												// For restarting the counter
}
//TF1=0; //For clearing the Interupt Flag