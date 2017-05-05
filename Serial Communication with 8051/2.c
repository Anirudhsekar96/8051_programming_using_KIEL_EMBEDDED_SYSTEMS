#include<stdio.h>
#include<reg51.h>

char str[5] = "HELLO";
int i=0;
int main(){
	
	TMOD = 0x20;
	TH1 = 0xFD;
	TR1=1;
	SCON = 0x50;
	
	while(1){
		SBUF = str[i];
		i++;
	if(i==6){i=0;}		
		
		while(TI==0);
		TI=0;
	}







}