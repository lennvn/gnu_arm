
#ifndef __LED_H__
#define __LED_H__


#define PA                          0ul
#define PB                          1ul
#define PC                          2ul
#define PD                          3ul
#define PE                          4ul

#define PIN7                        7ul


#define GPIO_BASE_ADDR              0x40053800ul
#define GPIO_PCR_ADDR(x, y)         (0x400ul + (0x40ul * (x)) + (0x4ul * (y)))
#define GPIO_POTR_ADDR(x)           (0x0C + (0x10ul * (x)))

#define GPIO_PCR(x, y)              (*(volatile uint16_t *)(GPIO_BASE_ADDR + GPIO_PCR_ADDR((x), (y))))
#define GPIO_POTR(x)                (*(volatile uint16_t *)(GPIO_BASE_ADDR + GPIO_POTR_ADDR((x))))



extern void led_init(void);
extern void led_routine(void);


#endif // __LED_H__

/******************************************************************************
 *                                                                            *
 * EOF                                                                        *
 *                                                                            *
 *****************************************************************************/

