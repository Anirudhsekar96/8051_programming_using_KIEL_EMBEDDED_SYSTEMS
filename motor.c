#include<stdio.h>
#include<reg51.h>

xdata char* SELMOT;


unsigned char array[] = {0x0A,0x06,0x05,0x09};

void delay(){
	int i,j;
	for(i = 0; i < 0xff; i++){
		for(j= 0; j< 0xff;j++);
	}
}

void main(){
	int i = 0;
	SELMOT = 0xffc8;
	while (1){
		*SELMOT = array[i];
		i++;
		delay();
		if(i == 4)
			i = 0;
	}
}  
