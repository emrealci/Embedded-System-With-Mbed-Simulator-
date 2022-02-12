#include "mbed.h"

DigitalOut led1(p5);
DigitalOut led2(p6);
DigitalIn button1(p7);
DigitalIn button2(p8);


int main(){
    
    int count1=0;
    int count2=0;
    led1=0;
    led2=0;
    
    while(1){
        
        if(button1==1){
            count1=count1+1;
            printf("count1 is : %d\n",count1);
        }
        
        if(button2==1){
            count2=count2+1;
            printf("count2 is : %d\n",count2);
        }
        
        
        if(count1==4){
            
            wait_ms(200),
            led1=!led1;
            count1=0;
        }
        if(count2==6){
            wait_ms(600),
            led2=!led2;
            count2=0;
        }
         wait_ms(500);
    }
    
    
    
    
}
