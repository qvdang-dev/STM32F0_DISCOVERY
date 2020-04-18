#include "stm32f0xx.h"
#include "hal_led.h"
#include "hal_button.h"

void delay()
{
    for(int i = 0; i <= 320000; i++);
}


void executing(unsigned int *counter_button)
{
      if(*counter_button == 2)
      {
          BlueLedOn();
          GreenLedOff();
      }
      else if (*counter_button == 4)
      {
          GreenLedOn();
          BlueLedOff();      
      }
      else
      {
        if(*counter_button > 5)
        {
          *counter_button = 0;
          BlueLedOff();
          GreenLedOff();
        }
      }
}

void button(unsigned int *count)
{
    if(isButtonPressed())
    {
      delay();
      (*count)++;
      executing(count);
      while(isButtonPressed());
    }
}

int main()
{
  unsigned int count = 0;
  while (1)
  {
    button(&count);
  }
    

  return 0;
}
