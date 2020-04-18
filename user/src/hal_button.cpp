#include <cstdint>
#include <iostream>
#include "hal_button.h"
using namespace std;

CHal_BUTTON *CHal_BUTTON::s_mInstande = NULL;

void CHal_BUTTON::Button_init()
{
    RCC->AHBENR  |= (1<<GPIOA_CLK_EN);
    GPIOA->MODER |= (0<<USER_BUUTON_PIN);
}

bool CHal_BUTTON::IsButtonPressed()
{
    if((GPIOA->IDR & BUTTON_PRESSED_VALUE) == 0x1)
    {
        return true;
    }

    return false;
}

bool CHal_BUTTON::IsButtonReleased()
{
    if((GPIOA->IDR & BUTTON_PRESSED_VALUE) == 0x0)
    {
        return true;
    }

    return false;
}

CHal_BUTTON *CHal_BUTTON::GetInstande()
{
    if(s_mInstande == NULL)
    {
        s_mInstande = new CHal_BUTTON();
    }
    
    return s_mInstande;
}

CHal_BUTTON::CHal_BUTTON()
{
    Button_init();
}

CHal_BUTTON::~CHal_BUTTON()
{
    delete s_mInstande;
    s_mInstande = NULL;
}

bool isButtonPressed()
{
    bool value;
    value = CHal_BUTTON::GetInstande()->IsButtonPressed();
    return value;
}

bool isButtonReleased()
{
    bool value;
    value = CHal_BUTTON::GetInstande()->IsButtonReleased();
    return value;
}
