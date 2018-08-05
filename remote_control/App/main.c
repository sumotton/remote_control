#include "stm32f10x.h"
#include <stdio.h>


void Delay(uint32_t u32Period)
{
  volatile uint64_t u64count = 1000*u32Period; 
  while(u64count--);
}

void Led_Init(void)
{
    GPIO_InitTypeDef LedPin;
  
    LedPin.GPIO_Pin = GPIO_Pin_4;
    LedPin.GPIO_Speed = GPIO_Speed_50MHz;
    LedPin.GPIO_Mode = GPIO_Mode_Out_PP;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

   GPIO_Init(GPIOA,&LedPin);
   /*turn off led by default*/
   GPIO_ResetBits(GPIOA,GPIO_Pin_4);
}


int main(void)
{
    Led_Init();

    while (1)
    {
        GPIO_SetBits(GPIOA,GPIO_Pin_4);
        Delay(1000);
        GPIO_ResetBits(GPIOA,GPIO_Pin_4);
        Delay(1000);
    }
}
