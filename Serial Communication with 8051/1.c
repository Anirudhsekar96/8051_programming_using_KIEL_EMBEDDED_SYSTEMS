#include<stdio.h>
#include<reg51.h>


int i=0;
int main(){
	
	TMOD = 0x20;
	TH1 = 0xFA;
	TR1=1;
	SCON = 0x50;
	
	while(1){
		SBUF = 'Y';
		
	
		while(TI==0);
		TI=0;
	}







}