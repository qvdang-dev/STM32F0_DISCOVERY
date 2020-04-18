#include "iostream"
#include "stm32f0xx.h"

#define GPIOC_CLK_EN            19
#define GREENLED_PIN            18
#define BLUELED_PIN             16
#define GREENLED_OUT            8
#define BLUE_LED_OUT            9
#define GREENLED_SET_PIN        8
#define GREENLED_RESET_PIN      24
#define BLUELED_SET_PIN         9
#define BLUELED_RESET_PIN       25


//#define   button_active 0x0001

enum LED
{
  LED_BLUE = 0,
  LED_GREEN,
  numOfLed
};

#ifdef __cplusplus

class CHal_LED
{
    private:
        static CHal_LED *s_mInstande;
        
        void Led_init();
        
    public:
        static CHal_LED *GetInstande();
        CHal_LED();
        ~CHal_LED();

        void GreenLed_On();
        void GreenLed_Off();
        
        void BlueLed_On();
        void BlueLed_Off();      
};


void GreenLedOn();
void GreenLedOff();
void BlueLedOn();
void BlueLedOff();
#endif