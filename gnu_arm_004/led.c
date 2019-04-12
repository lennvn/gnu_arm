
#include <stdint.h>
#include "led.h"


static void led_delay(uint32_t n);


void led_init(void)
{
    (*(volatile uint16_t *)0x40053BFC) = 0xA501;
    GPIO_PCR(PA, PIN7) = 0x0002;
    (*(volatile uint16_t *)0x40053BFC) = 0xA500;
}


void led_routine(void)
{
    GPIO_POTR(PA) |= (uint16_t)(0x1u << PIN7);
    led_delay(8000 * 100);
}


static void led_delay(uint32_t n)
{
    while (n--);
}
