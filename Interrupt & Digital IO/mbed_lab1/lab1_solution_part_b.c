//NOTT!!! red_led=!lred_led þeklinde olacak.... != deðil

#include "mbed.h"

DigitalOut blue_led(p5);
DigitalOut red_led(p6);
InterruptIn button_blue(p7);
InterruptIn button_red(p8);

int count1=0;
int count2=0;

void buffer1(){  //blue
    
    count1=count1+1;
    printf("blue %d\n",count1);
    if(count1==4){
    
        wait_ms(200);
        blue_led=!blue_led;
        count1=0;
         }   
}

void buffer2(){  //red

     count2=count2+1;
     printf("red %d\n",count2);
     if(count2==6){
          wait_ms(800);
          red_led=!red_led;
          count2=0; 
            }
    }

int main(){
    blue_led=0;
  // ilk baþta 0 olsun dedigi icin mainde tanýmladýk , yukarda tanýmlayýnca olmuyor
    red_led=0;
    button_blue.fall(callback(&buffer1));
    
    button_red.fall(callback(&buffer2));
    wait_ms(osWaitForever); //baba 1. kodda wait_ms(500) ekledik burda oswait cünkü interrupt var.
    
}

