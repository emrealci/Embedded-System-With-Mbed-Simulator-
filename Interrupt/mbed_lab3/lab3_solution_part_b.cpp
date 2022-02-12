#include "mbed.h"

DigitalOut blue_led(p5);
DigitalOut red_led(p6);
InterruptIn button1(p7);

int count1=0;
int count2=0;

void buffer1(){
    count1=count1+1;
    count2=count2+1;
    printf("blue %d red %d \n",count1,count2);
    
    if(count1==3){
         wait_ms(300);
        blue_led=!blue_led;
        
        
        count1=0;
         }   
         
     if(count2==5){
         wait_ms(500);
          red_led=!red_led;
         
          count2=0; 
          
            }
    
            
    }

int main(){
    blue_led=1;
    red_led=1;
    
    
    while(1){
        button1.fall(callback(&buffer1));
        wait_ms(1000);
    }
}

