//Bu 2 tickerla çözüm , fakat ilerki sorulardaki gibi tek tickerla yapýlabilir

#include <mbed.h>

DigitalOut Led1(p5);
InterruptIn button(p6);

Ticker timer1;
Ticker timer2;


int count_serial=0;
int count_push=0;

void countingSerial(){
    
    count_serial=count_serial+1;
    printf("Count is %d\n",count_serial);
    
    if(count_serial==4){
        
        count_serial=0;
    }

}
void buttonpush(){
    
 count_push=count_push+1;
 
    }
    
void TimerInterrupt(){
    
    button.fall(callback(&buttonpush));
    printf("Button count is %d\n",count_push);
    if(count_push>3){
        
        Led1=!Led1;
        
    }
     count_push=0;
    
}
int main(){
    
    
    timer1.attach(callback(&countingSerial),0.5f);
    timer2.attach(callback(&TimerInterrupt),2.0f);
    
    
    
}
