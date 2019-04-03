
#define STACK_TOP           0x20000000+192*1024

#define LOCATE_ICG          __attribute__((section(".icg_sec")))
#define LOCATE_FUNC         __attribute__((section(".func_sec")))


void nmi_handler(void);
void hardfault_handler(void);
int main(void);

unsigned int *myvector[4]                                   \
__attribute__ ((section("vectors"))) = {                    \
    (unsigned int *)STACK_TOP,          /* stack pointer */
    (unsigned int *)main,               /* code entry point */
    (unsigned int *)nmi_handler,        /* NMI handler(not really) */
    (unsigned int *)hardfault_handler
};

static const unsigned int cst_sec1 = 0x11111111;

static const unsigned int LOCATE_ICG icg_val[8] = {
    0xAAAAAAAA,
    0xBBBBBBBB,
    0xCCCCCCCC,
    0xDDDDDDDD,
    0xEEEEEEEE,
    0x77777777,
    0x99999999,
    0x66666666
};

static const unsigned int cst_sec2 = 0x22222222;

static unsigned int m_bss_array[5];
static unsigned int m_data_array[4] = {0x11, 0x22, 0x33, 0x44};
int main(void)
{
    int i = 0;

    m_bss_array[0] = 1;
    m_bss_array[1] = 2;
    m_bss_array[2] = 3;
    m_bss_array[3] = 4;
    m_bss_array[4] = 5;

    while (1)
    {
        i++;
    }
}

void nmi_handler(void)
{
    return;
}

void hardfault_handler(void)
{
    return;
}

void LOCATE_FUNC delay(void)
{
    return;
}

