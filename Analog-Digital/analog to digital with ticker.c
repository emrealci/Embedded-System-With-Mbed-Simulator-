#include "mbed.h"
 
AnalogIn   ain(p15);

Ticker sampler;

float av_float; // defined analog voltage value
 
 
 void sampler_ADC(){
     
     av_float=ain;
     printf("normalized: %.6f\n", av_float);
 }
 
int main(void)
{

   sampler.attach(callback(&sampler_ADC),0.1f);
   
   wait_ms(osWaitForever);


    
}
