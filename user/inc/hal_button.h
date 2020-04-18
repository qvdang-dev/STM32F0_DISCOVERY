#include <stdbool.h>
#include "stm32f0xx.h"

#define GPIOA_CLK_EN             17
#define USER_BUUTON_PIN          0
#define BUTTON_PRESSED_VALUE     0x0001

#ifdef __cplusplus
class CHal_BUTTON
{
    private:

        static CHal_BUTTON *s_mInstande;
        void Button_init();


    public:

        CHal_BUTTON();
        ~CHal_BUTTON();
        static CHal_BUTTON *GetInstande();
        bool IsButtonPressed();
        bool IsButtonReleased();
};
#endif

bool isButtonPressed();
bool isButtonReleased();

