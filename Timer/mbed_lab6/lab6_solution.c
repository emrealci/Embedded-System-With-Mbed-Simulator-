#include "mbed.h"

DigitalOut Led1(p5);
DigitalOut Led2(p6);
DigitalOut Led3(p7);
InterruptIn button(p8);

Ticker timer1;

int count_Led1=0;
int count_others=0;

void buttonpush(){
    
    count_others=count_others+1;

}
void TimerInterrupt(){
    
    
    count_Led1=count_Led1+1;
    printf("Ticker count is : %d\n",count_Led1);
    
    button.fall(callback(&buttonpush));
    
    if(count_Led1==6){
        Led1=!Led1;
        count_Led1=0;
    
    
    if(count_others==2){
      
        Led2=!Led2;
        
    }
    if(count_others==3){
        
        Led3=!Led3;
    }
    
    printf("button count is %d\n ",count_others);
    count_others=0;
    
}
}



int main() {

 timer1.attach(callback(&TimerInterrupt),0.25f);
    
}

