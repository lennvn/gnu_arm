

#include <stdint.h>
#include "led.h"



int main(void)
{
    led_init();

    while (1)
    {
        led_routine();
    }
}

