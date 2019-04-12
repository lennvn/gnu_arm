
/******************************************************************************
 * HC32F460: ROM 512KB(0x00000000 ~ 0x00007FFF)
 *           SRAM 188KB(0x1FFF8000 ~ 0x20026FFF)
 *           RET_SRAM 4KB(0x200F0000 ~ 0x200F0FFF)
 */

#define LOCATE_ICG      __attribute__((section(".icg_sec")))

LOCATE_ICG const unsigned int icg_val[8] =
{
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
};

int main(void)
{
    int i = 0;

    while (1)
    {
        i++;
    }
}
