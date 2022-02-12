#include "mbed.h"
 
AnalogIn   ain(p15);
 
int main(void)
{

    float av_float; //  defined analog voltage value
    unsigned int av_int;

    while (true) {

        // normalized value
        av_float=ain.read(); // ý can read analog value as float  .... convert it to digital form..normalized.. between 0 - 1
        //16-bit value
        av_int=ain.read_u16(); //ý read my value in 16 bits  convert it to digital form between 0 -0x0fff

        printf("normalized: %.6f\n", av_float);
        printf("16-bit unsigned: 0x%04X \n", av_int);
        wait_ms(200);
    }
}
