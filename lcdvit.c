#include<reg51.h>
#include<stdio.h>
xdata  char *SELRWD;
xdata  char *LCDSEL; 
unsigned char array[]  ={"ANIRUDH"};   
unsigned char array1[] =  {"DUMBO"};  
unsigned char i;      

void delay()
{  
int i,j;
for(i=0;i<0xf;i++)
for(j=0;j<0xff;j++);
}
void delay2()
{  
int i,j;
for(i=0;i<0xff;i++)
for(j=0;j<0xff;j++);
} 
      
void busycheck()
{
    delay();
    *SELRWD = 0x00;    
}


void main()
{  
SELRWD = 0xffc3;
LCDSEL = 0xffc4;

while(1)
      {
 
      busycheck();
        *LCDSEL = 0x38;
        busycheck();
        *LCDSEL= 0x06;
        busycheck();
        *LCDSEL = 0x01;
        busycheck();
        *LCDSEL = 0x0c;
        busycheck();
        *LCDSEL = 0x80;  
    
        for (i=0;i<10;i++)
        {
       busycheck();
       delay();
        *SELRWD = 0x01;
        *LCDSEL = array[i];
        }
        
        busycheck();
        *LCDSEL = 0xC3;  
    
        for (i=0;i<10;i++)
        {
       busycheck();
       delay();
        *SELRWD = 0x01;
        *LCDSEL = array1[i];
        }
        while(1){
        	busycheck();
        	*LCDSEL = 0x18;
        	delay2();
        }
    while(1);
 
        }   
  
} 
