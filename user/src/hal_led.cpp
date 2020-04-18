#include <cstdint>
#include <iostream>
#include "hal_led.h"

using namespace std;

CHal_LED *CHal_LED::s_mInstande = NULL;

void CHal_LED::Led_init()
{
  RCC->AHBENR  |= (1<<GPIOC_CLK_EN);
  GPIOC->MODER |= (1<<GREENLED_PIN);
  GPIOC->MODER |= (1<<BLUELED_PIN);
}

void CHal_LED::GreenLed_On()
{
    GPIOC->BSRR |= (1<<GREENLED_SET_PIN);
}

void CHal_LED::GreenLed_Off()
{
    GPIOC->BSRR |= (1<<GREENLED_RESET_PIN);
}

void CHal_LED::BlueLed_On()
{
    GPIOC->BSRR |= (1<<BLUELED_SET_PIN);
}

void CHal_LED::BlueLed_Off()
{
    GPIOC->BSRR |= (1<<BLUELED_RESET_PIN);
}

CHal_LED *CHal_LED::GetInstande()
{
    if(s_mInstande == NULL)
    {
        s_mInstande = new CHal_LED();
    }

    return s_mInstande;
}

CHal_LED::CHal_LED()
{
    Led_init();
}

CHal_LED::~CHal_LED()
{
    delete s_mInstande;
    s_mInstande = NULL;
}

void GreenLedOn()
{
     CHal_LED::GetInstande()->GreenLed_On();
}
void GreenLedOff()
{
    CHal_LED::GetInstande()->GreenLed_Off();
}
void BlueLedOn()
{
    CHal_LED::GetInstande()->BlueLed_On();
}
void BlueLedOff()
{
    CHal_LED::GetInstande()->BlueLed_Off();
}