#include "mbed.h"

AnalogIn ain(p15);

PwmOut led(p5);
InterruptIn button1(p6);

Timeout tim1;

void ADC(){

    led=ain;
    printf("led:%.2f\n",led.read());
    wait_ms(500);
    led=0;
    
}
void TimerInterrupt(){
        tim1.attach(callback(&ADC),1.0f);
} 



int main() {
    button1.fall(callback(&TimerInterrupt));
    
    wait_ms(osWaitForever);
}
