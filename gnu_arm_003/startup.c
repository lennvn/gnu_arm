

#include <stdint.h>

#define ISR_ATTR        __attribute__((section(".isr_vector")))

extern int main(void);
void low_level_init(void);
void nmi_handler(void);
void hardfault_handler(void);

extern uint32_t _stack_top_;

ISR_ATTR uint32_t *nvic_vector[4] =
{
    (uint32_t *)&_stack_top_,
    (uint32_t *)low_level_init,
    (uint32_t *)nmi_handler,
    (uint32_t *)hardfault_handler
};


extern uint32_t _bss_start_;
extern uint32_t _bss_end_;
extern uint32_t _data_vma_start_;
extern uint32_t _data_vma_end_;
extern uint32_t _data_lma_start_;
extern uint32_t _data_lma_end_;

void low_level_init(void)
{
    uint32_t *p_bss_start = &_bss_start_;
    uint32_t *p_bss_end   = &_bss_end_;

    while (p_bss_start < p_bss_end)
    {
        *p_bss_start = 0;
        p_bss_start++;
    }

    uint32_t *p_data_vma_start = &_data_vma_start_;
    uint32_t *p_data_vma_end   = &_data_vma_end_;
    uint32_t *p_data_lma_start = &_data_lma_start_;
    uint32_t *p_data_lma_end   = &_data_lma_end_;

    uint32_t data_vma_size = p_data_vma_end - p_data_vma_start;
    uint32_t data_lma_size = p_data_vma_end - p_data_lma_start;

    if (data_vma_size != data_lma_size)
    {
        while (1);
    }

    while (p_data_vma_start < p_data_vma_end)
    {
        *p_data_vma_start = *p_data_lma_start;
        p_data_vma_start++;
        p_data_lma_start++;
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

