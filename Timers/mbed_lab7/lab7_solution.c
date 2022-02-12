#include "mbed.h"

DigitalOut Led1(p5);
DigitalOut Led2(p6);
InterruptIn button1(p8);

Ticker timer1;
Timeout timer2;
Timeout timer3;

int count_timer=0;
int count_button=0;


void TimeoutInterrupt1(){
    Led2=1;
    
    
}
void TimeoutInterrupt(){
    
    Led2=0;
    
     timer3.attach(callback(&TimeoutInterrupt1),1.0f);
  
    }

void buttonpush(){
    count_button=count_button+1;
    
}


void TimerInterrupt(){
    
    count_timer=count_timer+1;
    printf("Serial count is:  %d\n",count_timer);
    
    button1.fall(callback(&buttonpush));
  
     if(count_timer==5){
        
        Led1=!Led1;
        count_timer=0;
        
        if(count_button>3){
            
            timer2.attach(callback(&TimeoutInterrupt),1.0f);
            
        
            
        }
         printf("Count pressed %d\n",count_button);
    count_button=0;
         }
   
    
}




int main() {
   Led2=1;
   
   timer1.attach(callback(&TimerInterrupt),0.3f);
   
   
}
