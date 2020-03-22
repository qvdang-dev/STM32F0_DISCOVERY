#include "stm32f0xx.h"

enum LED
{
  LED_BLUE = 0,
  LED_GREEN,
  numOfLed
};

#if !defined(_BOOL)
typedef unsigned char bool;
static const bool false = 0;
static const bool true = 1;
#endif

#define   green_led_pin     (1<<18)
#define   blue_led_pin      (1<<16)
#define   button_active 0x0001

void gpio_init()
{
  //LEDS
  RCC->AHBENR |= (1<<19);
  GPIOC->MODER |= (green_led_pin)|(blue_led_pin);
  //PUSH BUTTON - PA0
  RCC->AHBENR |= (1<<17);
  GPIOA->MODER |= (0<<0);
}

void Led_on(unsigned char LED)
{
    switch (LED)
    {
    case LED_BLUE:
      GPIOC->BSRR |= (1<<8);
      break;
    
    case LED_GREEN:
      GPIOC->BSRR |= (1<<9);
      break;
    
    default:
      break;
    } 
}

void Led_off(unsigned char LED)
{
    switch (LED)
    {
    case LED_BLUE:
      GPIOC->BSRR |= (1<<24);
      break;
    
    case LED_GREEN:
      GPIOC->BSRR |= (1<<25);
      break;
    
    default:
      break;
    } 
}

void delay()
{
    for(int i = 0; i <= 320000; i++);
}


void executing(unsigned int *counter_button)
{
      if(*counter_button == 2)
      {
          Led_on(LED_BLUE);
          Led_off(LED_GREEN);
      }
      else if (*counter_button == 4)
      {
          Led_on(LED_GREEN);
          Led_off(LED_BLUE);      
      }
      else
      {
        if(*counter_button > 5)
        {
          *counter_button = 0;
          Led_off(LED_BLUE);
          Led_off(LED_GREEN);
        }
      }
}

void button(unsigned int *count)
{
    if(GPIOA->IDR & button_active)
    {
      delay();
      (*count)++;
      executing(count);
      while(GPIOA->IDR & button_active);

    }
}

int main()
{
  unsigned int count = 0;
  gpio_init();
  while (1)
  {
    button(&count);
  }
    

  return 0;
}
