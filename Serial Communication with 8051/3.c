#include<stdio.h>
#include<reg51.h>
sbit PWPIN = P1^5;


char str[5] = "HELLO";
char str2[7] = "Anirudh";
int i=0;

int main(){
	
	EA=1;
	TMOD = 0x20;
	TH1 = 0xFD;
	TR1=1;
	EX1 = 1;
	SCON = 0x50;
	
	while(1){
		
		if(PWPIN==1){
						
						SBUF = str[i];
						i++;
						if(i==6){i=0;}		
		
						while(TI==0);
						TI=0;
		}
		if(PWPIN==0){
						SBUF = str2[i];
						i++;
						if(i==8){i=0;}		
		
						while(TI==0);
						TI=0;
			}


	}

}