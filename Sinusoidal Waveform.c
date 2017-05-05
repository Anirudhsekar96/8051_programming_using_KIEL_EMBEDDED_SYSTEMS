#include<stdio.h>
#include<reg51.h>

void sinefunc();
float x[16]={0,0.5,0.707,0.866,1.00,0.866,0.707,0.5,0,-0.5,-0.707,-0.866,-1,-0.866,-0.707,-0.5};
int i=0;

void main()
{

	
	for(i=0;i<16;i++){
		x[i] = (5*(x[i]+1));
		x[i] = 25.5 * x[i];
		//P1 = x[i];
		}
			
		
		
		TMOD = 0x01;
		EA = 1;
		ET0 =1;
		TR0 = 1;
		while(1)
		{}
		
		//P1 = Dac[i];
}

void sinefunc() interrupt 1
{
	if(i==16){

		i=0;
		}

		P1 = x[i];
		i++;


}