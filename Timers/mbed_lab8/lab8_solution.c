#include "mbed.h"

DigitalOut Led1(p5);
DigitalOut Led2(p6);
DigitalOut Led3(p7);
InterruptIn button1(p8);

Ticker timer1;
Timeout timer2;
int count_timer=0;
int count_button=0;

void buttonpush(){
 
    count_button=count_button+1;
   
}
void TimeoutInterrupt(){
    
    if(count_button==2){
          Led2=0;
        
        count_button=0;
    }
  if(count_button==3){
      Led3=0;
       
      count_button=0;
  }
    }
   


void TimerInterrupt(){
    
   count_timer=count_timer+1;
   
    printf("Counting serial output is %d\n",count_timer);
   
    button1.fall(callback(&buttonpush));
   
    if(count_timer==5){
        count_timer=0;
        Led1=!Led1;
        
       
        if(count_button==2){
           
            timer2.attach(callback(&TimeoutInterrupt),0.5f);
        }
       
        if(count_button==3){
         timer2.attach(callback(&TimeoutInterrupt),0.5f);
    }
      printf("Button pressed %d times \n",count_button);
     if (count_button>3 || count_button==1){
           count_button=0;
    
   
}
     Led2=1;
     Led3=1;
}
}


int main() {
   
    Led2=1;
    Led3=1;
   
    timer1.attach(callback(&TimerInterrupt),0.3f);
   
}
