

#include <stdint.h>


#include "led.h"


typedef void(*pfunc_t)(void);


#define _STACK_SIZE     0x400
#define _HEAP_SIZE      0x200

static uint8_t stack[_STACK_SIZE] __attribute__ ((aligned(8), used, section(".stack")));
static uint8_t heap[_HEAP_SIZE] __attribute__ ((aligned(8), used, section(".heap")));


#define ISR_ATTR        __attribute__((section(".isr_vector")))


extern int main(void);
void Reset_Handler(void);
void nmi_handler(void);
void hardfault_handler(void);

extern uint32_t _stack_top_;

ISR_ATTR pfunc_t nvic_vector[4] =
{
    (pfunc_t)&_stack_top_,
    Reset_Handler,
    nmi_handler,
    hardfault_handler
};


extern uint32_t _bss_start_;
extern uint32_t _bss_end_;
extern uint32_t _data_vma_start_;
extern uint32_t _data_vma_end_;
extern uint32_t _data_lma_start_;
extern uint32_t _data_lma_end_;


/* debug info */
#define RET_SRAM_START          0x20000000ul
typedef volatile uint32_t*      io32;


#define SAVE_DBG(off)           *((io32)(RET_SRAM_START + (off) * 4u))

/**/

void Reset_Handler(void)
{
    uint32_t p_bss_start = (uint32_t)&_bss_start_;
    uint32_t p_bss_end   = (uint32_t)&_bss_end_;

    while (p_bss_start < p_bss_end)
    {
        *((uint32_t *)p_bss_start) = 0u;
        p_bss_start += 4u;
    }


    uint32_t p_data_vma_start = (uint32_t)&_data_vma_start_;
    uint32_t p_data_vma_end   = (uint32_t)&_data_vma_end_;
    uint32_t p_data_lma_start = (uint32_t)&_data_lma_start_;
    uint32_t p_data_lma_end   = (uint32_t)&_data_lma_end_;
    uint32_t data_vma_size    = (uint32_t)&_data_vma_end_ - (uint32_t)&_data_vma_start_;
    uint32_t data_lma_size    = (uint32_t)&_data_lma_end_ - (uint32_t)&_data_lma_start_;


    SAVE_DBG(0) = (uint32_t)&_data_vma_start_;
    SAVE_DBG(1) = (uint32_t)&_data_vma_end_;
    SAVE_DBG(2) = (uint32_t)&_data_lma_start_;
    SAVE_DBG(3) = (uint32_t)&_data_lma_end_;
    SAVE_DBG(4) = data_vma_size;
    SAVE_DBG(5) = data_lma_size;

    if (data_vma_size != data_lma_size)
    {
        while (1);
    }

    while (p_data_vma_start < p_data_vma_end)
    {
        *((uint32_t *)p_data_vma_start) = *((uint32_t *)p_data_lma_start);
        p_data_vma_start += 4u;
        p_data_lma_start += 4u;
    }

    main();
}

void nmi_handler(void)
{
    return;
}

void hardfault_handler(void)
{
    while (1);
}

